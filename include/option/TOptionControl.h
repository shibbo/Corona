#ifndef TOPTIONCONTROL_H
#define TOPTIONCONTROL_H

#include "J2D.h"
#include "types.h"
#include "option/TOptionRumbleUnit.h"
#include "option/TOptionSoundUnit.h"
#include "option/TOptionSubtitleUnit.h"

enum SelectType
{
    SELECT_RUMBLE = 0,
    SELECT_SOUND = 1,
    SELECT_SUBTITLES = 2,
    SELECT_UNKNOWN = 3,
};

class TOptionControl
{
    public:
    void resetChangedSetting();
    bool isChangedSetting() const;
    void checkInput();
    void setType(SelectType, bool);
    bool movementOption2Card();
    bool movementOption();
    bool movementCard2Option();
    void draw(J2DOrthoGraph *);
    void loadSetting();
    void load();

    J2DSetScreen* setScreen; // _0
    u32* _4; // TArrowControl*
    TOptionRumbleUnit* rumbleUnit; // _8
    TOptionSoundUnit* soundUnit; // _C
    TOptionSubtitleUnit* subtitleUnit; // _10
    u32 selectType; // _14
    u8 _18;
    u8 _19;
    u8 _1A; // padding?
    u8 _1B; // ^^
    u32 _1C;
};

#endif // TOPTIONCONTROL_H