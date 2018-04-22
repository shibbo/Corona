#ifndef MAP_H
#define MAP_H

#include "JDrama.h"
#include "JSUStream.h"

using namespace JDrama;

class TMapCollisionData
{
    public:
    TMapCollisionData();

    float _0;
    float _4;
    int _8;
    int _C;
    int _10;
    int _14;
    int _18;
    int _1C;
    int _20;
    int _24;
    int _28;
    int _2C;
    int _30;
    int _34;
    int _38;
    int _3C;
    short _40;
    short entries[256]; // _42
};

class TMapWarp
{
    public:
    TMapWarp();

    void init(JSUMemoryInputStream &);
    void initModel();
    void watchToWarp();
    void changeModel(int);


    int _0;
    int _4;
    int _8;
    float _C; // init'd to 3.0

    class TMapWarpInfo
    {
        public:
        TMapWarpInfo(); // nullsub
    };
};

class TMap : public TViewObj
{
    public:
    TMap(char const *);
    ~TMap();

    void load(JSUMemoryInputStream &);
    void loadAfter();
    void perform(unsigned long, TGraphics *);

    void changeModel(int) const;
    float checkGround(float, float, float, int const **) const; // TBGCheckData
    float checkGround(TVec3<float> const &, int const **) const; // TBGCheckData
    float checkGroundExactY(float, float, float, int const **) const;
    
    bool isTouchedOneWallAndMoveXZ(float *, float, float *, float) const;
    bool isTouchedOneWall(float, float, float, float) const;
    bool intersectLine(TVec3<float> const &, TVec3<float> const &, bool, TVec3<float> *) const;
    bool isInArea(float, float) const;
    int* getIllegalCheckData();
    void update();

    TMapCollisionData* collisionData; // _10
    int* _14; // TMapModelManager
    TMapWarp* mapWarp; // _18
    int* _1C; // TMapXlu
};

void initStage();
void initStageCommon();
void initPinnaParco();
void initMare();
void initMonte();

#endif // MAP_H