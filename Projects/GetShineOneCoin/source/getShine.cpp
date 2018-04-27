#include <kamek.h>

// makes only one coin spawn a shine, rather than 100
kmWrite32(0x801BED40, 0x2C030001);