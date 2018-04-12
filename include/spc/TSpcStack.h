#ifndef TSPCSTACK_H
#define TSPCSTACK_H

// I've only seen this used as unsigned long and TSpcSlice
template <typename T>
class TSpcStack
{
    public:
    ~TSpcStack();

    int _0;
    int _4;
    int* _8; // some array
    int* vtable; // _C
};

#endif // TSPCSTACK_H