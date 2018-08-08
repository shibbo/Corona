#ifndef J2D_H
#define J2D_H

#include "JKR.h"
#include "JSUStream.h"
#include "JUT.h"
#include "types.h"

typedef u32* ResFONT; // just to be more percise

class J2DGrafContext
{
	public:
	J2DGrafContext(int, int, int, int);
	J2DGrafContext(JUTRect const &);
	~J2DGrafContext();

	void place(JUTRect const &);
	void place(int, int, int, int);
	void setPort();
	void setup2D();
	void setScissor();
	void setLookat();

	void scissor(JUTRect const &);
	void fillBox(JUTRect const &);
	
	VTABLE; // _0
	u32 _4; // padding?
	JUTRect _8;
	JUTRect _18;
	JUtility::TColor _28;
	JUtility::TColor _2C;
	JUtility::TColor _30;
	JUtility::TColor _34;
	u8 mLineWidth; // _38
	u8 _39; // padding?
	u8 _3A; // ^^
	u8 _3B; // ^^
	u32 _3C;
	u32 _40;
	u8 _44[0xB4-0x44]; // who knows what's here
	u32 _B4;
	u32 _B8;
	u32 _BC;
	u32 _C0;
	u32 _C4;
	u32 _C8;
	u32 _CC;
	u32 _D0;
	u32 _D4;
};

class J2DOrthoGraph : public J2DGrafContext
{
	public:
	J2DOrthoGraph(u32, u32, u32, u32);
	J2DOrthoGraph(JUTRect const &);
	~J2DOrthoGraph();

	void setPort();
	void setLookat();
	void scissorBounds(JUTRect *, JUTRect *);

	JUTRect _D8;
	u32 _DC;
	u32 _E0;
	u32 _E4;
	f32 _E8;
	f32 _EC;
};

class J2DPane
{
	public:
	J2DPane();
	J2DPane(J2DPane *, s16, bool, u32, JUTRect const &);
	J2DPane(s16, u32, JUTRect const &);
	J2DPane(J2DPane *, JSURandomInputStream *, bool);
	virtual ~J2DPane();
	
	virtual void drawSelf(int, int, f32 *[3][4]);
	virtual bool setConnectParent(bool);
	virtual void drawSelf(u32, u32);
	virtual void resize(int, int);
	virtual void move(int, int);
	virtual void add(int, int);
	virtual u32* search(u32);
	virtual void makeMatrix(int, int);

	void draw(int, int, J2DGrafContext const *, bool);
	void clip(JUTRect const &);
	void setCullBack(u32); // GXCullback
	void setBasePosition(u32); // J2DBasePosition
	
	VTABLE; // _0
	u16 _4;
	u16 _6; // padding?
	u32 id; // _8
	u8 isVisible; // _C
	u8 _D; // padding?
	u8 _E; // ^^
	u8 _F; // ^^
	u32 _10;
	JUTRect rect; // _14
	JUTRect cRect; // _24
	JUTRect clipRect; // _34
	JUTRect scissorBound; // _44
	Mtx _54;
	u8 _84[0xB4-0x84];
	u32 _B4;
	u32 _B8;
	u8 _BC;
	f32 rotation; // _C0
	u32 basePosition; // _C4 (J2DBasePosition)
	u32 cullingMode; // _C8
	u8 _CC;
	u8 _CD;
	u8 _CE;
	u8 _CF; // connectParent
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
	VBindingCenter = 0,
	VBindingBottom = 1,
	VBindingTop = 2
};

enum J2DBinding
{
	BindingBottom = (1 << 0),
	BindingTop = (1 << 1),
	BindingRight = (1 << 2),
	BindingLeft = (1 << 3),
};

enum J2DWrapMode 
{
		None,
		Clamp,
		Repeat,
		Mirror,
};

class J2DScreen : public J2DPane
{
	public:
	virtual ~J2DScreen();

	virtual void drawSelf(u32, u32, f32 *[3][4]);
	virtual u32* search(u32);

	void makeHiearachyPanes(J2DPane *, JSURandomInputStream *, bool, bool, bool, u32 *);
	u32 makeUserPane(s16, J2DPane *,JSURandomInputStream *);
	u32 makeUserPane(u32, J2DPane *,JSURandomInputStream *);

	void stop();
	void draw(u32, u32, J2DGrafContext const *);

	u8 _EC;
	u8 _ED; // padding?
	u8 _EE; // ^^
	u8 _EF; // ^^
	u32 _D0;
	u8 _D4[0xF0-0xD4];
	u32 _F0;
};

class J2DSetScreen : public J2DScreen
{
	public:
	J2DSetScreen(char const *, JKRArchive *);

	void makeHiearachyPanes(J2DPane *, JSURandomInputStream *, bool, bool, bool, u32 *);
};

class J2DTextBox : public J2DPane
{
	public:
	J2DTextBox(ResFONT const *, char const *);
	J2DTextBox(J2DPane *, JSURandomInputStream *, bool);
	J2DTextBox(u32, JUTRect const &, ResFONT const *, char const *, J2DTextBoxHBinding, J2DTextBoxVBinding);
	virtual ~J2DTextBox();
	
	virtual void resize(int, int);
	virtual bool setConnectParent(bool);
	virtual void drawSelf(int, int);
	virtual void drawSelf(int, int, f32 *[3][4]);

	void initiate(ResFONT const *, char const *, J2DTextBoxHBinding, J2DTextBoxVBinding);
	
	u32 getStringPtr() const;
	u8* setString(char const *, ...);
	void setFont(JUTFont *);
	void draw(int, int);
	
	JUTFont* font; // _EC
	u32 _F0;
	u32 _F4;
	J2DTextBoxHBinding hBinding; // _F8
	J2DTextBoxVBinding vBinding; // _FC
	u32* strPtr;
	u32 _104;
	u32 _108;
	u32 _10C;
	u32 _110;
	u32 _114;
	u32 _118;
	u32 _11C;
	u32 _120;
};

class J2DPicture : public J2DPane
{
	public:
	J2DPicture(J2DPane *, JSURandomInputStream *, bool);
	virtual ~J2DPicture();

	virtual void drawSelf(int, int);
	virtual void drawSelf(int, int, f32 *[3][4]);

	void drawFullSet(int, int, int, int, J2DBinding, u32, bool, J2DWrapMode, J2DWrapMode, float *[3][4]);
	void draw(int, int, int, int, bool, bool, bool);
	void drawTexCoord(int, int, int, int, f32, f32, f32, f32, f32, f32, f32, f32, f32 *[3][4]);
	void setTevMode();
	void swap(f32 &, f32 &);
	void setBlendKonstColor();
	void setBlendKonstAlpha();
	
	u32* _EC;
	u8 _F0[0xFC-0xF0];
	u8 _FC; // padding?
	u8 _FD; // ^^
	u8 _FE; // ^^
	u8 _FF; // ^^
	u8 _100[0x128-0x100];
	u32 _128;
	u32 _12C;
	u8 _130;
	u8 _131; // padding?
	u8 _132; // ^^
	u8 _133; // ^^
	u32 _134;
	u32 _138;
};

class J2DPrint
{
	public:
	J2DPrint(JUTFont *, int, int, JUtility::TColor, JUtility::TColor);
	J2DPrint(JUTFont *, int);
	virtual ~J2DPrint();

	void initiate();
	void private_initiate(JUTFont *, int, int, JUtility::TColor, JUtility::TColor);
	static void setBuffer(u32);
	void locate(int, int);
	void setFontSize();
	void print(int, int, char const *, ...);
	void print(int, int, u8, char const *, ...);
	void getWidth(char const *, ...);
	void printReturn(char const *, int, int, J2DTextBoxHBinding, J2DTextBoxVBinding, int, int, u8);

	VTABLE; // _0
	JUTFont* font; // _4
	u32 _8;
	u32 _C;
	// there's more
};

/* ----- Some functions for J2D not assigned to a class */
void J2DFillBox(u32, u32, u32, u32, JUtility::TColor);
void J2DFillBox(JUTRect, JUtility::TColor);

#endif // J2D_H