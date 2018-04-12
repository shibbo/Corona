#ifndef CARD_H
#define CARD_H

// this seems to be what is referenced in a lot of functions
typedef void (*CARDCallback)(int chan, int res);

typedef struct CARDInfo
{
    int channel;
    int fileNo;

    int offset;
    int length;
    short block;
} CARDInfo;

#ifdef __cplusplus
extern "C" {
#endif

void CARDInit();
void CARDCheck(int chan);
int CARDCreate(int chan, char *fileName, int size, CARDInfo *cardInfo);
int CARDCreateAsync(int chan, char *fileName, int size, CARDInfo *cardInfo, CARDCallback cardCB);
int CARDFormat(int chan);
int CARDFormatAsync(int chan, CARDCallback cardCB);

#ifdef __cplusplus
}
#endif

#endif // CARD_H