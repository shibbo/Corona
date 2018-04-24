#ifndef JSUSTREAM_H
#define JSUSTREAM_H

class JSUPtrList; // forward declaration

class JSUPtrLink
{
	public:
	JSUPtrLink(void *);
	~JSUPtrLink();
	
	void* _0;
	JSUPtrList* ptrList; // _4
	int _8;
	int _C;
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
	
	int _0;
	int _4;
	int _8;
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

    int* vtable; // _0
};

/* INPUT */

class JSUInputStream : public JSUIosBase
{
	public:
	JSUInputStream();
	~JSUInputStream();
	
	int* skip(long);
	void read(void *, long size);
	char* readString();
    char* readString(char *, unsigned short);
	
	char _4;
	char _5; // padding?
	char _6; // ^^
	char _7; // ^^
};

class JSURandomInputStream : public JSUInputStream
{
	public:
	~JSURandomInputStream();
	
	int getAvailable() const;
	int* align(long);
	void skip(long);
	int* peek(void *, long);
	void seek(long, JSUStreamSeekFrom);
};

class JSUMemoryInputStream : public JSURandomInputStream
{
    public:
    ~JSUMemoryInputStream();
	
	int getAvailable() const;
	void skip(long);
	int getPosition() const;
	int getLength() const;
	void setBuffer(void const *, long size);
	int* readData(void *, long size);
	int* seekPos(long, JSUStreamSeekFrom);
	
	int _8;
	int length; // _C
	int position; // _10
};

/* OUTPUT */
class JSUOutputStream : public JSUIosBase
{
	public:
	~JSUOutputStream();
	
	void skip(long, signed char);
	void write(void const *, long);
	
	char _4;
	char _5; // padding?
	char _6; // ^^
	char _7; // ^^
};

class JSURandomOutputStream : public JSUOutputStream
{
	public:
	~JSURandomOutputStream();
	
	void seek(long, JSUStreamSeekFrom);
	int getAvailable() const;
};

class JSUMemoryOutputStream : public JSURandomOutputStream
{
	public:
	~JSUMemoryOutputStream();
	
	int getPosition() const;
	int getLength() const;
	void setBuffer(void *, long);
	int* writeData(void const *, long);
	int* seekPos(long, JSUStreamSeekFrom);
	
	int _8;
	int length; // _C
	int position; // _10
};
#endif // JSUSTREAM_H