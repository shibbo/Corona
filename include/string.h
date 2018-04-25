#ifndef STRING_H
#define STRING_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

void *memchr(const void *, u32, size_t);
u32 memcmp(const void *, const void *, size_t);
void *memcpy(void *, const void *, size_t);
void *memmove(void *, const void *, size_t);
void *memset(void *, u32, size_t);
u8 *strcpy(u8 *, const u8 *);
u8 *strncpy(u8 *, const u8 *, size_t);
u8 *strcat(u8 *, const u8 *);
u8 *strncat(u8 *, const u8 *, size_t);
size_t strlen(const u8 *);
u32 strcmp(const u8 *, const u8 *);
u32 strncmp(const u8 *, const u8 *, size_t);
u32 stricmp(const u8 *, const u8 *);
u8 *strchr(const u8 *, u32);
u8 *strrchr(const u8 *, u32);
u8 *strstr(const u8 *, const u8 *);

#ifdef __cplusplus
}
#endif

#endif // STRING_H