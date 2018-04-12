#ifndef TSPCBINARY_H
#define TSPCBINARY_H

class TSpcBinary
{
    public:
    TSpcBinary(void *);
    ~TSpcBinary();

    void initUserBuiltin();
    void* getHeader() const;
    void bindSystemDataToSymbol(char const *, unsigned long);
    int* searchSymbol(char const *);
    void init();
    
    
    void* spcBinary; // _0
    int* vtable; // _4
};


#endif // TSPCBINARY_H