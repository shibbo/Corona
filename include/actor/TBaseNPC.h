#ifndef TBASENPC_H
#define TBASENPC_H

#include "actor/TSpineEnemy.h"

/* NPC IDs */
#define JELLYFISH_MARE 0x400000F
#define SUNFLOWER_NPC 0x400001A


class TBaseNPC : public TSpineEnemy
{
	public:
	TBaseNPC(unsigned long, char const *);
	~TBaseNPC();
	
	int _150;
	int _154;
	int _158;
	int _15C;
	int _160;
	signed int _164;
	int _168;
	int _16C;
	int _170;
	char _174;
	char _175;
	char _176;
	char _177;
	float _178;
	int _17C;
	int _180;
	int _184;
	int _188;
	int _18C;
	int _190;
	char _194[0x1C4-0x194];
	float _1C4;
	float _1C8;
	int _1CC;
	float _1D0;
	int _1D4;
	char _1D8;
	char _1D9;
	char _1DA;
	char _1DB; // padding?
	int _1DC;
	short _1E0;
	short _1E2;
	short _1E4;
	short _1E6; // padding?
	int _1E8;
	int _1EC;
	float _1F0;
	float _1F4;
	float _1F8;
	int _1FC;
	int _200;
	int _204;
	int _208;
	float _20C;
	float _210;
	float _214;
	float _218;
	float _21C;
	float _220;
	float _224;
	int* _228;
	int _22C;
	int _230;
};

#endif // TBASENPC_H