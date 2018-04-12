#ifndef PAD_H
#define PAD_H

#ifdef __cplusplus
extern "C" {
#endif

#define PAD_STOP_RUMBLE         0
#define PAD_START_RUMBLE        1
#define PAD_STOP_HARD           2

struct PADStatus
{
    short button; // _0
    signed char  stickX; // _2
    signed char  stickY; // _3
    signed char  subStickX; // c stick X (_4)
    signed char  subStickY; // c stick Y (_5)
    char  triggerLeft; // left trigger pressure (_6)
    char  triggerRight; // right trigger pressure (_7)
    char  analogA; // _8
    char  analogB; // _9
    signed char curError; // some odd number based on some constant (_10)
};

bool PADReset(int mask);
bool PADRecalibrate(int mask);
bool PADInit();
int PADRead(PADStatus * padStat);
void PADControlMotor(int channel, int command);

#ifdef __cplusplus
}
#endif

#endif // PAD_H