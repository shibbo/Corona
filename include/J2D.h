#ifndef J2D_H
#define J2D_H

#include "JSUStream.h"
#include "JUT.h"

class J2DPane
{
	public:
	J2DPane();
	J2DPane(J2DPane *, unsigned short, bool, unsigned long, JUTRect const &);
	J2DPane(unsigned short, unsigned long, JUTRect const &);
	J2DPane(J2DPane *, JSURandomInputStream *, bool);
	~J2DPane();
	
	void draw(int, int, J2DGrafContext const *, bool);
	void drawSelf(int, int, float *[3][4]);
	void clip(JUTRect const &);
	int* search(unsigned long);
	void makeMatrix(int, int);
	void setCullBack(int); // GXCullback
	void setBasePosition(int); // J2DBasePosition
	bool setConnectParent(bool);
	void drawSelf(int, int);
	void resize(int, int);
	void move(int, int);
	void add(int, int);
	
	int* vtable; // _0
	short _4;
	short _6; // padding?
	int id; // _8
	char isVisible; // _C
	char _D; // padding?
	char _E; // ^^
	char _F; // ^^
	int _10;
	JUTRect rect; // _14
	JUTRect cRect; // _24
	JUTRect clipRect; // _34
	JUTRect scissorBound; // _44
	Mtx _54;
	char _84[0xB4-0x84];
	int _B4;
	int _B8;
	char _BC;
	float rotation; // _C0
	int basePosition; // _C4 (J2DBasePosition)
	int cullingMode; // _C8
	char _CC;
	char _CD;
	char _CE;
	char _CF; // connectParent
	JSUPtrList _D0;
	JSUPtrLink _DC;
};

enum J2DTextBoxHBinding
{
	Center = 0,
	Right = 1,
	Left = 2
};

enum J2DTextBoxVBinding
{
	Center = 0,
	Bottom = 1,
	Top = 2
};

class J2DTextBox : public J2DPane
{
	public:
	J2DTextBox(ResFONT const *, char const *);
	J2DTextBox(J2DPane*, JSURandomInputStream*, bool);
	J2DTextBox(unsigned long, JUTRect const &, ResFONT const*, char const*, J2DTextBoxHBinding, J2DTextBoxVBinding);
	~J2DTextBox();
	
	void resize(int, int);
	void setConnectParent(bool);
	void drawSelf(int, int);
	void drawSelf(int, int, float *[3][4]);
	
	void initiate(ResFONT const *, char const *, J2DTextBoxHBinding, J2DTextBoxVBinding);
	
	int getStringPtr() const;
	char* setString(char const *, ...);
	void setFont(JUTFont*);
	void draw(int, int);
	
	JUTFont* font; // _EC
	int _F0;
	int _F4;
	J2DTextBoxHBinding hBinding; // _F8
	J2DTextBoxVBinding vBinding; // _FC
	int* strPtr;
	int _104;
	int _108;
	int _10C;
	int _110;
	int _114;
	int _118;
	int _11C;
	int _120;
};

class J2DPicture
{
	public:
	J2DPicture(J2DPane*, JSURandomInputStream*, bool);
	~J2DPicture();
	
	
};

#endif // J2D_H