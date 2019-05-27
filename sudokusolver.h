#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include <iostream>
#include <string>


class SudokuSolver
{
public:
    SudokuSolver();

    ~SudokuSolver();

    void setInput(std::string input);

    void printBoard() const;

    void solve();


private:
    std::string _inputString;
    char** _board;

    bool _step(const int row , const int col);

    void _falsifyArray(bool array[9]) const;

    bool _checkRows(int rowNum) const;

    bool _checkColumns(int colNum) const;
    
    bool _checkSquares(int rowNum , int colNum) const;
};


#endif