///***************************************************************************
///
///  Dale Westberg
///
///
///***************************************************************************
#include "sudokuSolver.h"

//default constructor
sudokuSolver::sudokuSolver()
{
    for(uint8_t y = 0x00; y < 0x09; y++)
    {
        for(uint8_t x = 0x00; x < 0x09; x++)
        {
            board[x][y] = 0x00;
        }
    }
}


//construct from file
//pretty basic
//uses old ss file structure:
//X6X1X4X5X
//XX83X56XX
//2XXXXXXX1
//8XX4X7XX6
//XX6XXX3XX
//7XX9X1XX4
//5XXXXXXX2
//XX72X69XX
//X4X5X8X7X
sudokuSolver::sudokuSolver(string fileName)
{
    memory mem(0x100);
    uint32_t head = 0x00000000;

    //load puzzle
    //if fail then show error
    if (!mem.load_file(fileName))
    {
        std::cerr << "can't load file";
        exit(1);
    }

    //nested for loop to loop through board
    for(uint8_t y = 0x00; y < 0x09; y++)
    {
        for(uint8_t x = 0x00; x < 0x09; x++)
        {

            board[x][y] = 0x00;
        }
    }


    
}




//check if value is legal: 0 <= val < 10
bool sudokuSolver::isLegal(uint8_t val)
{
    if ((0 <= val) && (val < 10))
    {
        return true;
    }
    //else return false
    return false;
}


//output board as a printimg in appropiate format
void sudokuSolver::printer()
{
    for(uint8_t y = 0; y < 10; y++)
    {
        for(uint8_t x = 0; x < 10; x++)
        {
            cout << getCell(x, y);

            if ((x == 2) || (x == 5))
            {
                cout << "|";
            }
        }


        //if y = 2 or y = 5 then print a horizontal line
        if ((y == 2) || (y == 5))
        {
            cout << endl << "---|---|---";
        }

        //newline
        cout << endl;
    }
}

//check if the value at the given coordinates is possible with the current board
bool sudokuSolver::possible(uint8_t x, uint8_t y, uint8_t n)
{
    return false;
}

//function to solve the puzzle from the current boardstate
void sudokuSolver::solver()
{

}
