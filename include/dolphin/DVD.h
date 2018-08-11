#ifndef DVD_H
#define DVD_H

#include "types.h"

#ifdef __cplusplus
extern "C"{
#endif

// our callbacks
typedef void (*DVDCallback)(s32 result, DVDFileInfo *info);
typedef void (*DVDCBCallback)(s32 result, DVDCommandBlock *cmdBlock);

struct DVDDiskID
{
    char name[0x04]; // _0
    char company[0x02]; // _4
    u8 diskNum; // _6
    u8 version; // _7
    u8 streaming; // _8
    u8 streamBufferSize; // _9
    u8 pad[0x16]; // _A
};

struct DVDCommandBlock
{
    DVDCommandBlock* nextBlock; // _0
    DVDCommandBlock* prevBlock; // _4
    u32 curCommand; // _8
    s32 curState; // _C
    u32 offset; // _10
    u32 length; // _14
    void* address; // _18
    u32 curTransferSize; // _1C
    u32 transferredSize; // _20
    DVDDiskID* diskID; // _24
    DVDCBCallback cb; // _28
    void* data; // _2C
};

struct DVDFileInfo
{
    DVDCommandBlock cmdBlock; // _0
    u32 start; // _30
    u32 len; // _34
    DVDCallback cb; // _38
};

// credit to arookas
struct DVDDriveInfo 
{
    u16 revisionLevel; // _0
    u16 deviceCode; // _2
    u16 releaseDate; // _4
    u8 pad[0x18];
};

void DVDInit();

s32 DVDConvertPathToEntrynum(char *path);
bool DVDOpen(char *name, DVDFileInfo *info);
bool DVDFastOpen(s32 entryNum, DVDFileInfo *info);
bool DVDClose(DVDFileInfo *info);

bool DVDGetCurrentDir(char *path, u32 maxLength);
bool DVDChangeDir(char *directoryName);

bool DVDReadAsyncPrio(DVDFileInfo *info, void *address, s32 length, s32 offset, DVDCallback cb, s32 priority);
s32 DVDReadPrio(DVDFileInfo *info, void *address, s32 length, s32 offset, s32 priority);

bool DVDPrepareStreamAsync(DVDFileInfo *info, u32 length, u32 offset, DVDCallback cb);
bool DVDCancelStreamAsync(DVDCommandBlock *cmdBlock, DVDCBCallback cb);
bool DVDStopStreamAtEndAsync(DVDCommandBlock *cmdBlock, DVDCBCallback cb);
bool DVDGetStreamPlayAddrAsync(DVDCommandBlock *cmdBlock, DVDCBCallback cb);

s32 DVDGetCommandBlockStatus(DVDCommandBlock *cmdBlock);
s32 DVDGetDriveStatus();

bool DVDInquiryAsync(DVDCommandBlock *cmdBlock, DVDDriveInfo *info, void *cb);

bool DVDSetAutoInvalidation(bool isAutoInvalidated);

bool DVDCancelAsync(DVDCommandBlock *cmdBlock, DVDCBCallback cb);
s32 DVDCancel(DVDCommandBlock *cmdBlock);
DVDDiskID* DVDGetCurrentDiskID();
bool DVDCheckDisk();

#ifdef __cplusplus
}
#endif

#endif // DVD_H