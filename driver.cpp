//driver.cpp
//Dale Westberg (Bleu)

#include "sudokuSolver.h"


int main()
{
    string fileName = "samplePuzzles/";
    string input = "";

    cout << "Name of the file with the puzzle: ";
    cin >> input;

    fileName.append(input);

    sudokuSolver node(fileName);
    
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
    
    cout << endl << "Before:" << endl;
    node.printer();
    cout << endl << "After:" << endl;
    node.solver();
    node.printer();
    
    //number of recursive calls
    cout << endl << "And it only took " << "XXX" << "Calls." << endl;





    return 0;
}