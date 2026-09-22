#include "NQueens.h"
using namespace std;

// Constructor
NQueens::NQueens(int n)
{
    size = n;
    numberOfExistingQueens = 0;

    board.resize(size);

    for (int r = 0; r < size; r++)
    {
        board[r].resize(size, 0);
    }
}


// Return board size
int NQueens::getSize() const
{
    return size;
}


// Place a queen
void NQueens::setQueen(int r, int c)
{
    if (r >= 0 && r < size && c >= 0 && c < size)
    {
        if (board[r][c] == 0)
        {
            board[r][c] = 1;
            numberOfExistingQueens++;
        }
    }
}


// Remove a queen
void NQueens::eraseQueen(int r, int c)
{
    if (r >= 0 && r < size && c >= 0 && c < size)
    {
        if (board[r][c] == 1)
        {
            board[r][c] = 0;
            numberOfExistingQueens--;
        }
    }
}


// Check if a queen exists at a location
bool NQueens::checkQueenCell(int r, int c) const
{
    if (r >= 0 && r < size && c >= 0 && c < size)
    {
        return board[r][c] == 1;
    }

    return false;
}


// Check if the puzzle is solved
bool NQueens::solved() const
{
    if (numberOfExistingQueens != size)
    {
        return false;
    }

    // Check every queen for conflicts
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            if (board[r][c] == 1)
            {
                if (conflict(r, c) > 0)
                {
                    return false;
                }
            }
        }
    }

    return true;
}


// Check how many queens conflict with this position
int NQueens::conflict(int r, int c) const
{
    // Check same row
    for (int column = 0; column < size; column++)
    {
        if (column != c && board[r][column] == 1)
        {
            return 1;
        }
    }

    // Check same column
    for (int row = 0; row < size; row++)
    {
        if (row != r && board[row][c] == 1)
        {
            return 2;
        }
    }

    // Check upper-left diagonal
    for (int row = r - 1, column = c - 1;row >= 0 && column >= 0;row--, column--)
    {
        if (board[row][column] == 1)
        {
            return 3;
        }
    }

    // Check upper-right diagonal
    for (int row = r - 1, column = c + 1;row >= 0 && column < size;row--, column++)
    {
        if (board[row][column] == 1)
        {
            return 3;
        }
    }

    // Check lower-left diagonal
    for (int row = r + 1, column = c - 1;row < size && column >= 0;row++, column--)
    {
        if (board[row][column] == 1)
        {
            return 3;
        }
    }

    // Check lower-right diagonal
    for (int row = r + 1, column = c + 1;row < size && column < size;row++, column++)
    {
        if (board[row][column] == 1)
        {
            return 3;
        }
    }

    // No conflict
    return 0;
}


// Display the board
void NQueens::displayBoard() const
{
    cout << "\n\t" << size << "-Queens";

    // Top of board
    cout << "\n\t";
    cout << char(201);

    for (int c = 0; c < (size * 2) - 1; c++)
    {
        cout << char(205);
    }

    cout << char(187);


    // Board
    for (int r = 0; r < size; r++)
    {
        cout << "\n\t";
        cout << char(186);

        for (int c = 0; c < size; c++)
        {
            // Display queen
            if (board[r][c] == 1)
            {
                cout << "Q";
            }
            else
            {
                // Last row uses spaces
                if (r == size - 1)
                {
                    cout << " ";
                }
                else
                {
                    cout << "_";
                }
            }

            // Vertical divider between cells
            if (c < size - 1)
            {
                cout << char(179);
            }
        }

        cout << char(186);
    }


    // Bottom of board
    cout << "\n\t";
    cout << char(200);

    for (int c = 0; c < (size * 2) - 1; c++)
    {
        cout << char(205);
    }

    cout << char(188);

    cout << "\n";
}