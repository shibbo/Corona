#ifndef __KAMEK_BASE_C_STDLIB_H
#define __KAMEK_BASE_C_STDLIB_H

#ifdef __cplusplus
extern "C" {
#endif

extern f32 NAN;

/* stdarg.h */
typedef struct va_list_struct {
	char gpr, fpr, reserved[2], *input_arg_area, *reg_save_area;
} va_list[1];
extern void *__va_arg(void *, int);
#define va_start(ap, last) (__builtin_va_info(&ap))
#define va_arg(ap, type) (*((type *)__va_arg(ap, _var_arg_typeof(type))))
#define va_end(ap) ((void)0)

/* stdio.h */
int snprintf(char *, size_t, const char *, ...);
int sprintf(char *, const char *, ...);
int vsnprintf(char *, size_t, const char *, va_list);
int vsprintf(char *, const char *, va_list);

/* wchar.h */
int vswprintf(wchar_t *, size_t, const wchar_t *, va_list);
wchar_t *wcschr(const wchar_t *, wchar_t);
int wcscmp(const wchar_t *, const wchar_t *);
wchar_t *wcscpy(wchar_t *, const wchar_t *);
wchar_t *wcsncpy(wchar_t *, const wchar_t *, size_t);
size_t wcslen(const wchar_t *);
wchar_t *wmemchr(const wchar_t, wchar_t, size_t);
wchar_t *wmemcpy(wchar_t *, const wchar_t *, size_t);

#ifdef __cplusplus
}
#endif

#endif
