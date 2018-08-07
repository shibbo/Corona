#ifndef MAP_H
#define MAP_H

#include "JDrama.h"
#include "JSUStream.h"

class TMapCollisionData
{
    public:
    TMapCollisionData();

    f32 _0;
    f32 _4;
    u32 _8;
    u32 _C;
    u32 _10;
    u32 _14;
    u32 _18;
    u32 _1C;
    u32 _20;
    u32 _24;
    u32 _28;
    u32 _2C;
    u32 _30;
    u32 _34;
    u32 _38;
    u32 _3C;
    u16 _40;
    u16 entries[256]; // _42
};

class TMapWarp
{
    public:
    TMapWarp();

    void init(JSUMemoryInputStream &);
    void initModel();
    void watchToWarp();
    void changeModel(u32);


    u32 _0;
    u32 _4;
    u32 _8;
    f32 _C; // init'd to 3.0

    class TMapWarpInfo
    {
        public:
        TMapWarpInfo(); // nullsub
    };
};

class TMap : public JDrama::TViewObj
{
    public:
    TMap(char const *);
    ~TMap();

    void load(JSUMemoryInputStream &);
    void loadAfter();
    void perform(u32, JDrama::TGraphics *);

    void changeModel(u32) const;
    f32 checkGround(f32, f32, f32, u32 const **) const; // TBGCheckData
    f32 checkGround(JGeometry::TVec3<f32> const &, u32 const **) const; // TBGCheckData
    f32 checkGroundExactY(f32, f32, f32, u32 const **) const;
    
    bool isTouchedOneWallAndMoveXZ(f32 *, f32, f32 *, f32) const;
    bool isTouchedOneWall(f32, f32, f32, f32) const;
    bool intersectLine(JGeometry::TVec3<f32> const &, JGeometry::TVec3<f32> const &, bool, JGeometry::TVec3<f32> *) const;
    bool isInArea(f32, f32) const;
    u32* getIllegalCheckData();
    void update();

    TMapCollisionData* collisionData; // _10
    u32* _14; // TMapModelManager
    TMapWarp* mapWarp; // _18
    u32* _1C; // TMapXlu
};

void initStage();
void initStageCommon();
void initPinnaParco();
void initMare();
void initMonte();

#endif // MAP_H