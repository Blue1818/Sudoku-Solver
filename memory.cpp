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
#include "memory.h"


/// Allocate s bytes in the mem vector and initialize every byte/element to 0xa5.
memory::memory( uint32_t s )
{
    /// Implement the following rounding logic (before allocating the siz elements) to make the job
    /// of formatting and aligning your last line of output in your dump() method much, much easier:
    s = (s+15)&0xfffffff0; /// round the length up, mod-16
    ///allocate s bytes to 0xa5
    this->mem.resize(s, 0xa5);
}


///Return true if the given address addr does not represent an element that is present in the mem
///vector. (ie. Is there actually a byte at the given address or not?)
///If the given address is not within the range of valid addresses of the simulated memory then
///print a warning message to stdout formatted as:
/// WARNING: Address out of range: 0x00001000
///and return true.
///Obviously, formatting this warning message will involve using your hex::to_hex0x32() function.
bool memory::check_illegal ( uint32_t addr ) const
{
    bool flag = false;

    ///if addr is greater than the memory size
    if (addr >= mem.size())
    {
        ///then print the warning message and set flag to true.
        cout << "WARNING: Address out of range: " << hex::to_hex0x32(addr);
        cout << endl; ///remove later maybe?
        flag = true;
    }

    return flag;
}


///Return the (rounded up) number of bytes in the simulated memory.
uint32_t memory::get_size () const
{
    uint32_t size;
    size = mem.size();

    return size;
}


///Note that this is the only code that will ever read values from the mem vector.
uint8_t memory::get8 ( uint32_t addr ) const
{
    ///Check to see if the given addr is in your mem by calling check_illegal().
    if (check_illegal(addr))
    {
        ///If addr is not in the valid range then return zero to the caller.
        return 0;
    }

    ///If addr is in the valid range then return the value of the byte from your
    ///simulated memory at the given address. 
    return mem.at(addr);
}


///This function will call get8() and then return the 
///sign-extended value of the byte as a 32-bit signed integer.
int32_t memory::get8_sx ( uint32_t addr ) const
{
    ///this could get slimmed down maybe
    uint32_t uval = (get8(addr) * 0x1000000);
    int32_t val = uval;
    val >>= 24;
    return val;
}


///This function will call get16() and then return the sign-extended value
/// of the 16-bit value as a 32-bit signed integer.
int32_t memory::get16_sx ( uint32_t addr ) const
{
    ///this could get slimmed down maybe
    uint32_t uval = (get16(addr) * 0x10000);
    int32_t val = uval;
    val >>= 16;
    return val;
}


///Note that this, and the constructor, are the only code that will ever write values into the mem vector.
void memory::set8 (uint32_t addr, uint8_t val)
{
    ///This function will call check_illegal() to verify the addr argument is valid.
    if(check_illegal(addr))
    {
        ///If addr is not valid then discard the data and return to the caller.
        return;
    }

    ///If addr is valid then set the byte in the simulated memory at that address to the given val.
    mem.at(addr) = val;
}


///This function will call set8() twice to store the given val in little-endian order into the
///simulated memory starting at the address given in the addr argument.
void memory::set16 (uint32_t addr, uint16_t val)
{
    uint8_t byteVal;
    uint16_t LSB = val;
    ///put the Least Significant Byte in the first 8 bits of LSB.
    LSB <<= 8;  
    ///slide them back to the last 8 bits of LSB.
    LSB >>= 8;
    ///load LSB into byteVal
    byteVal = LSB;
    ///call set8() to load byteVal into address addr
    set8(addr, byteVal);
    ///put the Most Significant Byte in the last 8 bits of val.
    val >>= 8;
    ///load val into byteVal
    byteVal = val;
    ///call set8() to load byteVal into address addr+1
    set8((addr+1), byteVal);
}


///This function will call set16() twice to store the given val in little-endian order into the
///simulated memory starting at the address given in the addr argument.
void memory::set32 ( uint32_t addr , uint32_t val )
{
    uint16_t halfword;
    uint32_t LSB = val;
    ///put the Least Significant Bytes in the first 16 bits of LSB.
    LSB <<= 16;  
    ///slide them back to the last 16 bits of LSB.
    LSB >>= 16;
    ///load LSB into halfword
    halfword = LSB;
    ///call set16() to load halfword into address addr
    set16(addr, halfword);
    ///put the Most Significant Bytes in the last 16 bits of val.
    val >>= 16;  
    ///load val into halfword
    halfword = val;
    ///call set16() two load halfword into address addr+2
    set16((addr+2), halfword);
}









///Dump the entire contents of your simulated memory in hex with the corresponding ASCII2
///characters on the right exactly, space-for-space in the format shown in the output section below.
    /// 00000000: 68 65 6c 6c 6f 20 77 6f  72 6c 64 20 31 20 32 20 *hello world 1 2 *
    /// 00000010: 33 20 34 0a a5 a5 a5 a5  a5 a5 a5 a5 a5 a5 a5 a5 *3 4.............*
    /// 00000020: a5 a5 a5 a5 a5 a5 a5 a5  a5 a5 a5 a5 a5 a5 a5 a5 *................*
void memory::dump() const
{
    uint8_t ch; ///for ASCII2 characterse

    ///ok lets divid this up into 3 parts per a line, looping til you print each line of memory.
    ///make the counter addr and incrment it by 0x10 each cycle til we hit the end of memory.
    for (uint32_t addr = 0x00000000; addr < get_size(); addr += 0x00000010)
    {
        ///1: the address
        ///easy enough, just print addr.
        cout << hex::to_hex32(addr) << ':';

        ///2: each byte in the address, mirroring the spacing in the example below between the ::
        /// : a5 a5 a5 a5 a5 a5 a5 a5 :
        /// do this twice to get all 16 bytes
        /// use a for loop for each 8 byte segment
        for (uint32_t i = 0; i < 2; i++)
        {
            ///print a space
            cout << ' ';
            ///print 8 bytes with a space behind it.
            for (uint32_t addrB = (addr + (i * 0x00000008)); addrB < (addr + 0x08 + (i * 0x00000008)); addrB++)
            {
                cout << hex::to_hex8(get8(addrB)) << " ";
            }
        }
        
        ///3: the ASCII2 characters on the left.
        ///print inital *
        cout << '*';
        for (uint32_t addrB = addr; addrB < (addr + 0x00000010); addrB++)
        {
            ///In order to format the ASCII part of the dump lines, fetch a byte from the memory and then
            ///use isprint(3) to determine if you are to show an ASCII character or a dot (.) when the
            ///byte does not have a valid printable value.
            ch = get8(addrB);
            /// This code fragment will leave the character to be printed in the ASCII portion of the dump
            /// in the ch variable.
            ch = isprint(ch) ? ch : '.';
            ///print ch
            cout << ch;
        }
        ///print ending *
        cout << '*';

        ///print newline
        cout << endl;
    }
}


///Open the file named fname in binary mode and read its contents into your simulated memory
bool memory::load_file (const std::string &fname)
{
    uint8_t i;  ///for reading file contents.
;
    ///open file in binary
    std::ifstream infile(fname, std::ios::in|std::ios::binary);

    ///ok lets check this file to see if itsall good.
    ///check if file is open
    if (!infile.is_open())
    {
        ///If the file can not be opened,
        ///then print a suitable message to stderr including the name of the file and return false.
        cerr << "Can't open file '" << fname << "' for reading." << endl;
        return false;
    }
    ///check the file length
    ///loop one byte at a time and call check_illegal() then load the byte.
    ///you will want to set noskipws before reading from it
    infile >> std::noskipws;
    for (uint32_t addr = 0x00000000;  infile >> i; ++addr)
    {
        ///check if the address is legal
        if (check_illegal(addr))
        {
            ///if so print a error message to cerr and close.
            cerr << "Program too big." << endl;
            infile.close();
            return false;
        }

        ///assign i to memory at addr.
        set8(addr, i);
    }




    ///If the file loads OK then close the file and return true
    infile.close();
    return true;
}





