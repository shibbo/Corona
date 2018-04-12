#ifndef JAISOUND_H
#define JAISOUND_H

struct JAIMoveParaSet
{
    float _0;
    float _4;
    float _8;
    int* _C;
};

class JAISound
{
    public:
    JAISound();

    void setSeDistanceParameters();
    void setSeDistanceVolume(unsigned char);
    void setSeDistancePan(unsigned char);
    void setSeDistancePitch(unsigned char);
    void setSeDistanceFxmix(unsigned char);
    void setSeDistanceFir(unsigned char);
    void setSeDistanceDolby(unsigned char);
    void setSePositionDopplar();
    void setPositionDopplarCommon(unsigned long);
    void setDistanceVolumeCommon(float, unsigned char);
    void setDistancePanCommon();

    bool initMoveParameter(JAIMoveParaSet *, float, unsigned long);
    int getSeCategoryNumber();
    int getSwBit();
    int checkSwBit(unsigned long);
    char getInfoPriority();
    void claerMainSoundPPointer();
    void release();
    void stop(unsigned long);
    void setVolume(float, unsigned long, unsigned char);
    void setPan(float, unsigned long, unsigned char);
    void setPitch(float, unsigned long, unsigned char);
    void setFxmix(float, unsigned long, unsigned char);
    

    char _0;
    char _1;
    char _2;
    char _3;
    int _4;
    int ID; // _8
    char _C[0x18-0xC];
    int _18;
    int _1C;
    int _20;
    char _24[0x34-0x24];
    int* _34; // sound pointer, maybe?
    int* streamParam; // _38
    void* _3C;
    int* vtable; // _40
};

#endif // JAISOUND_H