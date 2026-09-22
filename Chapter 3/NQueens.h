#pragma once
#include <iostream>
#include <vector>

using namespace std;

class NQueens
{
private:
    vector<vector<int>> board;
    int size;
    int numberOfExistingQueens;

public:
    // Constructor
    NQueens(int n);

    // Get board size
    int getSize() const;

    // Place a queen
    void setQueen(int r, int c);

    // Remove a queen
    void eraseQueen(int r, int c);

    // Check if a queen exists at a cell
    bool checkQueenCell(int r, int c) const;

    // Check if puzzle is solved
    bool solved() const;

    // Check conflicts
    int conflict(int r, int c) const;

    // Display board
    void displayBoard() const;
};
	
