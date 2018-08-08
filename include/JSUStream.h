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
	void insert(JSUPtrLink *, JSUPtrLink *);
	void remove(JSUPtrLink *);
	
	u32 _0;
	u32 _4;
	s32 numPtrs; // _8
};

template<typename T>
class JSUList : public JSUPtrList
{
	public:
	~JSUList();
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

    VTABLE; // _0
};

/* INPUT */

class JSUInputStream : public JSUIosBase
{
	public:
	JSUInputStream();
	~JSUInputStream();
	
	u32* skip(u32);
	void read(void *, u32 size);
	char* readString();
	char* readString(u8 *, s16);
	
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
	u32* align(u32);
	void skip(u32);
	u32* peek(void *, u32);
	void seek(u32, JSUStreamSeekFrom);
};

class JSUMemoryInputStream : public JSURandomInputStream
{
    public:
    ~JSUMemoryInputStream();
	
	u32 getAvailable() const;
	void skip(u32);
	u32 getPosition() const;
	u32 getLength() const;
	void setBuffer(void const *, u32 size);
	u32* readData(void *, u32 size);
	u32* seekPos(u32, JSUStreamSeekFrom);
	
	void* _8;
	u32 length; // _C
	u32 position; // _10
};

/* OUTPUT */
class JSUOutputStream : public JSUIosBase
{
	public:
	~JSUOutputStream();
	
	void skip(u32, u8);
	void write(void const *, u32);
	
	u8 _4;
	u8 _5; // padding?
	u8 _6; // ^^
	u8 _7; // ^^
};

class JSURandomOutputStream : public JSUOutputStream
{
	public:
	~JSURandomOutputStream();
	
	void seek(u32, JSUStreamSeekFrom);
	u32 getAvailable() const;
};

class JSUMemoryOutputStream : public JSURandomOutputStream
{
	public:
	~JSUMemoryOutputStream();
	
	u32 getPosition() const;
	u32 getLength() const;
	void setBuffer(void *, u32);
	u32* writeData(void const *, u32);
	u32* seekPos(u32, JSUStreamSeekFrom);
	
	u32 _8;
	u32 length; // _C
	u32 position; // _10
};

#endif // JSUSTREAM_H