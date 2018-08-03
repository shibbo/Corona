#ifndef TYPES_H
#define TYPES_H

// note -- u32 and u64 are the same (32-bit)
// same for s32 and s64

typedef signed char         s8;
typedef signed short        s16;
typedef signed int          s32;
typedef signed long         s64;
typedef signed long long    s128;
typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned int        u32;
typedef unsigned long       u64;
typedef unsigned long long  u128;
typedef float               f32;
typedef double              f64;

#define VTABLE u32* vtable;

typedef f32 Mtx[3][4];
typedef f32 (*MtxPtr)[4];
typedef f32 ROMtx[4][3];
typedef f32 (*ROMtxPtr)[3];
typedef f32 Mtx44[4][4];
typedef f32 (*Mtx44Ptr)[4];

#endif // TYPES_H