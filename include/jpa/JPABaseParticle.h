#ifndef JPABASEPARTICLE_H
#define JPABASEPARTICLE_H

#include "jpa/JPABaseEmitter.h"

class JPABaseParticle
{
    public:
    void initGlobalPosition();
    void calcGlobalPosition();
    void incTimer();
    void executeParticleCallBack(JPABaseEmitter *);
    void drawParticleCallBack(JPABaseEmitter *);

    u8 _0[0x14];
    f32 _14;
    f32 _1C;
    f32 _20;
    f32 _24;
    f32 _28;
    f32 _2C;
    f32 _30;
    f32 _34;
    f32 _38;
    f32 _3C;
    f32 _40;
    f32 timer; // _44
    f32 _4C;
    u32* _50;
    u32 _54;
    VTABLE; // _58
};

#endif // JPABASEPARTICLE_h