#include "TicTacToe.h"

TicTacToe::TicTacToe()
{
	Reset();
}


void TicTacToe::Reset()
{
	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			Board[row][column] = ' ';
		}
	}
}


const char TicTacToe::GetCellValue(int Row, int Column)
{
    return Board[Row][Column];
}


void TicTacToe::SetCellValue(int Row, int Column, char Value)
{
    Board[Row][Column] = Value;
}


const bool TicTacToe::CheckIllegalMove(int Row, int Column)
{
    if (Board[Row][Column] != ' ')
    {
        return true;
    }

    return false;
}


void TicTacToe::ComputerMove()
{
    int row;
    int column;

    do
    {
        row = rand() % 3;
        column = rand() % 3;

    } while (CheckIllegalMove(row, column));

    SetCellValue(row, column, 'O');
}


const bool TicTacToe::CheckDrawGame()
{
    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            if (Board[row][column] == ' ')
            {
                return false;
            }
        }
    }

    return true;
}


const char TicTacToe::CheckWonByPlayer()
{
    // Check all 3 rows
    for (int row = 0; row < 3; row++)
    {
        if (Board[row][0] != ' ' && Board[row][0] == Board[row][1] && Board[row][1] == Board[row][2])
        {
            return Board[row][0];
        }
    }

    // Check all 3 columns
    for (int column = 0; column < 3; column++)
    {
        if (Board[0][column] != ' ' && Board[0][column] == Board[1][column] && Board[1][column] == Board[2][column])
        {
            return Board[0][column];
        }
    }

    // Check diagonal from top-left to bottom-right
    if (Board[0][0] != ' ' && Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2])
    {
        return Board[0][0];
    }

    // Check diagonal from top-right to bottom-left
    if (Board[0][2] != ' ' && Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0])
    {
        return Board[0][2];
    }

    // Nobody has won
    return ' ';
}






















//displays the board of TicTacToe
ostream& operator<<(ostream& out, TicTacToe& obj)
{
    out << "\n\t";
    out << "\n\t\tTic-Tac-Toe";

    out << "\n\t\t"<< char(201) << string(3, char(205))<< char(203) << string(3, char(205))<< char(203) << string(3, char(205))<< char(187);
    out << "\n\t\t"<< char(186) << " " << obj.Board[0][0] << " "<< char(186) << " " << obj.Board[0][1] << " "<< char(186) << " " << obj.Board[0][2] << " "<< char(186);
    out << "\n\t\t"<< char(204) << string(3, char(205))<< char(206) << string(3, char(205))<< char(206) << string(3, char(205))<< char(185);
    out << "\n\t\t"<< char(186) << " " << obj.Board[1][0] << " "<< char(186) << " " << obj.Board[1][1] << " "<< char(186) << " " << obj.Board[1][2] << " "<< char(186);
    out << "\n\t\t"<< char(204) << string(3, char(205))<< char(206) << string(3, char(205))<< char(206) << string(3, char(205))<< char(185);
    out << "\n\t\t"<< char(186) << " " << obj.Board[2][0] << " "<< char(186) << " " << obj.Board[2][1] << " "<< char(186) << " " << obj.Board[2][2] << " "<< char(186);
    out << "\n\t\t"<< char(200) << string(3, char(205))<< char(202) << string(3, char(205))<< char(202) << string(3, char(205))<< char(188);

    return out;
}