#ifndef TSHINE_H
#define TSHINE_H

#include "actor/TItem.h"
#include "JDrama.h"

using namespace JDrama;

class TShine : public TItem
{
    public:
    TShine(char const *);
    ~TShine();

    void loadAfter();
    void perform(unsigned long, TGraphics *);
    bool recieveMessage(THitActor *, unsigned long);
    void control();
    void kill();
    void initMapObj();
    void loadBeforeInit(JSUMemoryInputStream &);
    int* makeMActors();
    void calc();
    void touchPlayer(THitActor *);
    void appearWithDemo(char const *);
    void appearSimple(int);
    void appearWithTimeCallback(unsigned long, unsigned long);
    void appearWithTime(int, int, int, int);

    int _154;
    float _158;
    float _15C;
    float _160;
    float _164;
    int _168;
    float _16C;
    int _170; // unk
    int _174; // ^^
    int _178; // ^^
    float _17C;
    float _180;
    float _184;
    float _188;
    int _18C;
    char _190;
    char _191; // padding?
    char _192; // ^^
    char _193; // ^^
    int _194;
    int _198;
    int _19C;
    int _1A0;
    int _1A4;
    float _1A8;
    float _1AC;
    float _1B0;
    char _1B4;
    char _1B5; // padding?
    char _1B6; // ^^
    char _1B7; // ^^
};

#endif // TSHINE_H