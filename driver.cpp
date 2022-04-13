//driver.cpp
//Dale Westberg (Bleu)

#include "sudokuSolver.h"


int main()
{
    sudokuSolver node("samplePuzzles/exOld.ss");
    
    /* 
    //manual print
    for(uint8_t y = 0x00; y < 0x09; y++)
    {
        for(uint8_t x = 0x00; x < 0x09; x++)
        {
            cout << (uint32_t)node.getCell(x, y);
        }
        
        cout << endl;
    }
    cout << endl; */

    node.printer();

    





    return 0;
}