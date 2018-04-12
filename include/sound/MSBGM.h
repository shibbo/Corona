#ifndef MSBGM_H
#define MSBGM_H

class MSBgm
{
    public:
    static void setStageBgmYoshiPercussion(bool);
    static void setDolby(unsigned char, float, unsigned long, unsigned char);
    static void setPan(unsigned char, float, unsigned long, unsigned char);
    static void setVolume(unsigned long, float, unsigned long, unsigned char);
    static void setTrackVolume(unsigned char, float, unsigned long, unsigned char);
    static void stopTrackBGMs(unsigned char, unsigned long);
    static void stopTrackBGM(unsigned char, unsigned long);
    static void stopBGM(unsigned long, unsigned long);
    static int* getHandle(unsigned char);
    static int* startBGM(unsigned long);
    static int getSceneNo(unsigned long);
    static void init();
};
#endif // MSBGM_H