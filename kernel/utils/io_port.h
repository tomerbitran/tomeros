
#ifndef __IO_PORT_HPP
#define __IO_PORT_HPP

#include "../common.h" 
namespace serial {
class IoPort 
{
public:
    IoPort(uint16_t port);

    ~IoPort() = default;

    void write(uint8_t data);
    void writeString(const char *str);

    uint8_t read();

    private:
    uint16_t m_port;
};


} //namespace serial

#endif //__IO_PORT_HPP