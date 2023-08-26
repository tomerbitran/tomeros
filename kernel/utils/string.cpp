#include "string.h"

size_t strlen(const char* str) 
{
	size_t len = 0;
	while (str[len])
	{
		len++;
	}
	return len;
}

size_t memcpy(void* dst, void* src, size_t n) {
	char* cdest = (char*) dst;
	char* csrc 	= (char*) src;

	for (size_t i = 0; i < n; i++)
	{
		cdest[i] = csrc[i];
	}
	return n;
}
