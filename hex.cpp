///***************************************************************************
///
///  Dale Westberg
///  z1910234
///  CSCI 463 - 1
///
///  I certify that this is my own work and where appropriate an extension 
///  of the starter code provided for the assignment.
///
///***************************************************************************
#include "hex.h"


///This function must return a std::string with exactly 2 hex digits representing the 8 bits of
///the i argument
std::string hex::to_hex8 ( uint8_t i )
{
    std::ostringstream os;
    os << std::hex << std::setfill('0') << std::setw(2) << static_cast<uint16_t>(i);
    return os.str();
}

/// This function must return a std::string with 8 hex digits representing the 32 bits of the i
/// argument.
std::string hex::to_hex32 ( uint32_t i )
{
    std::ostringstream os;
    os << std::hex << std::setfill('0') << std::setw(8) << i;
    return os.str();
}


/// This function must return a std::string beginning with 0x, followed by the 8 hex digits
/// representing the 32 bits of the i argument. It must be implemented by creating a string by
/// concatenating a 0x to the output of to_hex32() like this:
std::string hex::to_hex0x32 ( uint32_t i )
{
    return std::string("0x")+to_hex32(i);
}


///This function must return a std::string beginning with 0x, followed by the 5 hex digits
///representing the 20 least significant bits of the i argument. Implement this method in a
///similar fashion as hex::to_hex8() but without the static_cast.
///This new method will be used when formatting the lui and auipc instructions.
std::string hex::to_hex0x20(uint32_t i)
{
    ///da string stream
    std::ostringstream os;

    ///get rid of the 12 most significant bits of i
    i <<= 12;
    i >>= 12;

    ///load i into os with setw = 5
    os << std::hex << std::setfill('0') << std::setw(5) << i;

    ///return "0x" appended with os
    return std::string("0x")+os.str();
}



///This function must return a std::string beginning with 0x, followed by the 3 hex digits
///representing the 12 least significant bits of the i argument. See to_hex0x20().
///This new method will be used when formatting the csrrX() instructions.
std::string hex::to_hex0x12(uint32_t i)
{
    ///da string stream
    std::ostringstream os;

    ///get rid of the 20 most significant bits of i
    i <<= 20;
    i >>= 20;

    ///load i into os with setw = 3
    os << std::hex << std::setfill('0') << std::setw(3) << i;

    ///return "0x" appended with os
    return std::string("0x")+os.str();
}





