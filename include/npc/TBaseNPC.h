#ifndef TBASENPC_H
#define TBASENPC_H

#include "types.h"
#include "actor/TSpineEnemy.h"

/* NPC IDs */
#define JELLYFISH_MARE 0x400000F
#define SUNFLOWER_NPC 0x400001A


class TBaseNPC : public TSpineEnemy
{
	public:
	TBaseNPC(u32, char const *);
	~TBaseNPC();
	
	u32 _150;
	u32 _154;
	u32 _158;
	u32 _15C;
	u32 _160;
	u32 _164;
	u32 _168;
	u32 _16C;
	u32 _170;
	u8 _174;
	u8 _175;
	u8 _176;
	u8 _177;
	f32 _178;
	u32 _17C;
	u32 _180;
	u32 _184;
	u32 _188;
	u32 _18C;
	u32 _190;
	u8 _194[0x1C4-0x194];
	f32 _1C4;
	f32 _1C8;
	u32 _1CC;
	f32 _1D0;
	u32 _1D4;
	u8 _1D8;
	u8 _1D9;
	u8 _1DA;
	u8 _1DB; // padding?
	u32 _1DC;
	u16 _1E0;
	u16 _1E2;
	u16 _1E4;
	u16 _1E6; // padding?
	u32 _1E8;
	u32 _1EC;
	f32 _1F0;
	f32 _1F4;
	f32 _1F8;
	u32 _1FC;
	u32 _200;
	u32 _204;
	u32 _208;
	f32 _20C;
	f32 _210;
	f32 _214;
	f32 _218;
	f32 _21C;
	f32 _220;
	f32 _224;
	u32* _228;
	u32 _22C;
	u32 _230;

	static u32** mPtrSaveNormal;
	static u16** mAngleYDiffWhenTaken;
};

#endif // TBASENPC_H