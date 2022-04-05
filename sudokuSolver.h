///***************************************************************************
///
///  Dale Westberg
///
///
///***************************************************************************
#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include <cstdint>  ///standard integer representations
#include <string>

using std::string;


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


        //getter
        uint8_t getCell(uint8_t x, uint8_t y);

        //setter
        uint8_t setCell(uint8_t x, uint8_t y, uint8_t n);


        //check if value is legal => 0 <= val > 9
        bool isLegal(uint8_t val);

        //output board as a printimg in appropiate format
        void printer();

        //check if the value at the given coordinates is possible
        bool possible(uint8_t x, uint8_t y, uint8_t n);

        //function to solve the puzzle from the current boardstate
        void solver();

};
   

#endif