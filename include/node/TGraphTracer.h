#ifndef TGRAPHTRACER_H
#define TGRAPHTRACER_H

class TGraphTracer
{
    public:
    TGraphTracer();

    int getCurGraphIndex() const;
    int* getGraph() const;
    int traceSpline(float);
    float calcSplineSpeed(float);
    void moveTo(int);
    void setTo(int);

    int* _0; // not sure WHAT graph yet
    int graphIndex;
    int _8;
    float _C;
    float _10;
    float _14;
};

#endif // TGRAPHTRACER_H