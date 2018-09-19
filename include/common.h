#ifndef COMMON_H
#define COMMON_H

// r13
#define SDA_ADDR_NUS 0x804141C0

// object names
#define OBJ_ONEUP           0x20000006
#define OBJ_COIN            0x2000000E
#define OBJ_BLUE_COIN       0x20000010
#define OBJ_ROCKET_NOZZLE   0x20000022
#define OBJ_HOVER_NOZZLE    0x20000026
#define OBJ_TURBO_NOZZLE    0x2000002A

// possible fruits
enum Fruits
{
    FRUIT_COCONUT =     0x40000390,
    FRUIT_PAPAYA =      0x40000391,
    FRUIT_PINEAPPLE =   0x40000392,
    FRUIT_DURIAN =      0x40000393,
    FRUIT_BANANA =      0x40000394
};

// mario states
#define MARIO_STATE_TAKING      0x0C400201
#define MARIO_STATE_TALKING     0x10001308

#endif // COMMON_H