#ifndef LIB_SERIAL_PTZ_H
#define LIB_SERIAL_PTZ_H

#include <libserial/SerialPort.h>
#include <iostream>


using namespace LibSerial;
class libserilalptz
{
private:
    /* data */
    SerialPort serial_port;
    char address;
    std::string serial_tty_port;
public:
    libserilalptz();
    libserilalptz(char address);
    libserilalptz(char address, std::string serial_tty_port);
    void init();
    void panLeft(char speed);
    void panRight(char speed);
    void tiltUp(char speed);
    void tiltDown(char speed);
    void stopAll();
    void resetToDefault();
    void setPanPosition(char msb_data, char lsb_data);
    void setTiltPosition(char msb_data, char lsb_data);
    void querryPanPosition();
    void querryTiltPosition();
    void returnPanPosition(char msb_data, char lsb_data);
    void returnTiltPosition(char msb_data, char lsb_data);
    void writeData(char Sync, char Address, char Command1, char Command2, char Data1, char Data2, char Checksum);

    char readByte(size_t msTimeout = 0);
    // void read(DataBuffer& dataBuffer, size_t numberOfBytes = 0, size_t msTimeout = 0);
    // void read(std::string& dataString, size_t numberOfBytes = 0, size_t msTimeout = 0);
    ~libserilalptz();
};

/*
address default is 0x01
serial_tty_port default is /dev/ttyUSB0
*/
libserilalptz::libserilalptz(/* args */)
{
    this->address = 0x01;
    this->serial_tty_port = "/dev/ttyUSB0";
    init();
}

libserilalptz::libserilalptz(char address)
{
    this->address = address;
    this->serial_tty_port = "/dev/ttyUSB0";
    init();
}

libserilalptz::libserilalptz(char address, std::string serial_tty_port)
{
    this->address = address;
    this->serial_tty_port = serial_tty_port;
    init();
}

void libserilalptz::init()
{
    try
    {
        // Open the Serial Ports at the desired hardware devices.
        this->serial_port.Open(serial_tty_port);
    }
    catch (const OpenFailed&)
    {
        std::cerr << "The serial ports did not open correctly." << std::endl;
        return;
    }

    // Set the baud rates.
    this->serial_port.SetBaudRate(BaudRate::BAUD_9600);

    // Set the number of data bits.
    this->serial_port.SetCharacterSize(CharacterSize::CHAR_SIZE_8);

    // Set the hardware flow control.
    this->serial_port.SetFlowControl(FlowControl::FLOW_CONTROL_NONE);

    // Set the parity.
    this->serial_port.SetParity(Parity::PARITY_NONE);
    
    // Set the number of stop bits.
    this->serial_port.SetStopBits(StopBits::STOP_BITS_1);
}

void libserilalptz::panLeft(char speed)
{
    // Write a single byte of data to the serial ports.
    char Sync = 0xFF;
    char Address = this->address;
    char Command1 = 0x00;
    char Command2 = 0x04;
    char Data1 = speed;
    char Data2 = 0x00;
    char Checksum = Address + Command1 + Command2 + Data1 + Data2;

    writeData(Sync, Address, Command1, Command2, Data1, Data2, Checksum);
}

void libserilalptz::panRight(char speed)
{
    // Write a single byte of data to the serial ports.
    char Sync = 0xFF;
    char Address = this->address;
    char Command1 = 0x00;
    char Command2 = 0x02;
    char Data1 = speed;
    char Data2 = 0x00;
    char Checksum = Address + Command1 + Command2 + Data1 + Data2;

    writeData(Sync, Address, Command1, Command2, Data1, Data2, Checksum);
}

void libserilalptz::tiltUp(char speed)
{
    // Write a single byte of data to the serial ports.
    char Sync = 0xFF;
    char Address = this->address;
    char Command1 = 0x00;
    char Command2 = 0x08;
    char Data1 = 0x00;
    char Data2 = speed;
    char Checksum = Address + Command1 + Command2 + Data1 + Data2;

    writeData(Sync, Address, Command1, Command2, Data1, Data2, Checksum);
}

void libserilalptz::tiltDown(char speed)
{
    // Write a single byte of data to the serial ports.
    char Sync = 0xFF;
    char Address = this->address;
    char Command1 = 0x00;
    char Command2 = 0x10;
    char Data1 = 0x00;
    char Data2 = speed;
    char Checksum = Address + Command1 + Command2 + Data1 + Data2;

    writeData(Sync, Address, Command1, Command2, Data1, Data2, Checksum);
}

void libserilalptz::stopAll()
{
    // Write a single byte of data to the serial ports.
    char Sync = 0xFF;
    char Address = this->address;
    char Command1 = 0x00;
    char Command2 = 0x00;
    char Data1 = 0x00;
    char Data2 = 0x00;
    char Checksum = Address + Command1 + Command2 + Data1 + Data2;

    writeData(Sync, Address, Command1, Command2, Data1, Data2, Checksum);
}

void libserilalptz::resetToDefault()
{
    // Write a single byte of data to the serial ports.
    char Sync = 0xFF;
    char Address = this->address;
    char Command1 = 0x00;
    char Command2 = 0x29;
    char Data1 = 0x00;
    char Data2 = 0x00;
    char Checksum = Address + Command1 + Command2 + Data1 + Data2;

    writeData(Sync, Address, Command1, Command2, Data1, Data2, Checksum);
}

void libserilalptz::setPanPosition(char msb_data, char lsb_data)
{
    // Write a single byte of data to the serial ports.
    char Sync = 0xFF;
    char Address = this->address;
    char Command1 = 0x00;
    char Command2 = 0x4B;
    char Data1 = msb_data;
    char Data2 = lsb_data;
    char Checksum = Address + Command1 + Command2 + Data1 + Data2;

    writeData(Sync, Address, Command1, Command2, Data1, Data2, Checksum);
}

void libserilalptz::setTiltPosition(char msb_data, char lsb_data)
{
    // Write a single byte of data to the serial ports.
    char Sync = 0xFF;
    char Address = this->address;
    char Command1 = 0x00;
    char Command2 = 0x4D;
    char Data1 = msb_data;
    char Data2 = lsb_data;
    char Checksum = Address + Command1 + Command2 + Data1 + Data2;

    writeData(Sync, Address, Command1, Command2, Data1, Data2, Checksum);
}

void libserilalptz::querryPanPosition()
{
    // Write a single byte of data to the serial ports.
    char Sync = 0xFF;
    char Address = this->address;
    char Command1 = 0x00;
    char Command2 = 0x51;
    char Data1 = 0x00;
    char Data2 = 0x00;
    char Checksum = Address + Command1 + Command2 + Data1 + Data2;

    writeData(Sync, Address, Command1, Command2, Data1, Data2, Checksum);
}

void libserilalptz::querryTiltPosition()
{
    // Write a single byte of data to the serial ports.
    char Sync = 0xFF;
    char Address = this->address;
    char Command1 = 0x00;
    char Command2 = 0x53;
    char Data1 = 0x00;
    char Data2 = 0x00;
    char Checksum = Address + Command1 + Command2 + Data1 + Data2;

    writeData(Sync, Address, Command1, Command2, Data1, Data2, Checksum);
}

void libserilalptz::returnPanPosition(char msb_data, char lsb_data)
{
    // Write a single byte of data to the serial ports.
    char Sync = 0xFF;
    char Address = this->address;
    char Command1 = 0x00;
    char Command2 = 0x59;
    char Data1 = msb_data;
    char Data2 = lsb_data;
    char Checksum = Address + Command1 + Command2 + Data1 + Data2;

    writeData(Sync, Address, Command1, Command2, Data1, Data2, Checksum);
}

void libserilalptz::returnTiltPosition(char msb_data, char lsb_data)
{
    // Write a single byte of data to the serial ports.
    char Sync = 0xFF;
    char Address = this->address;
    char Command1 = 0x00;
    char Command2 = 0x5B;
    char Data1 = msb_data;
    char Data2 = lsb_data;
    char Checksum = Address + Command1 + Command2 + Data1 + Data2;

    writeData(Sync, Address, Command1, Command2, Data1, Data2, Checksum);
}

void libserilalptz::writeData(char Sync, char Address, char Command1, char Command2, char Data1, char Data2, char Checksum)
{
    this->serial_port.WriteByte(Sync);
    this->serial_port.WriteByte(Address);
    this->serial_port.WriteByte(Command1);
    this->serial_port.WriteByte(Command2);
    this->serial_port.WriteByte(Data1);
    this->serial_port.WriteByte(Data2);
    this->serial_port.WriteByte(Checksum);
    // Wait until the data has actually been transmitted.
    this->serial_port.DrainWriteBuffer();
}

char libserilalptz::readByte(size_t msTimeout)
{
    char c;
    this->serial_port.ReadByte(c, msTimeout);
    return c;
    // try
    // {
    //     this->serial_port.ReadByte(c, msTimeout);
    //     return c;
    // }
    // catch(const ReadTimeout&)
    // {
    //     // std::cerr << "e.what()" << '\n';

    // }
    
    
}

// void libserilalptz::read(DataBuffer& dataBuffer, size_t numberOfBytes = 0, size_t msTimeout = 0)
// {
//     this->serial_port.Read(dataBuffer, numberOfBytes, msTimeout);
// }

// void libserilalptz::read(std::string& dataBuffer, size_t numberOfBytes = 0, size_t msTimeout = 0)
// {
//     this->serial_port.Read(dataBuffer, numberOfBytes, msTimeout);
// }


libserilalptz::~libserilalptz()
{
}



#endif  //#ifndef LIB_SERIAL_PTZ_H