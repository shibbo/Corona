#ifndef JSUSTREAM_H
#define JSUSTREAM_H

#include "types.h"

class JSUPtrList; // forward declaration

class JSUPtrLink
{
	public:
	JSUPtrLink(void *);
	~JSUPtrLink();
	
	void* _0;
	JSUPtrList* ptrList; // _4
	u32 _8;
	u32 _C;
};

class JSUPtrList
{
	public:
	JSUPtrList();
	JSUPtrList(bool);
	~JSUPtrList();
	
	void initiate();
	void append(JSUPtrLink *);
	void prepend(JSUPtrLink *);
	void insert(JSUPtrLink*, JSUPtrLink *);
	void remove(JSUPtrLink *);
	
	u32 _0;
	u32 _4;
	u32 _8;
};

enum JSUStreamSeekFrom
{
	Unknown1,
	Unknown2,
	Unknown3,
	Unknown4
};

class JSUIosBase
{
    public:
    JSUIosBase();
    ~JSUIosBase();

    u32* vtable; // _0
};

/* INPUT */

class JSUInputStream : public JSUIosBase
{
	public:
	JSUInputStream();
	~JSUInputStream();
	
	u32* skip(long);
	void read(void *, long size);
	u8* readString();
    u8* readString(u8 *,  u16);
	
	u8 _4;
	u8 _5; // padding?
	u8 _6; // ^^
	u8 _7; // ^^
};

class JSURandomInputStream : public JSUInputStream
{
	public:
	~JSURandomInputStream();
	
	u32 getAvailable() const;
	u32* align(long);
	void skip(long);
	u32* peek(void *, long);
	void seek(long, JSUStreamSeekFrom);
};

class JSUMemoryInputStream : public JSURandomInputStream
{
    public:
    ~JSUMemoryInputStream();
	
	u32 getAvailable() const;
	void skip(long);
	u32 getPosition() const;
	u32 getLength() const;
	void setBuffer(void const *, long size);
	u32* readData(void *, long size);
	u32* seekPos(long, JSUStreamSeekFrom);
	
	u32 _8;
	u32 length; // _C
	u32 position; // _10
};

/* OUTPUT */
class JSUOutputStream : public JSUIosBase
{
	public:
	~JSUOutputStream();
	
	void skip(long, u8);
	void write(void const *, long);
	
	u8 _4;
	u8 _5; // padding?
	u8 _6; // ^^
	u8 _7; // ^^
};

class JSURandomOutputStream : public JSUOutputStream
{
	public:
	~JSURandomOutputStream();
	
	void seek(long, JSUStreamSeekFrom);
	u32 getAvailable() const;
};

class JSUMemoryOutputStream : public JSURandomOutputStream
{
	public:
	~JSUMemoryOutputStream();
	
	u32 getPosition() const;
	u32 getLength() const;
	void setBuffer(void *, long);
	u32* writeData(void const *, long);
	u32* seekPos(long, JSUStreamSeekFrom);
	
	u32 _8;
	u32 length; // _C
	u32 position; // _10
};
#endif // JSUSTREAM_H