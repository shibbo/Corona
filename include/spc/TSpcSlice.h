#ifndef TSPCSLICE_H
#define TSPCSLICE_H

class TSpcSlice
{
    public:
    TSpcSlice();

    int getDataInt() const;
    float getDataFloat() const;
    
    bool operator !=(TSpcSlice const &) const;
    bool operator ==(TSpcSlice const &) const;

    int _0;
    int _4;
};

#endif // TSPCSLICE_H