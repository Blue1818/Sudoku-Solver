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
    for(uint8_t x = 0x00; x < 0x09; x++)
    {
        for(uint8_t y = 0x00; y < 0x09; y++)
        {
            board[x][y] = 0x00;
        }
    }
}


//construct from file
sudokuSolver::sudokuSolver(string fileName)
{

}




//check if value is legal: 0 <= val < 10
bool isLegal(uint8_t val)
{
    if ((0 <= val) && (val < 10))
    {
        return true;
    }
    //else return false
    return false;
}


//output board as a printimg in appropiate format
void printer()
{

}

//check if the value at the given coordinates is possible with the current board
bool possible(uint8_t x, uint8_t y, uint8_t n)
{

}

//function to solve the puzzle from the current boardstate
void solver()
{

}
