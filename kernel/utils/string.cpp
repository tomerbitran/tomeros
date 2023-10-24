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


// 	COPILOT CODE 💀💀💀💀
// BRUH

size_t itoa(int n, char* buf, int base) {
	size_t i = 0;
	bool isNegative = false;
	if (n == 0) {
		buf[i++] = '0';
		buf[i] = '\0';
		return i;
	}
	if (n < 0 && base == 10) {
		isNegative = true;
		n = -n;
	}
	while (n != 0) {
		int rem = n % base;

		// char hacks :)
		buf[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0'; 
		n = n / base;
	}

	if (isNegative) {
		buf[i++] = '-';
	}
	buf[i] = '\0';

	//reverse string
	for (size_t j = 0; j < i / 2; j++) {
		char tmp = buf[j];
		buf[j] = buf[i - j - 1];
		buf[i - j - 1] = tmp;
	}
	return i;
}



size_t vsnprintf(char* str, size_t n, const char* format, va_list args) 
{
	size_t i = 0;
	size_t j = 0;
	while (format[i] != '\0' && i < n) 
	{
		if (format[i] == '%') 
		{
			i++;
			switch (format[i]) 
			{
				case 'd': 
				{
					int arg = va_arg(args, int);
					char buf[32];
					itoa(arg, buf, 10);
					size_t len = strlen(buf);
					memcpy(str + j, buf, len);
					j += len;
					break;
				}
				case 'x': 
				{
					int arg = va_arg(args, int);
					char buf[32];
					itoa(arg, buf, 16);
					size_t len = strlen(buf);
					memcpy(str + j, buf, len);
					j += len;
					break;
				}
				case 's': 
				{
					char* arg = va_arg(args, char*);
					size_t len = strlen(arg);
					memcpy(str + j, arg, len);
					j += len;
					break;
				}
				case 'c': 
				{
					char arg = va_arg(args, int);
					str[j] = arg;
					j++;
					break;
				}
				default:
					break;
			}
		} 
		else 
		{
			str[j] = format[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return j;
}

size_t snprintf(char* str, size_t n, const char* format, ...) 
{
	va_list args;
	va_start(args, format);
	size_t len = vsnprintf(str, n, format, args);
	va_end(args);
	return len;
}
