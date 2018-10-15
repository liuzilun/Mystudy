#include "port.h"
#include "Define.h"

CPort::CPort(CMYSQLDBPool	*db_pool,
			 const char		*db_name)
	: _db_pool(db_pool)
{
	strncpy(_db_name, db_name, MAX_PATH);
	startup(0);
}

CPort::~CPort(void)
{
	cleanup();
}

bool CPort::startup(unsigned long port_id)
{
	bool ret = true;

	cleanup();

	Process::CAutoLock lock(&_cs_info);

	SMYSQLDBLink *db = _db_pool->enter();
	char sql[MAX_SQL_LEN] = {0};
	if (0 == port_id)
	{
		sprintf(sql, SQL_GET_PORT, _db_name);
	}
	else
	{
		sprintf(sql, SQL_GET_THE_PORT, _db_name, port_id);
	}
	CMYSQLRS rs;
	if (db->_db->Exec(sql, &rs))
	{
		while (rs.LoadRow())
		{
			SSPInfo x;
			unsigned long port_id	= rs.AsU32(0);
			
			strncpy(x._port_num, rs.AsStr(1), 10);
			strncpy(x._misc_num, rs.AsStr(2), 10);
			
			x._smg_type		= (unsigned char)rs.AsU32(3);
			x._slip_win		= (unsigned char)rs.AsU32(4);
			x._resp_time	= (unsigned char)rs.AsU32(5);
			x._resp_try		= (unsigned char)rs.AsU32(6);
			x._rpt_try		= (unsigned char)rs.AsU32(7);
			x._has_expire	= (unsigned char)rs.AsU32(8);
			x._delay_time	= rs.AsU32(9);
			x._links		= (unsigned char)rs.AsU32(10);
			x._mt_int		= (unsigned short)rs.AsU32(11);

			strncpy(x._local_ip, rs.AsStr(12), MAX_IP_LEN);
			x._local_port	= (unsigned short)rs.AsU32(13);
			strncpy(x._smg_ip, rs.AsStr(14), MAX_IP_LEN);
			x._smg_mo_port	= (unsigned short)rs.AsU32(15);
			x._smg_mt_port	= (unsigned short)rs.AsU32(16);

			strncpy(x._login_name, rs.AsStr(17), MAX_UID_LEN);
			strncpy(x._login_pswd, rs.AsStr(18), MAX_PSWD_LEN);

			strncpy(x._corp_id, rs.AsStr(19), MAX_CORP_ID_LEN);
			x._src_id		= rs.AsU32(20);
			x._min_seq_id	= rs.AsU32(21);
			x._max_seq_id	= rs.AsU32(22);
			x._seq_id		= rs.AsU32(23);
			x._is_iden		= (unsigned char)rs.AsU32(24);

			_sp_info[port_id] = x;
		}
		rs.FreeRsl();
	}
	else
	{
		ret = false;
	}
	_db_pool->leave(*db);

	return ret;
}

void CPort::cleanup(void)
{
	_cs_info.Lock();
	_sp_info.clear();
	_cs_info.Unlock();
}

SSPInfo* CPort::find(unsigned long port_id)
{
	Process::CAutoLock lock(&_cs_info);
	MAP_SPInfo::iterator it = _sp_info.find(port_id);
	if (it != _sp_info.end())
	{
		return &it->second;
	}
	else
	{
		return NULL;
	}
}

bool CPort::save_seq_id(unsigned long port_id, 
						unsigned long seq_id)
{
	_cs_info.Lock();
	MAP_SPInfo::iterator it = _sp_info.find(port_id);
	if (it != _sp_info.end())
	{
		it->second._seq_id = seq_id;
	}
	_cs_info.Unlock();

	SMYSQLDBLink *db = _db_pool->enter();
	char sql[MAX_SQL_LEN] = {0};
	sprintf(sql, SQL_UPDATE_SEQ_ID, _db_name, seq_id, port_id);
	bool ret = db->_db->Exec(sql) == TRUE;
	_db_pool->leave(*db);

	return ret;
}

unsigned long CPort::size(void)
{
	Process::CAutoLock lock(&_cs_info);
	return (unsigned long)_sp_info.size();
}