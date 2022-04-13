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
// params: (all int)
//         x: x-cordinate 1-9
//         y: y-cordinate 1-9
//         n: value 1-9 to check the legality of
// returns:
//         bool value
//             True: n is a possible value
//             False: n is not a possible value
bool sudokuSolver::possible(uint8_t x, uint8_t y, uint8_t n)
{
// instructions:
//     loop through each int in row x and check if they are equal to n
//         if they are equal return False
    for(uint8_t i = 0; i < 9; i++)
    {
        if(getCell(i, y) == n)
        {
            return false;
        }
    }

//     loop through each int in colum y and check if they are equal to not
//         if they are equal return False
    for(uint8_t i = 0; i < 9; i++)
    {
        if(getCell(x, i) == n)
        {
            return false;
        }
    }

//     check each int in the square the x,y int is located
//         if any are equal return False
//     if non of the above conditions are met, return true
    return possibleBox(x, y, val);
}

//function to solve the puzzle from the current boardstate
void sudokuSolver::solver()
{
    char a;
// instructions:
// loop x from 0 to 8 inclusively
    for(uint8_t x = 0; x < 9; x++)
    {
        //     loop y from 0 to 8 inclusively
        for(uint8_t y = 0; y < 9; y++)
        {
            //if board[x][y] = 0 then
            if (getCell(x, y) == 0)
            {
                // loop i from 1 to 9 inclusively
                for(uint8_t i = 1; i <= 9; i++)
                {
                    //                 if possible(x,y,i) returns true
                    if (possible(x,y,i))
                    {
                        //                     set board[x][y] = i
                        setCell(x,y,i);
                        //                     call solver() recursively
                        solver();
                        //                     if solver returns then backtrack by setting board[x][y] = 0
                        setCell(x,y,0x00);
                    }
                }
                //             if you loop through all then return
                return;
            }
        }
    }

// if you loop though all possiblies then the puzzles is solved
// call printer() to print the board
    printer();
// ask the user if they want to keep going
    cout << "would you like to keep going?" << endl;
    std::cin >> a;
    if (a = 'n') exit(2);

}


bool sudokuSolver::possibleBox(uint32_t x, uint32_t y, uint32_t val)
{
    //find the corner of box:
    uint8_t startx = x - (x % 3);
    uint8_t starty = y - (y % 3);

    //compare val to each cell in that 3x3 box
    for(uint8_t j = starty; j < (starty + 3); j++)
    i
        for(uint8_t i = startx; i < (startx + 3); i++)
        {
            if (getCell(i, j) = val)
            {
                //if equal return false
                return false;
            }
        }
    }

    //return true
    return true;
}