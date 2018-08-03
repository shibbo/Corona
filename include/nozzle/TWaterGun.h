#ifndef TWATERGUN_H
#define TWATERGUN_H

#include "types.h"
#include "nozzle/TNozzleBase.h"

class TMario;

class TWaterGun
{
	public:
	TWaterGun(TMario *);
	
	VTABLE; // _0
	u32 _4;
	TMario* mMario; // _8
	TNozzleBase mNozzleDeform; // _C
	TNozzleBase mNozzleDeformBomb; // _390
	u8 _714;
	u8 _715;
	u8 _716;
	u8 _717; // padding?
	u16 _718;
	TNozzleBase mNozzleRocket; // _720
	u8 _AA4;
	u8 _AA5;
	u16 _AA6;
	f32 _AA8;
	u32 _AAC;
	TNozzleBase mNozzleHover; // _AB0
	TNozzleBase mNozzleDummy; // _E34 (parameters are "nozzle diving"?)
	TNozzleBase mNozzleBase6; // _11B8 ("deformbomb")
	u8 _153C;
	u8 _153D;
	u8 _153E;
	u8 _153F; // padding?
	f32 _1540;
	u32 _1544;
	TNozzleBase mNozzleBase7; // _1548
	u8 _18CC[0x1DD0-0x18CC]; // one more nozzlebase and parameters

};

#endif // TWATERGUN_H