///***************************************************************************
///
///  Dale Westberg
///
///
///***************************************************************************
#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include <iostream>
#include <cstdint>  ///standard integer representations
#include <string>
#include "memory.h"

using std::string;
using std::cout;
using std::endl;

/* struct puzzle
{
    uint8_t cell[9][9];
}; */


class sudokuSolver
{
    private:
        uint8_t board[9][9]; //board state of the sudoku board
                             //1 - 9
                             //0 = blank
                             

    public:
        //default constructor
        sudokuSolver();

        //construct from file
        sudokuSolver(string fileName);

        //set each cell in board to 0xf5;
        void nullBoard();


        //getter
        uint8_t getCell(uint8_t x, uint8_t y)
        {
            return this->board[x][y];
        }

        //setter
        void setCell(uint8_t x, uint8_t y, uint8_t n)
        {
            this->board[x][y] = n;
        }

        //check if current board state is legal;
        bool isLegalBoard();

        //check if value is legal => 0 <= val < 10
        bool isLegal(uint8_t val);

        //output board as a printimg in appropiate format
        void printer();

        //check if the value at the given coordinates is possible with the current board
        bool possible(uint8_t x, uint8_t y, uint8_t n);

        //function to solve the puzzle from the current boardstate
        void solver();

        //check if value is in box
        bool possibleBox(uint32_t x, uint32_t y, uint32_t val)

};
   

#endif