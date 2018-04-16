#include <kamek.h>

// this is a write to direct code to change a single instruction.
// when the function incGoldCoin() is called, it accepts an argument of type long that
// is the number of coins to increment by. 
// Old Code: li r5, 1
// New Code: li r5, 0x64 # 100
kmWrite32(0x801BECD4, 0x38A00064);