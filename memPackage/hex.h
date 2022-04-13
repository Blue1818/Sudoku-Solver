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
#ifndef HEX_H
#define HEX_H


#include <string>
#include <cstdint>  ///standard integer representations
#include <iostream>
#include <iomanip>
#include <cstdlib>  ///for abs()
#include <unistd.h>
#include <ctype.h>


class hex
{
    public:
/**
 * Turn a 8-bit value to 2 hex digits in a string.
 * 
 * @param i a std::string with exactly 2 hex digits representing the 8 bits of
 * the i argument.
 *
 * @return a std::string with exactly 2 hex digits representing the 8 bits of
 * the i argument.
 ********************************************************************************/
    static std::string to_hex8 ( uint8_t i );

/**
 * Format a 32-bit number to hex digits in a sting.
 *
 * @param i 32-bit unsigned integer
 *
 * @return a std::string with 8 hex digits representing the 32 bits of
 * the i argument.
 ********************************************************************************/
    static std::string to_hex32 ( uint32_t i );

/**
 * Format a 32-bit number to hex digits in 0x format
 * 
 * Similar to to_hex32 but it has 0x appended by the return value of
 * to_hex32 after calling it.
 *
 * @param i 32-bit unsigned integer
 *
 * @return a std::string with 0x followed by a 8 hex digits representing
 * the 32 bits of the i argument.
 ********************************************************************************/
    static std::string to_hex0x32 ( uint32_t i );



    ///NEW FUNCTIONS:

/**
 * Returns a string beginning with 0x, ammended the hex notation of the
 * 20 Least Significant bits if i.
 *
 * @param i the 32 bit int that we want to represent.
 *
 * @return a string with 0x appened by i's 5 least significant hex bytes
 ********************************************************************************/
    static std::string to_hex0x20(uint32_t i);

/**
 * Returns a string beginning with 0x, ammended the hex notation of the
 * 12 Least Significant bits if i.
 *
 * @param i the 32 bit int that we want to represent.
 *
 * @return a string with 0x appened by i's 3 least significant hex bytes
 ********************************************************************************/
    static std::string to_hex0x12(uint32_t i);




};


#endif