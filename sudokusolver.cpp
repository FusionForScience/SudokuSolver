#include "sudokusolver.h"


SudokuSolver::SudokuSolver()
{
    _board = new char*[9];

    for(int i = 0; i < 9; i ++)
    {
        _board[i] = new char[9];
    }
}


SudokuSolver::~SudokuSolver()
{
    for(int i = 0; i < 9; i ++)
    {
        delete[] _board[i];
    }

    delete[] _board;
}


void SudokuSolver::setInput(std::string input)
{
    _inputString = input;


    int stringIndex = 0;

    for(int i = 0; i < 9; i ++)
    {
        for(int j = 0; j < 9; j ++)
        {
            _board[i][j] = _inputString[stringIndex];
            stringIndex ++;
        }
    }
}


void SudokuSolver::printBoard() const 
{
    std::cout << "-------------------------" << std::endl;
    for(int i = 0; i < 9; i ++)
    {
        for(int j = 0; j < 9; j ++)
        {
            if(j % 3 == 0)
            {
                std::cout << "| ";
            }
            std::cout << _board[i][j] << " ";
        }

        std::cout << "|" << std::endl;

        if((i + 1) % 3 ==0)
        {
            std::cout << "-------------------------" << std::endl;
        }
    }
}


void SudokuSolver::solve()
{
    if(_step(0 , 0))
    {
        std::cout << "Solution: " << std::endl;
        printBoard();
    }
    else
    {
        std::cout << "No solution" << std::endl;
    }
}


bool SudokuSolver::_step(const int row , const int col)
{
    char currentTry = '1';

    bool isEmpty = _board[row][col] == ' ';

    for(int i = 0; i < 9; i ++)
    {
        bool isValid = true;

        if(isEmpty)
        {
            _board[row][col] = currentTry;
        }

        isValid = isValid && _checkRows(row) && _checkColumns(col) && _checkSquares(row , col); 

        if(isValid || !isEmpty)
        {
            int newRow = row;
            int newCol = col + 1;

            if(newCol == 9)
            {
                newCol = 0;
                newRow = row + 1;
            }

            if(newRow == 9)
            {
                return isValid;
            }

            if(_step(newRow , newCol))
            {
                return true;
            }
            else
            {
                currentTry ++;
            }
            
            
        }
        else if(isEmpty)
        {
            currentTry ++;
        }
        
    }

    _board[row][col] = ' ';
    return false;
}



void SudokuSolver::_falsifyArray(bool array[9]) const
{
    for(int i = 0; i < 9; i ++)
    {
        array[i] = false;
    }
}


bool SudokuSolver::_checkRows(int rowNum) const
{
    bool exists[9];

    _falsifyArray(exists);

    for(int j = 0; j < 9; j ++)
    {
        char current = _board[rowNum][j];

        if(current == ' ')
        {
            continue;
        }
        
        if(exists[current - '1'] == false)
        {
            exists[current - '1'] = true;
        }
        else
        {
            return false;
        }
    }

    return true;
}


bool SudokuSolver::_checkColumns(int colNum) const
{
    bool exists[9];

    _falsifyArray(exists);

    for(int j = 0; j < 9; j ++)
    {
        char current = _board[j][colNum];
        
        if(current == ' ')
        {
            continue;
        }

        if(exists[current - '1'] == false)
        {
            exists[current - '1'] = true;
        }
        else
        {
            return false;
        }
    }

    return true;
}


bool SudokuSolver::_checkSquares(int rowNum , int colNum) const
{
    bool exists[9];

    _falsifyArray(exists);

    int squareRowIndex = (rowNum / 3) * 3;
    int squareColIndex = (colNum / 3) * 3;


    for(int row = 0; row < 3; row ++)
    {
        for(int col = 0; col < 3; col ++)
        {
            char current = _board[row + squareRowIndex][col + squareColIndex];

            if(current == ' ')
            {
                continue;
            }

            if(exists[current - '1'] == false)
            {
                exists[current - '1'] = true;
            }
            else
            {
                return false;
            }
        }
    }

}