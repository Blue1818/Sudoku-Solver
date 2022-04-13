//driver.cpp
//Dale Westberg (Bleu)

#include "memory.h"
#include "sudokuSolver.h"


int main()
{

    memory mem(0x1000);

    //memory before file
    mem.dump();
    
    //load puzzle
    //if fail then show error
    if (!mem.load_file("samplePuzzles/ARuud.sdk"))
    {
        std::cerr << "can't load file";
    }



    //dump file
    mem.dump();






    return 0;
}