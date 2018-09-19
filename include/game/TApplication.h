#ifndef TAPPLICATION_H
#define TAPPLICATION_H

#include "JDrama.h"
#include "types.h"

class TMarioGamePad;

class TApplication
{
    public:
    TApplication();
    
    u32* mountStageArchive();
    u32 drawDVDErr();
    s32 gameLoop();
    void proc();
    bool checkAdditionalMovie();
    bool finalize();
    void initialize_nlogoAfter();
    void initialize_bootAfter();
    bool setupThreadFuncLogo();
    void initialize();
    bool setup(JDrama::TDisplay *, TMarioGamePad **, u8, u8);

    u8 _0[0xD];
    u8 curStageID; // _E
    u8 curEpisodeID; // _F
    u8 _10;
    u8 _11;
    u8 nextStageID; // _12
    u8 nextEpisodeID; // _13
    u16 _14;
    u32 _18;
    JDrama::TDisplay* mDisplay; // _1C
    TMarioGamePad* mGamePad; // _20
    u8 _24[0x34-0x24];
    u32* _34; // TSMSFader*
    u8 _38;
};

bool SetupThreadFuncLogo(void *);
bool SetupThreadFuncBoot(void *);

#endif // TAPPLICATION_H