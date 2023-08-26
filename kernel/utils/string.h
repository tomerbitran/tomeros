#ifndef __STRING_H
#define __STRING_H

#include <stdint.h>
#include <stddef.h>

size_t strlen(const char* str);
size_t memcpy(void* dst, void* src, size_t n);

#endif //__STRING_H