#ifndef JPABASEFIELD_H
#define JPABASEFILED_H

#include "JSUStream.h"
#include "jpa/JPAParticle.h"

class JPABaseField
{
    public:
    JPABaseField();
    ~JPABaseField();

    void set();
    void affect(JPAParticle *particle);
    bool checkMaxDistance(JGeometry::TVec3<f32> &, JGeometry::TVec3<f32> &);
    
    void loadFieldBlock(u32 *data); // JPADataBlock*
    void calcFieldVelocity(JPAParticle *);
    f32 calcFieldFadeScale(f32);

    JSUPtrLink ptrLink; // _0
    f32 _10;
    f32 _14;
    f32 _18;
    f32 _1C;
    f32 _20;
    Vec _24;
    f32 _30;
    f32 _34;
    f32 _38;
    f32 _3C;
    f32 _40;
    f32 _44;
    f32 _48;
    f32 _4C;
    u16 _50;
    u8 _52;
    u8 _53; // padding?
    u16 _54;
    u8 _56[0x6C-0x56];
    Vec _6C;
    f32 _78;
    Vec _7C;
    u32 _88;
    VTABLE; // _8C

};

#endif // JPABASEFIELD_H