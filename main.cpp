#include <iostream>
#include <string>
#include "sudokusolver.h"


int main()
{   
    std::string sstring = "";
    std::string line;

    std::cout << "Enter sudoku string: " << std::endl;
    
    for (int i = 0; i < 9; i ++)
    {
        getline(std::cin , line);
        sstring += line;
    }


    std::cout << std::endl;

    SudokuSolver solver;

    solver.setInput(sstring);

    std::cout << "Unsolved puzzle:" << std::endl;

    solver.printBoard();
    
    std::cout << std::endl;

    solver.solve();

    return 0;
}