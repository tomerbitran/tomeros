#include "io_port.h"

namespace serial {
IoPort::IoPort(uint16_t port){
    this->m_port = port;
}

void IoPort::write(uint8_t data) {
    asm volatile("outb %0, %1" : : "a"(data), "Nd"(m_port));
}

void IoPort::writeString(const char *str) {
    while (*str != '\0') {
        write(*str);
        str++;
    }
}

uint8_t IoPort::read() {
    uint8_t result;
    asm volatile("inb %1, %0" : "=a"(result) : "Nd"(m_port));
    return result;
}



} //namespace serial