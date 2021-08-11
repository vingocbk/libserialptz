#include <iostream>
#include "libserilalptz.h"

#define MAX_SPEED   0x3F

libserilalptz libserilalptz;

void querry_Pan_Position(){
    std::cout << "querryPanPosition" << std::endl;
    // libserilalptz libserilalptz;
    libserilalptz.querryPanPosition();
    char datares;
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
            std::cout << (int)datares << std::endl;
            
        }
        catch (const ReadTimeout&)
        {
            // std::cerr << "The ReadByte() call has timed out." << std::endl;
        }
    }
}

void querry_Tilt_Position(){
    std::cout << "querryTiltPosition" << std::endl;
    // libserilalptz libserilalptz;
    libserilalptz.querryTiltPosition();
    char datares;
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
            std::cout << std::hex << (int)datares << std::endl;
            
        }
        catch (const ReadTimeout&)
        {
            // std::cerr << "The ReadByte() call has timed out." << std::endl;
        }
    }
}

void stop_All(){
    std::cout << "stopAll" << std::endl;
    // libserilalptz libserilalptz;
    libserilalptz.stopAll();
    char datares;
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
            std::cout << std::hex << (int)datares << std::endl;
            
        }
        catch (const ReadTimeout&)
        {
            // std::cerr << "The ReadByte() call has timed out." << std::endl;
        }
    }
}
void pan_Left(){
    std::cout << "panLeft" << std::endl;
    // libserilalptz libserilalptz;
    libserilalptz.panLeft(MAX_SPEED);
    char datares;
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
            std::cout << std::hex << (int)datares << std::endl;
            
        }
        catch (const ReadTimeout&)
        {
            // std::cerr << "The ReadByte() call has timed out." << std::endl;
        }
    }
}

void pan_Right(){
    std::cout << "panRight" << std::endl;
    // libserilalptz libserilalptz;
    libserilalptz.panRight(MAX_SPEED);
    char datares;
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
            std::cout << std::hex << (int)datares << std::endl;
            
        }
        catch (const ReadTimeout&)
        {
            // std::cerr << "The ReadByte() call has timed out." << std::endl;
        }
    }
}

void tilt_Up(){
    std::cout << "tiltUp" << std::endl;
    // libserilalptz libserilalptz;
    libserilalptz.tiltUp(MAX_SPEED);
    char datares;
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
            std::cout << std::hex << (int)datares << std::endl;
            
        }
        catch (const ReadTimeout&)
        {
            // std::cerr << "The ReadByte() call has timed out." << std::endl;
        }
    }
}

void tile_Down(){
    std::cout << "tiltDown" << std::endl;
    // libserilalptz libserilalptz;
    libserilalptz.tiltDown(MAX_SPEED);
    char datares;
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
            std::cout << std::hex << (int)datares << std::endl;
            
        }
        catch (const ReadTimeout&)
        {
            // std::cerr << "The ReadByte() call has timed out." << std::endl;
        }
    }
}




int main()
{
    while (true)
    {
        char i;
        std::cout << std::hex << "input i: ";
        std::cin >> i;
        if(i == 'a')
        {
            querry_Pan_Position();
        }
        else if(i == 's')
        {
            stop_All();
        }
        else if(i == 'd')
        {
            querry_Tilt_Position();
        }
        else if(i == 'e')
        {
            pan_Left();
        }
        else if(i == 'r')
        {
            pan_Right();
        }
        else if(i == 't')
        {
            tile_Down();
        }
        else if(i == 'h')
        {
            tilt_Up();
        }
    }
}

// rsync -a -e "ssh -p 1222" /home/ngoc/Documents/gsoap/libserialptz nano@tigerpuma.ddns.net:~/ngocnv_ws
// rsync -a -e "ssh -p 1222" /home/ubuntu/Documents/gsoap/libserilalptz nano@tigerpuma.ddns.net:~/ngocnv_ws