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
    uint8_t val = 0x00;

    //load puzzle
    //if fail then show error
    if (!mem.load_file(fileName))
    {
        std::cerr << "can't load file";
        exit(1);
    }

    //null the board
    nullBoard();

    //nested for loop to loop through board
    for(uint8_t y = 0x00; y < 0x09; y++)
    {
        for(uint8_t x = 0x00; x < 0x09; x++)
        {
            //get byte at address and assign it to val
            val = mem.get8(head);

            //decode val into 0-9;
            switch( val )
            {
                //1 - 9
                case 0x31: setCell(x, y , 0x01);
                break;
                
                case 0x32: setCell(x, y , 0x02);
                break;

                case 0x33: setCell(x, y , 0x03);
                break;

                case 0x34: setCell(x, y , 0x04);
                break;

                case 0x35: setCell(x, y , 0x05);
                break;

                case 0x36: setCell(x, y , 0x06);
                break;

                case 0x37: setCell(x, y , 0x07);
                break;

                case 0x38: setCell(x, y , 0x08);
                break;

                case 0x39: setCell(x, y , 0x09);
                break;


                //its a X, turn it into a 0
                case 0x58: setCell(x, y , 0x00);
                break;

                default: 
                    break;
            }

            //incrment head
            head++;
        }
        //newline, incrment head twice
        head += 0x00000002;
    }

    //check boardstate
    //if false then print error and exit 1
    if (!isLegalBoard())
    {
        std::cerr << "error: board not legal";
        exit(1);
    }
    
}


//set each cell to 0xf5
void sudokuSolver::nullBoard()
{
    for(uint8_t y = 0x00; y < 0x09; y++)
    {
        for(uint8_t x = 0x00; x < 0x09; x++)
        {
            setCell(x, y, 0xf5);
        }
    }
}


//check boardstate
bool sudokuSolver::isLegalBoard()
{
    for(uint8_t y = 0x00; y < 0x09; y++)
    {
        for(uint8_t x = 0x00; x < 0x09; x++)
        {
            if (!isLegal(getCell(x, y)))
            {
                return false;
            }
        }
    }

    return true;
}


//check if value is legal: 0 <= val < 10
bool sudokuSolver::isLegal(uint8_t val)
{
    if ((0x00 <= val) && (val < 0x0c))
    {
        return true;
    }
    //else return false
    return false;
}


//output board as a printimg in appropiate format
void sudokuSolver::printer()
{
    for(uint8_t y = 0; y < 9; y++)
    {
        for(uint8_t x = 0; x < 9; x++)
        {
            //print cell, cast as a uint32_t
            cout << (uint32_t)getCell(x, y);

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
