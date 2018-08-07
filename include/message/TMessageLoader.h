#ifndef TMESSAGELOADER_H
#define TMESSAGELOADER_H

#include "types.h"

struct JMSMesgEntry
{
    u32 dataOffset; // _0
    u16 startFrame; // 4
    u16 endFrame; // _6
    u32 flags; // _8
};

class TMessageLoader
{
    public:
    TMessageLoader(char const *resource);
    TMessageLoader();

    char* parseBlock(u32 size, u32 count, void* dataPtr);
    s16 loadMessageData(char const *);
    JMSMesgEntry* getMessageEntry(u32 messageID);

    u16 mMessageCount; // _0
    u16 mBaseID; // _2
    void* _4;

};

#endif // TMESSAGELOADER_H