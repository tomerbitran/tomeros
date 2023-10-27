#ifndef __GDT_H__
#define __GDT_H__

#include "../common.h"
namespace gdt {

void init_gdt();

struct __attribute__((packed)) gdt_access 
{
    uint8_t accessed                : 1;
    uint8_t readable_writable       : 1;
    uint8_t direction_conforming    : 1;
    uint8_t executable              : 1;
    uint8_t descriptor_type         : 1;
    uint8_t privilege_level         : 2;
    uint8_t present                 : 1;

    gdt_access(     uint8_t accessed,
                    uint8_t readable_writable,
                    uint8_t direction_conforming,
                    uint8_t executable,
                    uint8_t descriptor_type,
                    uint8_t privilege_level) :
                        accessed(accessed & 1 ),
                        readable_writable(readable_writable & 1),
                        direction_conforming(direction_conforming & 1),
                        executable(executable & 1),
                        descriptor_type(descriptor_type & 1),
                        privilege_level(privilege_level & 3),
                        present(1)  // always set to 1
                        {
                        }
    gdt_access() = default;
};
static_assert(sizeof(gdt_access) == 1);

struct  __attribute__((packed)) gdt_entry {
    uint16_t limit_low  : 16;
    uint16_t base_low   : 16;
    uint8_t base_middle : 8;
    gdt_access access;
    uint8_t limit_high  : 4;
    uint8_t granularity : 1;
    uint8_t db_size     : 1;
    uint8_t long_mode   : 1;
    uint8_t reserved    : 1;
    uint8_t base_high   : 8;

    uint32_t get_base();
    uint32_t get_limit();
    gdt_entry(uint32_t base, uint32_t limit, gdt_access access, uint8_t granularity, uint8_t db_size, uint8_t long_mode);
    gdt_entry() = default;

private:
    void set_base(uint32_t base);
    void set_limit(uint32_t limit);
};
static_assert(sizeof(gdt_entry) == 8);



struct gdt_ptr {
    uint16_t limit;
    uint32_t base;
};

} // namespace gdt
#endif //__GDT_H__