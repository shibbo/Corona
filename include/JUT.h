#ifndef JUT_H
#define JUT_H

#include "JKR.h"
#include "OS.h"
#include "pad.h"
#include "types.h"

namespace JUtility
{
	class TColor
	{
		public:
		TColor();
		void set(u8 r, u8 g, u8 b, u8 a);
		
		u8 R; // _0
		u8 G; // _1
		u8 B; // _2
		u8 A; // _3
	};
};

using namespace JUtility;

class JUTPoint
{
	public:
	JUTPoint();
	
	u32 X; // _0
	u32 Y; // _4
};

class JUTRect
{
	public:
	JUTRect();
	JUTRect(u32, u32, u32, u32);
	
	void set(u32, u32, u32, u32);
	void copy(JUTRect const &);
	void add(u32, u32);
	u32 intersect(JUTRect const &);
	void move(u32, u32);
	void resize(u32, u32);
	void reform(u32, u32, u32, u32);
	void normalize();
	bool isEmpty() const;
	
	u32 X; // _0
	u32 Y; // _4
	u32 Height; // _8
	u32 Width; // _C
};

/* Size -- 0x1C */
class JUTFont
{
	public:
	JUTFont();
	~JUTFont();
	
	void initiate(); // nullsub
	void setu8Color(TColor);
	void setGradColor(TColor, TColor);
	void drawString_size_scale(f32, f32, f32, f32, char const *, u32, bool);
	void setGX(TColor, TColor);
	
	u32* vtable; // _0
	u8 _4;
	u8 _5; // padding?
	u8 _6; // ^^
	u8 _7; // ^^
	u32 _8;
	TColor color1; // _C
	TColor color2; // _10
	TColor color3; // _14
	TColor color4; // _18
};

/* Size -- 0x6C */
class JUTResFont : public JUTFont
{
	public:
	JUTResFont(u32 const *, JKRArchive *); // ResFont
	~JUTResFont();
	
	void initiate(u32 const *, JKRArchive *); // ResFont
	void setGX();
	void setGX(TColor, TColor);
	
	u32 _1C;
	u32 _20;
	u8 _24[0x44-0x24]; // GXTexObj
	u32 _44;
	u32 _48;
	u32 _4C; // padding?
	u32 _50;
	u32 _54;
	u32 _58;
	u16 _5C;
	u16 _5E;
	u16 _60;
	u16 _62;
	u16 _64;
	u16 _66;
	u32 _68;
};

enum EPadPort
{
	Port1 = 0,
	Port2 = 1,
	Port3 = 2,
	Port4 = 3,
};

enum EStickMode
{
	NonClamped = 0,
	Clamped = 1,
};

enum WhichStick
{
	ControlStick = 0,
	CStick = 1,
};

class JUTGamePad : public JKRDisposer
{
	public:
	JUTGamePad(EPadPort port);
	~JUTGamePad();

	void assign();
	void update();

	class CButton
	{
		public:
		CButton();

		void clear();
		void update(PADStatus const *, u32);
		void setRepeat(u32, u32, u32);

		u32 _0;
		u32 _4;
		u32 _8;
		u8 analogA; // _C
		u8 analogB; // _D
		u8 triggerLeft; // _E
		u8 triggerRight; // _F
		f32 _10;
		f32 _14;
		u32 _18;
		u32 _1C;
		u32 _20;
		u32 _24;
		u32 _28;
		u32 _2C;
	};

	class CStick
	{
		public:
		CStick();

		void clear();
		u32 update(s8, s8, EStickMode, WhichStick);
		u32 getButton();

		f32 stickX;
		f32 stickY;
		f32 length;
		u16 angle;
		u16 _E; // i assume unused
	};

	class CRumble
	{
		public:
		void clear(JUTGamePad *);
		void stopMotor(u32);
		void stopMotorHard(u32);
		void update(u16);
		void setEnable(u32);

		u32 _0;
		u32 _4;
		u32 _8;
		u32 _C;
	};

	CButton buttons; // _18
	CStick controlStick; // _48
	CStick cStick; // _58
	CRumble rumble; // _68
	u16 port; // _78
	u16 _7A; // padding?
	JSUPtrLink ptrLink; // _7C
	u32 _8C;
	u32 _90;
	u32 _94;
	u32 _98;
	u8 resetFlag; // _9C
	u8 _9D; // ^^
	u8 _9E; // ^^
	u8 _9F; // ^^
	OSTime resetTime; // _A0
};

#endif // JUT_H