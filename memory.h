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
#ifndef MEMORY_H
#define MEMORY_H

#include "hex.h"
#include <vector>
#include <fstream>

using std::cerr;
using std::cout;
using std::endl;
using std::setfill;
using std::setw;
using std::string;
using std::cin;

class memory : public hex
{
    public :
/**
 * Constructor
 *
 * Creates a instance of the class and sizes the memory vector to the size
 * given as a argument, initalizing all elements to 0xa5.
 *
 * @param s desired size of for the memory vector.
 ********************************************************************************/
    memory( uint32_t s );
/**
 * Deconstructor
 *
 * In the destructor clean up anything necessary, so far nothing.
 ********************************************************************************/
    //~memory(); //uncomment later

/**
 * Checks to see if the address is legal.
 *
 * This function checks to see if there is a element in memory at that address.
 *
 * @param addr  Address that we are checking the legality of.
 *
 * @return a bool value that will be True if address isnt legal in memory and
 * will print a error message accordingly. 
 * If the address if legal then return false.
 ********************************************************************************/
    bool check_illegal ( uint32_t addr ) const ;

/**
 * Gets the size of the memory vector.
 *
 * @return the number of bytes in memory.
 ********************************************************************************/
    uint32_t get_size () const ;

/**
 * Gets the byte at the specified address.
 *
 * @param addr  Location in memory of the byte we want.
 *
 * @return The byte located in memory at address addr.
 * 
 * @note This is the only code that will ever read values from the mem vector.
 ********************************************************************************/
    uint8_t get8 ( uint32_t addr ) const ;

/**
 * Gets 2 bytes located at the specified address
 *
 * This function must call your get8() function twice to get two bytes and 
 * then combine them in little-endian order to create a 16-bit return value.
 * 
 * @param addr  Location in memory of the bytes we want.
 *
 * @return The 2 byte located in memory at address address a 16-bit val.
 ********************************************************************************/
    uint16_t get16 ( uint32_t addr ) const { return (get8(addr) + (get8(addr+1) * 0x100)); }

/**
 * Gets 4 bytes located at the specified address
 *
 * This function must call get16() function twice and combine the results in little-endian order
 * similar to the implementation of get16().
 * 
 * @param addr  Location in memory of the bytes we want.
 *
 * @return The 2 byte located in memory at address address a 32-bit val.
 ********************************************************************************/
    uint32_t get32 ( uint32_t addr ) const { return (get16(addr) + (get16(addr+2) * 0x10000)); }

/**
 * Gets the byte at the specified address and turn it into sign extended 32 bit value.
 * 
 * This function calls get8() then sign extend the value into a 32-bit signed integer.
 *
 * @param addr  Location in memory of the byte we want.
 *
 * @return the sign extended value of the byte, put into a 32-bit signed value.
 ********************************************************************************/
    int32_t get8_sx ( uint32_t addr ) const ;

/**
 * Gets 2 bytes located at the specified address and turns them into 32-bit signed values
 *
 * This function calls get16() then sign extends the 16-bit value into a 32-bit signed integer.
 * 
 * @param addr  Location in memory of the bytes we want.
 *
 * @return The sign extended value of the 16-bit val in memory at addr as a 32-bit signed integer.
 ********************************************************************************/
    int32_t get16_sx ( uint32_t addr ) const ;
    
/**
 * Turn the 4 bytes at the specified address into a signed 32-bit integer
 *
 * This function will call get32() and then return the value as a 32-bit signed integer.
 * 
 * @param addr  Location in memory of the bytes we want.
 *
 * @return the 4 bytes as a 32-bit signed integer.
 ********************************************************************************/
    int32_t get32_sx ( uint32_t addr ) const { return get32(addr); }


/**
 * Load a byte into memory at the specified address.
 * 
 * Checks if the address is legal then writes val into the mem
 * vector at addr.
 * 
 * @param addr  Location in memory that we want to load our val to.
 * @param val   Byte that we want to store in memory.
 * 
 * @note This and the constructor are the only code that will ever
 * write values into the mem vector.
 ********************************************************************************/
    void set8 ( uint32_t addr , uint8_t val );

/**
 * Load 2 bytes into memory at the specified address.
 * 
 * @param addr  Location in memory that we want to load our val to.
 * @param val   Bytes that we want to store in memory.
 ********************************************************************************/
    void set16 ( uint32_t addr , uint16_t val );

/**
 * Load 4 bytes into memory at the specified address.
 * 
 * This function will call set8() twice to store the given val in little-endian order
 * into the simulated memory starting at the address given in the addr argument.
 * 
 * @param addr  Location in memory that we want to load our val to.
 * @param val   Bytes that we want to store in memory.
 ********************************************************************************/
    void set32 ( uint32_t addr , uint32_t val );


/**
 * Dump the entire contents of your simulated memory in hex with the corresponding ASCII2
 * 
 * When printing these characters, it must be exactly match the sample output space-for-space.
 * ex: "00000010: 33 20 34 0a a5 a5 a5 a5  a5 a5 a5 a5 a5 a5 a5 a5 *3 4.............*"
 ********************************************************************************/
    void dump () const ;


/**
 * Open a file and load it's contents into memory.
 * 
 * Checks if the file is open, 
 * then reads the file byte-by-byte,
 * checking if the address is legal,
 * then loading it into memory,
 * then closing the program and returning true.
 * 
 * @param addr  Location in memory that we want to load our val to.
 * @param val   Bytes that we want to store in memory.
 * 
 * @return False: The program prints the appropriate error message.
 *         True: Loading of file is successful.
 ********************************************************************************/
    bool load_file ( const std :: string & fname );

    private :
    std :: vector < uint8_t > mem;


};
   

#endif