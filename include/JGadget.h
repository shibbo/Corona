#ifndef JGADGET_H
#define JGADGET_H


namespace JGadget
{
    template<typename T>
    class TAllocator
    {

    };

    class TVector_pointer_void
    {
        public:
        TVector_pointer_void(TAllocator<void *> const &);
        
        char _0;
        char _1; // padding?
        char _2; // ^^
        char _3; // ^^
        u32 _4;
        u32 _8;
        u32 _C;
        f32 _10; // init'd to 2.0
        u32 _14;
    };

    class TList_pointer_void
    {
        public:
        TList_pointer_void(TAllocator<void *> const &);

        u8 _0;
        u8 _1;
        u8 _2;
        u8 _3;
        u32 _4;
        u32 _8;
        u32 _C;
    };

    // i've seen this as THitActor
    template<typename T>
    class TList_pointer
    {
        TList_pointer(TAllocator<void *> const &);
        void end();

        u32 _0;
    };
};

#endif // JGADGET_H