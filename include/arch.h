#ifndef ARCH_H
#define ARCH_H

#include "types.h"

#ifdef __cplusplus
extern "C" 
{
    u32 PPCMfmsr();                 // move from machine state register
    void PPCMtmsr(u32 newVal);      // move to machine state register
    u32 PPCMfhid0();                // move from special purpose register (HID0)
    void PPCMthid0(u32 newVal);     // move to special purpose register (HID0)
    u32 PPCMfl2cr();                // move from special purpose register (count register)
    void PPCMtl2cr(u32 newVal);     // move to special purpose register (count register)
    void PPCMtdec(u32 newVal);      // move to decrementer
    void PPCSync();                 // system call (sync)
    void PPCHalt();                 // halt ppc
    u32 PPCMfhid2();                // move from special purpose register (HID2)
    void PPCMthid2(u32 newVal);     // move to special purpose register (HID2)
    void PPCMtwpar(u32 newVal);     // move to special purpose register (WPAR)

    void PPCDisableSpeculation();
    void PPCSetFpNonIEEEMode();
}
#endif

#endif // ARCH_H