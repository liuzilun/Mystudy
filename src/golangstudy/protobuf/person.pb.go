// Code generated by protoc-gen-go. DO NOT EDIT.
// source: person.proto

package address

import (
	fmt "fmt"
	proto "github.com/golang/protobuf/proto"
	math "math"
)

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

// This is a compile-time assertion to ensure that this generated file
// is compatible with the proto package it is being compiled against.
// A compilation error at this line likely means your copy of the
// proto package needs to be updated.
const _ = proto.ProtoPackageIsVersion2 // please upgrade the proto package

type PhoneType int32

const (
	PhoneType_HOME PhoneType = 0
	PhoneType_WORK PhoneType = 1
)

var PhoneType_name = map[int32]string{
	0: "HOME",
	1: "WORK",
}

var PhoneType_value = map[string]int32{
	"HOME": 0,
	"WORK": 1,
}

func (x PhoneType) String() string {
	return proto.EnumName(PhoneType_name, int32(x))
}

func (PhoneType) EnumDescriptor() ([]byte, []int) {
	return fileDescriptor_4c9e10cf24b1156d, []int{0}
}

type Phone struct {
	Type                 PhoneType `protobuf:"varint,1,opt,name=type,proto3,enum=address.PhoneType" json:"type,omitempty"`
	Number               string    `protobuf:"bytes,2,opt,name=number,proto3" json:"number,omitempty"`
	XXX_NoUnkeyedLiteral struct{}  `json:"-"`
	XXX_unrecognized     []byte    `json:"-"`
	XXX_sizecache        int32     `json:"-"`
}

func (m *Phone) Reset()         { *m = Phone{} }
func (m *Phone) String() string { return proto.CompactTextString(m) }
func (*Phone) ProtoMessage()    {}
func (*Phone) Descriptor() ([]byte, []int) {
	return fileDescriptor_4c9e10cf24b1156d, []int{0}
}
func (m *Phone) XXX_Unmarshal(b []byte) error {
	return xxx_messageInfo_Phone.Unmarshal(m, b)
}
func (m *Phone) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	return xxx_messageInfo_Phone.Marshal(b, m, deterministic)
}
func (m *Phone) XXX_Merge(src proto.Message) {
	xxx_messageInfo_Phone.Merge(m, src)
}
func (m *Phone) XXX_Size() int {
	return xxx_messageInfo_Phone.Size(m)
}
func (m *Phone) XXX_DiscardUnknown() {
	xxx_messageInfo_Phone.DiscardUnknown(m)
}

var xxx_messageInfo_Phone proto.InternalMessageInfo

func (m *Phone) GetType() PhoneType {
	if m != nil {
		return m.Type
	}
	return PhoneType_HOME
}

func (m *Phone) GetNumber() string {
	if m != nil {
		return m.Number
	}
	return ""
}

type Person struct {
	Id                   int32    `protobuf:"varint,1,opt,name=id,proto3" json:"id,omitempty"`
	Name                 string   `protobuf:"bytes,2,opt,name=name,proto3" json:"name,omitempty"`
	Phones               []*Phone `protobuf:"bytes,3,rep,name=phones,proto3" json:"phones,omitempty"`
	XXX_NoUnkeyedLiteral struct{} `json:"-"`
	XXX_unrecognized     []byte   `json:"-"`
	XXX_sizecache        int32    `json:"-"`
}

func (m *Person) Reset()         { *m = Person{} }
func (m *Person) String() string { return proto.CompactTextString(m) }
func (*Person) ProtoMessage()    {}
func (*Person) Descriptor() ([]byte, []int) {
	return fileDescriptor_4c9e10cf24b1156d, []int{1}
}
func (m *Person) XXX_Unmarshal(b []byte) error {
	return xxx_messageInfo_Person.Unmarshal(m, b)
}
func (m *Person) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	return xxx_messageInfo_Person.Marshal(b, m, deterministic)
}
func (m *Person) XXX_Merge(src proto.Message) {
	xxx_messageInfo_Person.Merge(m, src)
}
func (m *Person) XXX_Size() int {
	return xxx_messageInfo_Person.Size(m)
}
func (m *Person) XXX_DiscardUnknown() {
	xxx_messageInfo_Person.DiscardUnknown(m)
}

var xxx_messageInfo_Person proto.InternalMessageInfo

func (m *Person) GetId() int32 {
	if m != nil {
		return m.Id
	}
	return 0
}

func (m *Person) GetName() string {
	if m != nil {
		return m.Name
	}
	return ""
}

func (m *Person) GetPhones() []*Phone {
	if m != nil {
		return m.Phones
	}
	return nil
}

type ContactBook struct {
	Persons              []*Person `protobuf:"bytes,1,rep,name=persons,proto3" json:"persons,omitempty"`
	XXX_NoUnkeyedLiteral struct{}  `json:"-"`
	XXX_unrecognized     []byte    `json:"-"`
	XXX_sizecache        int32     `json:"-"`
}

func (m *ContactBook) Reset()         { *m = ContactBook{} }
func (m *ContactBook) String() string { return proto.CompactTextString(m) }
func (*ContactBook) ProtoMessage()    {}
func (*ContactBook) Descriptor() ([]byte, []int) {
	return fileDescriptor_4c9e10cf24b1156d, []int{2}
}
func (m *ContactBook) XXX_Unmarshal(b []byte) error {
	return xxx_messageInfo_ContactBook.Unmarshal(m, b)
}
func (m *ContactBook) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	return xxx_messageInfo_ContactBook.Marshal(b, m, deterministic)
}
func (m *ContactBook) XXX_Merge(src proto.Message) {
	xxx_messageInfo_ContactBook.Merge(m, src)
}
func (m *ContactBook) XXX_Size() int {
	return xxx_messageInfo_ContactBook.Size(m)
}
func (m *ContactBook) XXX_DiscardUnknown() {
	xxx_messageInfo_ContactBook.DiscardUnknown(m)
}

var xxx_messageInfo_ContactBook proto.InternalMessageInfo

func (m *ContactBook) GetPersons() []*Person {
	if m != nil {
		return m.Persons
	}
	return nil
}

func init() {
	proto.RegisterType((*Phone)(nil), "address.Phone")
	proto.RegisterType((*Person)(nil), "address.Person")
	proto.RegisterType((*ContactBook)(nil), "address.ContactBook")
	proto.RegisterEnum("address.PhoneType", PhoneType_name, PhoneType_value)
}

func init() { proto.RegisterFile("person.proto", fileDescriptor_4c9e10cf24b1156d) }

var fileDescriptor_4c9e10cf24b1156d = []byte{
	// 220 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0xe2, 0xe2, 0x29, 0x48, 0x2d, 0x2a,
	0xce, 0xcf, 0xd3, 0x2b, 0x28, 0xca, 0x2f, 0xc9, 0x17, 0x62, 0x4f, 0x4c, 0x49, 0x29, 0x4a, 0x2d,
	0x2e, 0x56, 0x72, 0xe7, 0x62, 0x0d, 0xc8, 0xc8, 0xcf, 0x4b, 0x15, 0x52, 0xe3, 0x62, 0x29, 0xa9,
	0x2c, 0x48, 0x95, 0x60, 0x54, 0x60, 0xd4, 0xe0, 0x33, 0x12, 0xd2, 0x83, 0x2a, 0xd0, 0x03, 0xcb,
	0x86, 0x54, 0x16, 0xa4, 0x06, 0x81, 0xe5, 0x85, 0xc4, 0xb8, 0xd8, 0xf2, 0x4a, 0x73, 0x93, 0x52,
	0x8b, 0x24, 0x98, 0x14, 0x18, 0x35, 0x38, 0x83, 0xa0, 0x3c, 0xa5, 0x10, 0x2e, 0xb6, 0x00, 0xb0,
	0x0d, 0x42, 0x7c, 0x5c, 0x4c, 0x99, 0x29, 0x60, 0x73, 0x58, 0x83, 0x98, 0x32, 0x53, 0x84, 0x84,
	0xb8, 0x58, 0xf2, 0x12, 0x73, 0x53, 0xa1, 0xea, 0xc1, 0x6c, 0x21, 0x35, 0x2e, 0xb6, 0x02, 0x90,
	0xc1, 0xc5, 0x12, 0xcc, 0x0a, 0xcc, 0x1a, 0xdc, 0x46, 0x7c, 0xa8, 0xf6, 0x05, 0x41, 0x65, 0x95,
	0x2c, 0xb8, 0xb8, 0x9d, 0xf3, 0xf3, 0x4a, 0x12, 0x93, 0x4b, 0x9c, 0xf2, 0xf3, 0xb3, 0x85, 0x34,
	0xb9, 0xd8, 0x21, 0xde, 0x28, 0x96, 0x60, 0x04, 0xeb, 0xe3, 0x47, 0xe8, 0x03, 0x8b, 0x07, 0xc1,
	0xe4, 0xb5, 0xe4, 0xb9, 0x38, 0xe1, 0x4e, 0x17, 0xe2, 0xe0, 0x62, 0xf1, 0xf0, 0xf7, 0x75, 0x15,
	0x60, 0x00, 0xb1, 0xc2, 0xfd, 0x83, 0xbc, 0x05, 0x18, 0x93, 0xd8, 0xc0, 0x21, 0x61, 0x0c, 0x08,
	0x00, 0x00, 0xff, 0xff, 0xc7, 0xa8, 0x7f, 0x9e, 0x19, 0x01, 0x00, 0x00,
}
