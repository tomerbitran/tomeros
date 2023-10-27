#include "gdt.h"

namespace gdt {

gdt_entry::gdt_entry(uint32_t base, uint32_t limit, gdt_access access, uint8_t granularity, uint8_t db_size, uint8_t long_mode) 
    : access(access),
      granularity(granularity & 1),
      db_size(db_size & 1),
      long_mode(long_mode & 1),
      reserved(0)
{   
    set_base(base);
    set_limit(limit);
}

void gdt_entry::set_base(uint32_t base) {
    base_low = base & 0xFFFF;
    base_middle = (base >> 16) & 0xFF;
    base_high = (base >> 24) & 0xFF;
}
void gdt_entry::set_limit(uint32_t limit) {
    limit_low = limit & 0xFFFF;
    limit_high = (limit >> 16) & 0xF;
}

uint32_t gdt_entry::get_base() 
{
    return (base_high << 24) | (base_middle << 16) | base_low;
}
uint32_t gdt_entry::get_limit() {
    return (limit_high << 16) | limit_low;
}


const uint8_t gdt_size = 6;
gdt_entry gdt[gdt_size];
gdt_ptr gdtptr;



void load_gdt() {
    gdtptr.limit = sizeof(gdt) - 1;
    gdtptr.base = (uint32_t)&gdt;
    asm volatile("lgdt (%0)" : : "r"(&gdtptr));
}

void init_gdt() {
    // Set up GDT entries
    

    // Load GDT
    //load_gdt();
}

} //namespace gdt