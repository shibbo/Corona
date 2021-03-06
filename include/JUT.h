#ifndef JUT_H
#define JUT_H

#include "JKR.h"
#include "types.h"
#include "dolphin/OS.h"
#include "dolphin/PAD.h"

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
	JUTRect(s32, s32, s32, s32);
	
	void set(s32, s32, s32, s32);
	void copy(JUTRect const &);
	void add(s32, s32);
	u32 s32ersect(JUTRect const &);
	void move(s32, s32);
	void resize(s32, s32);
	void reform(s32, s32, s32, s32);
	void normalize();
	bool isEmpty() const;
	
	s32 X; // _0
	s32 Y; // _4
	s32 mHeight; // _8
	s32 mWidth; // _C
};

/* Size -- 0x1C */
class JUTFont
{
	public:
	JUTFont();
	~JUTFont();
	
	void initiate(); // nullsub
	void setCharColor(JUtility::TColor);
	void setGradColor(JUtility::TColor, JUtility::TColor);
	void drawString_size_scale(f32, f32, f32, f32, char const *, u32, bool);
	void setGX(JUtility::TColor, JUtility::TColor);
	
	VTABLE; // _0
	u8 _4;
	u8 _5; // padding?
	u8 _6; // ^^
	u8 _7; // ^^
	u32 _8;
	JUtility::TColor mColor1; // _C
	JUtility::TColor mColor2; // _10
	JUtility::TColor mColor3; // _14
	JUtility::TColor mColor4; // _18
};

/* Size -- 0x6C */
class JUTResFont : public JUTFont
{
	public:
	JUTResFont(u32 const *, JKRArchive *); // ResFont
	~JUTResFont();
	
	void initiate(u32 const *, JKRArchive *); // ResFont
	void setGX();
	void setGX(JUtility::TColor, JUtility::TColor);
	
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
	virtual ~JUTGamePad();

	void assign();
	void update();

	class CButton
	{
		public:
		CButton();

		void clear();
		void update(PADStatus const *, u32);
		void setRepeat(u32, u32, u32);

		u32 mPressedFlag; // _0
		u32 _4;
		u32 _8;
		u8 mAnalogA; // _C
		u8 mAnalogB; // _D
		u8 mTriggerLeft; // _E
		u8 mTriggerRight; // _F
		f32 mAnalogL; // _10
		f32 mAnalogR; // _14
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

		f32 mStickX;
		f32 mStickY;
		f32 mLengthFromNeutral;
		u16 mAngle;
		u16 _E; // i assume unused
	};

	class CRumble
	{
		public:
		void clear(JUTGamePad *);
		static void stopMotor(s32);
		static void stopMotorHard(s32);
		void update(u16);
		void setEnable(u32);

		u32 _0;
		u32 _4;
		u32 _8;
		u32 _C;
	};

	class C3ButtonReset
	{	
		public:
		static s32 sResetPattern;
	};

	CButton mButtons; // _18
	CStick mControlStick; // _48
	CStick mCStick; // _58
	CRumble mCumble; // _68
	u16 mPort; // _78
	u16 _7A; // padding?
	JSUPtrLink mPtrLink; // _7C
	u32 _8C;
	u32 _90;
	u32 _94;
	u32 _98;
	u8 mResetFlag; // _9C
	u8 _9D; // padding?
	u8 _9E; // ^^
	u8 _9F; // ^^
	OSTime mResetTime; // _A0
};

class JUTNameTab
{
	public:
	JUTNameTab(u32 const *); // ResNTab*

	s32 getIndex(char const *name) const;
	u16 calcKeyCode(char const *name) const;
	char* getName(unsigned short const);

	u32* mResTab; // ResNTab*
	u32 _4;
	u16 _8;
};

class JUTDirectPrint
{
	public:
	JUTDirectPrint();

	void start();
	void erase(int, int, int, int);
	void drawChar(int, int, int);
	void changeFrameBuffer(void *buffer, u16, u16);
	void drawString(u16, u16, char *);
	void drawString_f(u16, u16, char const *, ...);

	void* mBuffer; // _0
	u16 _4;
	u16 _6;
	u16 _8;
	u16 _A; // padding?
	u32 _C;
	u32 _10;
	void* _14;
};

class JUTException : public JKRThread
{
	public:
	JUTException(JUTDirectPrint *printer);
	virtual ~JUTException();

	virtual void run();

	void printContext(u16, OSContext *, u32, u32);
	void createFB();

	static void appendMapFile(char *mapPath);
	static bool queryMapAddress(char *, u32, s32, u32 *, u32 *, char *, u32, bool, bool);

	u32 _60;
	JUTDirectPrint* mPrinter; // _64
};

#endif // JUT_H