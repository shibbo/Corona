#ifndef TRAILNODE_H
#define TRAILNODE_H

struct TRailNode
{
    char* pathName; // _0
    short _4;
    short count; // _6
    short _8;
    short _A;
    short pitch; // _C
    short yaw; // _E
    short roll; // _10
    short speed; // _12
    short cPoints[8]; // _14
    float pPoints[8]; 
};

#endif // TRAILNODE