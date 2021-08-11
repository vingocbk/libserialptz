#include <iostream>
#include "libserilalptz.h"

#define MAX_SPEED   0x3F

libserilalptz libserilalptz;

void querry_Pan_Position(){
    std::cout << "querryPanPosition" << std::endl;
    // libserilalptz libserilalptz;
    libserilalptz.querryPanPosition();
    char datares[7];
    bool start = false;
    int count = 0;
    for(unsigned int i = 0; i < 50; i++)
    {
        try
        {
            // Read a single byte of data from the serial ports.
            char c = libserilalptz.readByte(10);
            if(c == 0xFF){
                start = true;
            }
            if(start)
            {
                datares[count] = c;
                std::cout << "byte " << count << ": ";
                std::cout << std::hex << (int)datares[count] << std::endl;
                count++;
                if(count == 7)
                {
                    break;
                }
            }
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
    char datares[7];
    bool start = false;
    int count = 0;
    for(unsigned int i = 0; i < 50; i++)
    {
        try
        {
            // Read a single byte of data from the serial ports.
            char c = libserilalptz.readByte(10);
            if(c == 0xFF){
                start = true;
            }
            if(start)
            {
                datares[count] = c;
                std::cout << "byte " << count << ": ";
                std::cout << std::hex << (int)datares[count] << std::endl;
                count++;
                if(count == 7)
                {
                    break;
                }
            }
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
}
void pan_Left(){
    std::cout << "panLeft" << std::endl;
    // libserilalptz libserilalptz;
    libserilalptz.panLeft(MAX_SPEED);
}

void pan_Right(){
    std::cout << "panRight" << std::endl;
    // libserilalptz libserilalptz;
    libserilalptz.panRight(MAX_SPEED);
}

void tilt_Up(){
    std::cout << "tiltUp" << std::endl;
    // libserilalptz libserilalptz;
    libserilalptz.tiltUp(MAX_SPEED);
}

void tile_Down(){
    std::cout << "tiltDown" << std::endl;
    // libserilalptz libserilalptz;
    libserilalptz.tiltDown(MAX_SPEED);
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
// rsync -a -e "ssh -p 1222" /home/ubuntu/Documents/gsoap/libserialptz nano@tigerpuma.ddns.net:~/ngocnv_ws