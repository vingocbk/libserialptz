#include <iostream>
#include "libserilalptz.h"

int main()
{
    libserilalptz libserilalptz;
    char datares;

    libserilalptz.querryPanPosition();

    for(unsigned int i = 0; i < 50; i++)
    {
        try
        {
            // Read a single byte of data from the serial ports.
            // std::cout << "---Read---" << std::endl;
            // serial_port.Read(read_byte_1, 50);
            // std::cout << read_byte_1 << std::endl;
            datares = libserilalptz.readByte(10);
            std::cout << "byte " << i << ": ";
            std::cout << std::hex << datares << std::endl;
            
        }
        catch (const ReadTimeout&)
        {
            // std::cerr << "The ReadByte() call has timed out." << std::endl;
        }
    }

}