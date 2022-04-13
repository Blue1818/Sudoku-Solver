//driver.cpp
//Dale Westberg (Bleu)

#include "sudokuSolver.h"


int main()
{

    memory mem(0x100);

    //memory before file
    //mem.dump();
    
    //load puzzle
    //if fail then show error
    if (!mem.load_file("samplePuzzles/exOld.ss"))
    {
        std::cerr << "can't load file";
    }



    //dump file
    mem.dump();






    return 0;
}