#ifndef TSPLINEPATH_H
#define TSPLINEPATH_H

class TSplinePath
{
    public:
    TSplinePath(int); // this integer is nodeCount + 3

    float calcSpline(float, float *, float *, float *);
    void calcTable();
    void makeTable(float *, float *, float *);
    void getFloat(float);

    int _0; // said nodeCount + 3 is stored here
    float* _4;
    float* _8;
    float* _C;
    float* _10;
    float* _14;
    float* _18;
    float* _1C;
    float* _20;
    float* _24;
};

#endif // TSPLINEPATH_H