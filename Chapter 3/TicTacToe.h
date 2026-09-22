#pragma once
#include <iostream>
using namespace std;
class TicTacToe
{
private:
	char Board[3][3];

public:
	TicTacToe();

	void Reset();

	const bool CheckDrawGame();	
	const char CheckWonByPlayer();
	const bool CheckIllegalMove(int row, int column);

	void SetCellValue(int Row, int Column, char Value);
	const char GetCellValue(int Row, int Column);

	void ComputerMove();
	void DisplayBoard();

	friend ostream& operator << (ostream& out, TicTacToe& obj);
};

