#ifndef THP_H
#define THP_H

#ifdef __cplusplus
extern "C" {
#endif

struct VideoInfo
{
	int h;
	int w;
};

struct GXRenderModeObj
{
	int _0; // some VI shit
	short _4;
	short _6;
	short _8;
	short _A;
	short _C;
	short _E;
	short _10;
	int _12;
	char _16;
	char _17;
	char _18[12][2];
	char _19[7];
};

bool THPPlayerInit(int);
bool THPPlayerOpen(char *, int);
bool THPPlayerClose();
int THPPlayerCalcNeedMemory();
bool THPPlayerSetBuffer(char *);
bool THPPlayerPlay();
bool THPPlayerPrepare(int, int, int);
void THPPlayerStop();
bool THPPlayerPause();
void THPPlayerDrawDone();
signed int THPPlayerDrawCurrentFrame(GXRenderModeObj *, int, int, int, int);
bool THPPlayerPrepare(int, int, int);
void THPPlayerQuit();
bool THPPlayerGetVideoInfo(VideoInfo *);

#ifdef __cplusplus
}
#endif

#endif // THP_H