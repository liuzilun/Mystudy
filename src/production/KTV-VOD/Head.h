#ifndef STRUHEAD__
#define STRUHEAD__
#include "windows.h"
#define MYRUN        true   //如果是本人运行，则改成TRUE 否则是出品的，则改成FALSE
#define YS           false
#define PROGRUNPATH  "d:\\VOD\\"
#define GXPATH       "d:\\VOD\\gx.dbf"
#define GQPATH       "d:\\VOD\\gq.dbf"
#define XFKPATH      "d:\\VOD\\x\\xfk.dbf"
#define DANPATH      "d:\\VOD\\X\\dan\\"
#define VIPTABPATH   "d:\\VOD\\X\\mylove\\viptab.dbf"
#define SHOPLBPATH   "x:\\shoplb.dbf"
#define SHOPPATH     "x:\\shop.dbf"
#define KEYTABPATH   "d:\\VOD\\keytab.dbf"
#define MAPTABPATH   "d:\\VOD\\map.dbf"
#define SERMAPPATH   "d:\\vod\\sermap.dbf"    //服务器的MAP文件
#define PARATABPATH  "d:\\VOD\\paratab.dbf"
#define COPYPATH     "x:\\COPYDATA\\"
#define POPERPATH    "d:\\VOD\\poper.dbf"
#define MOUSETABPATH "d:\\VOD\\mousetab.dbf"
#define FWHJPATH     "x:\\fwhj.dbf"
#define INTERPATH    "d:\\vod\\internet.dbf"
struct EventStru
   {
     HANDLE KeyHandle;
     int    KeyValue;
     int    KeyValue1;   //双键值时使用
     int    KeyValueCount; //表示键值的多少个
     int    KeyType;
   };
struct ShowPictureStru
   {
     int x;
     int y;
     int type;
     char fname[1024];
   };
struct DrawTextStru
   {
     int x;
     int y;
     int Color;
     char Text[1024];
     char FontName[1024];  //字体名字
     int  fonttype;        //0表示十六位   1 表示24位    2表示32点阵  3.表示自选
     int  FontSize;        //自选时的字体大小
     int  Len;
   };
#define KeyTabHead   129   //KeyTab.dbf文件的头文件大小
struct KeyTabStru
   {
     char delflag;
     char KeyChar[10];  //对应的字符
     char KeyDown[10];  //对应的字符的数值
     char common[20];   //注释
   };
#define SongTabHead   417
struct SongTab
   {
     char delflag;
     char GM[40];
     char BH[10];
     char ZHPY[4];
     char GX[10];
     char LB[10];
     char YZ[10];
     char YSSD[2];
     char BCSD[2];
     char ZS[4];
     char DCCS[10];
     char YLDX[2];
     char VIP[1];
   };
struct SelSongTab      //待选歌曲队列和播放歌曲队列
 {
   struct SongTab A;
   int    Stat;        //状态,对于待选歌曲,1表示选中,对于己选歌曲,1表示正在播放,2表示播放完毕
   unsigned long PlayOff;  //播放的偏移量
   int    RecNo;       //记录号
 };
#define SingerHeadSize 193
struct SingerTab
 {
   char delflag;
   char xm[24];
   char xb[1];
   char sp[1];
   char qp[12];
   char dccs[8];
 };

struct ph     //处理流行金曲的结构
 {
   unsigned int rno;   //歌曲的记录号
   unsigned int cs;    //点唱次数
 };
struct Xf
 {
   char shopname[100];   //商品名称
   char shopdw[8];       //商品单位
   char shopdj[10];      //商品单价
   char shopsl[10];      //商品数量
   char shopzj[10];      //商品总价
   char shopzt[4];       //商品状态
   char shoprq[10];      //商品点取日期
   char shopsj[10];      //商品点取时间
   char shopczy[10];     //商品点取的操作员编号
 };
struct WaveHead   //WAVE声音文件的头部分
  {
   char  RIFF[4];
   DWORD BLOCKSIZE;
   char  WAVE[4];
   char  fmt[4];
   DWORD SIZE16;
   WORD  FormatFlag;
   WORD  Chanel;
   DWORD SamplesPerSec;
   DWORD AvgBytesPerSec;
   WORD  BlockAlign;
   WORD  BitsPerSample;
   char  datastr[4];
   DWORD DataSize;
  };
#define MapDriveHead 161
struct MapDrive
   {
    char DelFlag;
    char RemoteIP[48];
    char RemotePath[100];
    char MapDrive[2];
    char MapOk;
   };
#if YS
#define MYLOVEMAX  2
#else
#define MYLOVEMAX  200
#endif
struct MyLoveFile
   {
    char Password[100];                //口令
    int  Rcount;                       //记录总数
    struct SongTab A[MYLOVEMAX];       //最多两百首歌曲
    int  RecNo[MYLOVEMAX];             //记录号
    unsigned long PlayOff[MYLOVEMAX];  //播放偏移
   };
#define VIPTABHeadSize 353
 struct VIPTAB
  {
    char delfag;
    char bh[10];
    char mm[10];
    char sm[40];
    char bl1[10];
    char bl2[20];
    char bl3[30];
    char bl4[2];
    char bl5[1];
    char bl6[3];
    char bl7[5];
  };
#define SHOPLBHEADSIZE 129
struct shoplb
  {
   char delfalg;
   char bh[10];
   char sm[20];
   char pict[100];
  };
#define ShopHeadSize 289
   struct Shop   //商品库
   {
     char DelFlag;
     char ShopName[40];  //商品名称
     char ShopBh[5];     //商品编号
     char ShopDj[8];     //商品单价
     char ShopDz[3];     //商品打折率
     char ShopSm[40];    //商品说明
     char ShopKc[10];    //商品库存数量
     char ShopLb[10];    //商品类别
     char ShopDw[4];     //商品单位
   };
#define DanHeadSize 449
   struct Dan            //用户点单的数据库
   {
     char DelFlag;       //删除标志
     char RoomName[10];  //房间名称
     char ShopName[20];  //商品名称
     char ShopDj[8];     //商品单价
     char ShopDz[3];     //商品打折
     char ShopDw[4];     //商品单位
     char ShopSl[5];     //商品数量
     char ShopZj[10];    //商品总价
     char Gh[10];        //工号
     char bl1[3];
     char bl2[6];
     char bl3[9];
     char bl4[10];
     char bl5[10];
   };
#define XfkHeadSize 449
   struct Xfk
   {
     char DelFlag;
     char JiuName[20];  //酒水名称
     char Sl[3];        //数据
     char Dw[4];        //酒水单位
     char Dj[7];        //酒水单价
     char Zj[7];        //总消费值
     char Zt[4];        //酒水状态
     char Fm[10];       //房间名称
     char Sj[20];       //消费时间
     char Czy[20];      //操作员（也就是送商品员）
     char Sfjz;         //是否结帐
     char Zdh[10];      //帐单号
     char dzl[3];       //打折率
     char fwfzk[3];     //服务费折扣
   };
//下面是所有的网络操作请求包
struct QQDG              //请求点歌的歌曲包
   {
      char SongName[100];   //请求要点的歌曲的编号
      unsigned long BH;     //请求的包的编号
      int  KD;              //包的状态（由服务器回应）NOPACK/OKPACK/WAITPACK
      char Song[100];       //远程歌曲的全名（服务器回应），当KD=OKPACK时可以使用
   };
struct SearchPath         //搜索路径结构
   {
    char Path[40];          //搜索路径名
    int MaxClick;           //此路径最大的点播数
   };
struct LoginPack
   {
    char RemoteName[20];   //远程用户名称如"\\888lfw\"
    int  DriveCount;       //拥有搜索路径的个数
    struct SearchPath Sp[24]; //最多24个搜索路径
   };
#define ParaTabHeadSize 97
struct ParaTab
   {
    char delflag;
    char sm[20];
    char v1[100];
   };
#define MouseTabHeadSize 353
struct MouseTab
   {
    char delflag;
    char X[3];        //图片X坐标
    char Y[3];        //图片Y坐标
    char X1[3];       //图片右边坐标
    char Y1[3];       //图片左下角坐标
    char PICT[200];   //对应的是穿透图片,如果不需要穿透图片判断，则此处为空
    char KEYDOWN1[4]; //对应的键值1
    char KEYDOWN2[4]; //对应的键值2
    char KEYCOUNT;    //对应的键值总数
    char OPERCODE[3]; //属于第几类操作代码
    char SM[20];
   };
#define POPERTabeHeadSize 193
struct POPERTab
   {
    char delfalg;
    char pictname[200];
    char opercode[3];
    char bl1[5];
    char bl2[10];
    char bl3[5];
   };
#define JIUYHHeadSize  257
  struct JiuYhStru
   {
    char delflag;
    char gh[10];
    char mm[10];
    char bl1[10];
    char bl2[10];
    char bl3[10];
    char bl4[10];
    char bl5[10];
   };
#define AUTOPLAY 3   //自动播放
#define QUITPLAY 4   //停止播放，并清空数据
#define CLOSEPROG 5  //关闭程序
#define PLAYONEFILE 6  //播放指定文件
#define SYSTEMRESET 7  //重新初始化系统参数
#define FORWARD     8  //快进
#define BACKWARD    9  //快退
#define MUSICECHANGE 10 //声道切换
#define TVAVCHANGE   11 //TVAV切换
#define ENDPLAY      12 //终止播放文件
#define REPLAYSONG   13 //重放歌曲
#define PAUSESONG    14 //暂停播放
#define VOLUMEUP     15 //音大
#define VOLUMEDOWN   16 //音小
#define GETMSG       17 //获取远程信息
#define RESET        18 //远程计算机重新启动
#define CLOSECOMPUTER 19 //远程计算机关机

#define FWHJHEADSIZE  513
struct fwhj
{
 char delflag;
 char room[10];
 char hjcs[3];
 char s1[10];
 char s2[10];
 char s3[10];
 char s4[10];
 char s5[10];
 char s6[10];
 char s7[10];
 char s8[10];
 char s9[10];
 char s10[10];
 char s11[10];
 char s12[10];
 char s13[10];
};
#define INTERNETHEAD 193
struct InterNet
 {
  char delflag;
  char sm[40];
  char wz[200];
  char bl1[10];
  char bl2[20];
  char bl3[50];
 };
#endif

