#ifndef J2D_H
#define J2D_H

#include "JSUStream.h"
#include "JUT.h"
#include "types.h"

using namespace JUtility;

typedef f32 Mtx[3][4];
typedef u32* ResFONT; // just to be more percise

class J2DGrafContext
{
	public:
	J2DGrafContext(u32, u32, u32, u32);
	J2DGrafContext(JUTRect const &);
	~J2DGrafContext();

	void place(JUTRect const &);
	void place(u32, u32, u32, u32);
	void setPort();
	void setup2D();
	void setScissor();
	void setLookat();

	void scissor(JUTRect const &);
	void fillBox(JUTRect const &);
	
	u32* vtable; // _0
	u32 _4; // padding?
	JUTRect _8;
	JUTRect _18;
	TColor _28;
	TColor _2C;
	TColor _30;
	TColor _34;
	u8 lineWidth; // _38
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
	~J2DPane();
	
	void draw(u32, u32, J2DGrafContext const *, bool);
	void drawSelf(u32, u32, f32 *[3][4]);
	void clip(JUTRect const &);
	u32* search(u32);
	void makeMatrix(u32, u32);
	void setCullBack(u32); // GXCullback
	void setBasePosition(u32); // J2DBasePosition
	bool setConnectParent(bool);
	void drawSelf(u32, u32);
	void resize(u32, u32);
	void move(u32, u32);
	void add(u32, u32);
	
	u32* vtable; // _0
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
	Center = 0,
	Bottom = 1,
	Top = 2
};

class J2DScreen : public J2DPane
{
	public:
	~J2DScreen();

	void makeHiearachyPanes(J2DPane *, JSURandomInputStream *, bool, bool, bool, long *);
	void drawSelf(u32, u32, f32 *[3][4]);
	u32* search(u32);
	u32 makeUserPane(s16, J2DPane *,JSURandomInputStream *);
	u32 makeUserPane(u32, J2DPane *,JSURandomInputStream *);

	void stop();
	void draw(u32, u32, J2DGrafContext const *);
};

class J2DTextBox : public J2DPane
{
	public:
	J2DTextBox(ResFONT const *, char const *);
	J2DTextBox(J2DPane *, JSURandomInputStream *, bool);
	J2DTextBox(u32, JUTRect const &, ResFONT const *, char const *, J2DTextBoxHBinding, J2DTextBoxVBinding);
	~J2DTextBox();
	
	void resize(u32, u32);
	void setConnectParent(bool);
	void drawSelf(u32, u32);
	void drawSelf(u32, u32, f32 *[3][4]);

	void initiate(ResFONT const *, char const *, J2DTextBoxHBinding, J2DTextBoxVBinding);
	
	u32 getStringPtr() const;
	u8* setString(char const *, ...);
	void setFont(JUTFont *);
	void draw(u32, u32);
	
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

class J2DPicture
{
	public:
	J2DPicture(J2DPane *, JSURandomInputStream *, bool);
	~J2DPicture();
};

/* ----- Some functions for J2D not assigned to a class */
void J2DFillBox(u32, u32, u32, u32, TColor);
void J2DFillBox(JUTRect, TColor);

#endif // J2D_H