#ifndef __SCREEN_H
#define __SCREEN_H

#include "string.h"
namespace serial 
{

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

enum VGAColor 
{
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};

using VGAEntry = uint16_t;
using VGAColorEntry = uint8_t;

VGAEntry vga_entry(unsigned char uc, VGAColorEntry color);

VGAColorEntry vga_color_entry(VGAColor fg, VGAColor bg);

class Screen
{
    public:
    Screen();

    void reset_row(size_t row_num);
    void scroll(int num_lines);
    void setcolor(VGAColorEntry color);
    void putentryat(VGAEntry entry, size_t x, size_t y);
    void putentryat(char c, VGAColorEntry color, size_t x, size_t y);
    void put_newline();
    void putchar(char c);
    void write(const char* data, size_t size);
    void writestring(const char* data);

    private:
    size_t m_row;
    size_t m_column;
    VGAColorEntry m_color;
    uint16_t* m_buffer;

};

} //namespace serial

#endif //__SCREEN_H