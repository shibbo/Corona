#ifndef TSHINE_H
#define TSHINE_H

#include "JDrama.h"
#include "types.h"
#include "actor/TItem.h"

class TShine : public TItem
{
    public:
    TShine(char const *);
    virtual ~TShine();

    virtual void loadAfter();
    virtual void perform(u32, JDrama::TGraphics *);
    virtual bool recieveMessage(THitActor *, u32);
    virtual void control();
    virtual void kill();
    virtual void initMapObj();
    virtual void loadBeforeInit(JSUMemoryInputStream &);
    virtual u32* makeMActors();
    virtual void calc();
    virtual void touchPlayer(THitActor *);
    void appearWithDemo(char const *);
    void appearSimple(int);
    void appearWithTimeCallback(int, int);
    void appearWithTime(int, int, int, int);

    u32 _154;
    f32 _158;
    f32 _15C;
    f32 _160;
    f32 _164;
    u32 _168;
    f32 _16C;
    u32 _170; // unk
    u32 _174; // ^^
    u32 _178; // ^^
    f32 _17C;
    f32 _180;
    f32 _184;
    f32 _188;
    u32 _18C;
    u8 _190;
    u8 _191; // padding?
    u8 _192; // ^^
    u8 _193; // ^^
    u32 _194;
    u32 _198;
    u32 _19C;
    u32 _1A0;
    u32 _1A4;
    f32 _1A8;
    f32 _1AC;
    f32 _1B0;
    u8 _1B4;
    u8 _1B5; // padding?
    u8 _1B6; // ^^
    u8 _1B7; // ^^
};

#endif // TSHINE_H