#ifndef JUT_H
#define JUT_H

#include "JKR.h"
#include "pad.h"

namespace JUtility
{
	class TColor
	{
		public:
		TColor();
		void set(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
		
		unsigned char R; // _0
		unsigned char G; // _1
		unsigned char B; // _2
		unsigned char A; // _3
	};
};

using namespace JUtility;

class JUTPoint
{
	public:
	JUTPoint();
	
	int X; // _0
	int Y; // _4
};

class JUTRect
{
	public:
	JUTRect();
	JUTRect(int, int, int, int);
	
	void set(int, int, int, int);
	void copy(JUTRect const &);
	void add(int, int);
	int intersect(JUTRect const &);
	void move(int, int);
	void resize(int, int);
	void reform(int, int, int, int);
	void normalize();
	bool isEmpty() const;
	
	int X; // _0
	int Y; // _4
	int Height; // _8
	int Width; // _C
};

/* Size -- 0x1C */
class JUTFont
{
	public:
	JUTFont();
	~JUTFont();
	
	void initiate(); // nullsub
	void setCharColor(TColor);
	void setGradColor(TColor, TColor);
	void drawString_size_scale(float, float, float, float, char const *, unsigned long, bool);
	void setGX(TColor, TColor);
	
	int* vtable; // _0
	char _4;
	char _5; // padding?
	char _6; // ^^
	char _7; // ^^
	int _8;
	TColor color1; // _C
	TColor color2; // _10
	TColor color3; // _14
	TColor color4; // _18
};

/* Size -- 0x6C */
class JUTResFont : public JUTFont
{
	public:
	JUTResFont(int const *, JKRArchive *); // ResFont
	~JUTResFont();
	
	void initiate(int const *, JKRArchive *); // ResFont
	void setGX();
	void setGX(TColor, TColor);
	
	int _1C;
	int _20;
	char _24[0x44-0x24]; // GXTexObj
	int _44;
	int _48;
	int _4C; // padding?
	int _50;
	int _54;
	int _58;
	short _5C;
	short _5E;
	short _60;
	short _62;
	short _64;
	short _66;
	int _68;
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
	JUTGamePad(int); // EPadPort
	~JUTGamePad();

	void assign();
	void update();

	class CButton
	{
		public:
		CButton();

		void clear();
		void update(PADStatus const *, unsigned long);
		void setRepeat(unsigned long, unsigned long, unsigned long);

		int _0;
		int _4;
		int _8;
		char analogA; // _C
		char analogB; // _D
		char triggerLeft; // _E
		char triggerRight; // _F
		float _10;
		float _14;
		int _18;
		int _1C;
		int _20;
		int _24;
		int _28;
		int _2C;
	};

	class CStick
	{
		public:
		CStick();

		void clear();
		int update(signed char, signed char, EStickMode, WhichStick);
		int getButton();

		float stickX;
		float stickY;
		float length;
		short angle;
		short _E; // i assume unused
	};

	class CRumble
	{
		public:
		void clear(JUTGamePad *);
		void stopMotor(int);
		void stopMotorHard(int);
		void update(short);
		void setEnable(unsigned long);

		int _0;
		int _4;
		int _8;
		int _C;
	};

	CButton buttons; // _18
	CStick controlStick; // _48
	CStick cStick; // _58
	CRumble rumble; // _68
	short port; // _78
	short _7A; // padding?
	JSUPtrLink ptrLink; // _7C
	int  _8C;
	int _90;
	int _94;
	int _98;
};

#endif // JUT_H