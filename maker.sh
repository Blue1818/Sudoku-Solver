#!/bin/bash
# make script for unit tests


#g++ -g -ansi -pedantic -Wall -Werror -std=c++14 -c -o memory.o memPackage/memory.cpp
#g++ -g -ansi -pedantic -Wall -Werror -std=c++14 -c -o hex.o memPackage/hex.cpp
g++ -g -ansi -pedantic -Wall -Werror -std=c++14 -c -o hex.o hex.cpp
g++ -g -ansi -pedantic -Wall -Werror -std=c++14 -c -o memory.o memory.cpp

g++ -g -ansi -pedantic -Wall -Werror -std=c++14 -c -o sudokuSolver.o sudokuSolver.cpp

g++ -g -ansi -pedantic -Wall -Werror -std=c++14 -c -o driver.o driver.cpp

g++ -g -ansi -pedantic -Wall -Werror -std=c++14 -o sudokuSolver driver.o sudokuSolver.o memory.o hex.o


# remove o files
rm -f *.o hex.o
rm -f *.o driver.o
rm -f *.o memory.o
rm -f *.o sudokuSolver.o