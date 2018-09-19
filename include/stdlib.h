#ifndef STDLIB_H
#define STDLIB_H

#ifdef __cplusplus
extern "C" {
#endif

char* strcat(char *, const char *);
char* strchr(const char *, int);
char* strrchr(const char *, int);
char* strstr(const char *, const char *);
int strcmp(char *, char *);
size_t strlen(const char *);

#ifdef __cplusplus
}
#endif

#endif // STDLIB_H