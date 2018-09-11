#ifndef KOGA_H
#define KOGA_H

#include "types.h"

// this seems to be named after Naoki Koga, a support programmer
// seems to be responsible for reading BCR files
namespace Koga
{
    class ToolData
    {
        public:
        ToolData();
        virtual ~ToolData();

        bool Attach(void const *src);
        bool GetValue(int, char const *, char const *&);
        bool GetValue(int, char const *, s32 &) const;

        VTABLE; // _0
        void* mSrc; // _4
    };
}

#endif // KOGA_H