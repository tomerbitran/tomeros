#include "screen.h"



namespace serial {

VGAEntry vga_entry(unsigned char uc, VGAColorEntry color)
{
    return (uint16_t) uc | (uint16_t) color << 8;
}

VGAColorEntry vga_color_entry(VGAColor fg, VGAColor bg)
{
    return fg | bg << 4;
}

Screen::Screen() : 
    m_row(0),
    m_column(0),
    m_color(vga_color_entry(VGA_COLOR_GREEN, VGA_COLOR_BLACK)),
    m_buffer((uint16_t*) 0xB8000)
{
	for (size_t y = 0; y < VGA_HEIGHT; y++) 
	{
		reset_row(y);
	}
}

void Screen::putentryat(VGAEntry entry, size_t x, size_t y) 
{
	const size_t index = y * VGA_WIDTH + x;
	m_buffer[index] = entry;
}


void Screen::putentryat(char c, VGAColorEntry color, size_t x, size_t y) 
{
	putentryat(vga_entry(c, color), x, y);
}

void Screen::reset_row(size_t row_num)
{
    for (size_t x = 0; x < VGA_WIDTH; x++) 
	{
		putentryat(' ', m_color, x, row_num);
	}
}

void Screen::setcolor(VGAColorEntry color) 
{
    m_color = color;
}

void Screen::scroll(int num_lines) 
{
    uint16_t* new_terminal_start = m_buffer + num_lines * VGA_WIDTH;
	memcpy(m_buffer, new_terminal_start, ((VGA_HEIGHT - num_lines) * VGA_WIDTH) * 2);

	for (size_t y = VGA_HEIGHT - num_lines; y < VGA_HEIGHT; y++) {
		reset_row(y);
	}

	m_row = m_row - num_lines;
}

void Screen::put_newline()
{
    m_column = 0;
	m_row++;
	if (m_row == VGA_HEIGHT) 
	{
		scroll(1);
	}
}

void Screen::putchar(char c) 
{
	if (c == '\n') 
	{
		put_newline();
		return;
	}

	putentryat(c, m_color, m_column, m_row);

	if (++m_column == VGA_WIDTH) 
	{
		put_newline();
	}
}
 
void Screen::write(const char* data, size_t size) 
{
	for (size_t i = 0; i < size; i++) 
	{
		putchar(data[i]);
	}
}
 
void Screen::writestring(const char* data) 
{
	write(data, strlen(data));
}


} //namespace serial
