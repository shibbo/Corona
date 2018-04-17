#ifndef TNERVEBASE_H
#define TNERVEBASE_H

// i've seen TLiveActor with this
template <typename T>
class TNerveBase
{
    public:
    TNerveBase();
    ~TNerveBase();

    int* vtable; // _0
};

#endif // TNERVEBASE_H