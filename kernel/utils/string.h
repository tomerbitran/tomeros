#ifndef __STRING_H
#define __STRING_H

#include "../common.h"

size_t strlen(const char* str);
size_t memcpy(void* dst, void* src, size_t n);

size_t itoa(int n, char* buf, int base);
size_t vsnprintf(char* str, size_t n, const char* format, va_list args);
size_t snprintf(char* str, size_t n, const char* format, ...);

#endif //__STRING_H