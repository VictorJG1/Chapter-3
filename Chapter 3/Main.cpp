//Victor Garcia
//09/14/26
//Chapter 3

#include<iostream>
#include<ctime>
#include<string>
#include"input.h"
#include<iomanip>
#include<cstdlib>
#include"TicTacToe.h"
#include"TowerOfHanoi.h"
#include"NQueens.h"

using namespace std;

// Function prototypes
char menuOption();
char TicTacToeGame();
char TowerOfHanoiGame();
char NQueensGame();
char PlayAgain();

// Objects
TicTacToe test;
TowerOfHanoi trial;


int main()
{
    srand(time(0));

    do
    {
        switch (menuOption())
        {
        case 1:
        {
            TicTacToeGame();
            break;
        }

        case 2:
        {
            TowerOfHanoiGame();
            break;
        }

        case 3:
        {
            NQueensGame();
            break;
        }

        case 'X':
        {
            exit(1);
        }
        }

        cout << "\n";
        system("pause");

    } while (true);

    return EXIT_SUCCESS;
}


// Introduction to main menu
char menuOption()
{
    system("cls");

    cout << "\n\tCMPR131 Chapter 3 - Games Applications using Container by Victor Garcia (9/24/2026)";
    cout << "\n\t" << string(80, char(205));
    cout << "\n\t\t1> Tic-Tac-Toe";
    cout << "\n\t\t2> Tower of Hanoi";
    cout << "\n\t\t3> n-Queens";
    cout << "\n\t" << string(80, char(196));
    cout << "\n\t\tX. Exit";
    cout << "\n\t" << string(80, char(205));

    char option = toupper(inputChar("\n\tOption: ",static_cast<string>("123x")));

    switch (option)
    {
    case '1':
    {
        return 1;
    }

    case '2':
    {
        return 2;
    }

    case '3':
    {
        return 3;
    }

    case 'X':
    {
        exit(1);
    }

    default:
    {
        return option;
    }
    }
}


// Play again
char PlayAgain()
{
    return toupper(inputChar("\n\tPlay again? (Y-yes or N-no): ",static_cast<string>("yn")));
}


// Tic-Tac-Toe
char TicTacToeGame()
{
    system("cls");

    cout << "\n\tTic-tac-toe (also known as Noughts and crosses or Xs and Os) is a game for two";
    cout << "\n\tplayers, X and O, who take turns marking the spaces in a 3"<< string(1, char(215))<< "3 grid. The player who";
    cout << "\n\tsucceeds in placing three of their marks in a horizontal, vertical, or diagonal";
    cout << "\n\trow wins the game.";
    cout << "\n\tThis tic-tac-toe program plays against the computer. Human player, X, will always be";
    cout << "\n\tfirst. Time will be recorded for the fastest and the slowest game. Average time will ";
    cout << "\n\tthen be calculated and displayed. ";
    cout << "\n";

    // STATISTICS
    int gamesPlayed = 0;
    int totalTime = 0;

    int fastestTime = 0;
    int fastestMoves = 0;

    int slowestTime = 0;
    int slowestMoves = 0;

    char again;

    // PLAY AGAIN LOOP
    do
    {
        cout << "\n\tGame begins... ";

        test.Reset();

        int row;
        int column;
        int moves = 0;

        bool gameOver = false;

        // Start timer
        time_t startTime = time(0);

        // MAIN GAME LOOP
        do
        {
            cout << test;

            // HUMAN MOVE
            cout << "\n\tHUMAN moves...";

            do
            {
                row = inputInteger("\n\tEnter the board's row # (1..3) or 0 to forfeit: ",0,3);

                // Forfeit
                if (row == 0)
                {
                    cout << "\n\tYou forfeited the game. Therefore, Dumb AI has won.\n";

                    gameOver = true;
                    break;
                }

                column = inputInteger("\n\tEnter the board's column # (1..3) or 0 to forfeit: ",0,3);

                // Forfeit
                if (column == 0)
                {
                    cout << "\n\tYou forfeited the game. Therefore, Dumb AI has won.\n";

                    gameOver = true;
                    break;
                }

                // Convert 1..3 to 0..2
                row--;
                column--;

                // Check illegal move
                if (test.CheckIllegalMove(row, column))
                {
                    cout << "\n\tERROR: Illegal move. The square is already occupied. Please re-specify.\n";
                }

            } while (test.CheckIllegalMove(row, column));

            // Check if human forfeited
            if (gameOver)
            {
                break;
            }

            // Place X
            test.SetCellValue(row, column, 'X');

            moves++;

            cout << test;

            // CHECK IF HUMAN WON
            if (test.CheckWonByPlayer() == 'X')
            {
                cout << "\n\tHUMAN player has won.\n";

                gameOver = true;
                break;
            }

            // CHECK FOR DRAW
            if (test.CheckDrawGame())
            {
                cout << "\n\tThe game ended in a draw.\n";

                gameOver = true;
                break;
            }

            // COMPUTER MOVE
            cout << "\n\tDumb AI moves...";

            test.ComputerMove();

            moves++;

            cout << test;

            // CHECK IF COMPUTER WON
            if (test.CheckWonByPlayer() == 'O')
            {
                cout << "\n\tDumb AI has won the game.\n";

                gameOver = true;
                break;
            }

            // CHECK FOR DRAW
            if (test.CheckDrawGame())
            {
                cout << "\n\tThe game ended in a draw.\n";

                gameOver = true;
                break;
            }

            cout << "\n";

            system("pause");

        } while (!gameOver);

        // STOP TIMER
        time_t endTime = time(0);

        int gameTime =static_cast<int>(difftime(endTime, startTime));

        // UPDATE STATISTICS
        gamesPlayed++;

        totalTime += gameTime;

        // First game is both fastest and slowest
        if (gamesPlayed == 1)
        {
            fastestTime = gameTime;
            slowestTime = gameTime;

            fastestMoves = moves;
            slowestMoves = moves;
        }
        else
        {
            // Fastest game
            if (gameTime < fastestTime)
            {
                fastestTime = gameTime;
                fastestMoves = moves;
            }

            // Slowest game
            if (gameTime > slowestTime)
            {
                slowestTime = gameTime;
                slowestMoves = moves;
            }
        }

        // PLAY AGAIN
        again = PlayAgain();

        if (again == 'Y')
        {
            system("cls");
        }

    } while (again == 'Y');

    // CALCULATE AVERAGE TIME
    double averageTime =static_cast<double>(totalTime) / gamesPlayed;

    // DISPLAY GAME STATISTICS
    cout << "\n\tGame statistics:";
    cout << "\n";

    if (gamesPlayed == 1)
    {
        cout << "\n\t1 game using of Tic-Tac-Toe were played.";
    }
    else
    {
        cout << "\n\t"<< gamesPlayed<< " games using of Tic-Tac-Toe were played.";
    }

    cout << "\n\t\tThe fastest time was "<< fastestTime<< " seconds in "<< fastestMoves<< " moves.";

    cout << "\n\t\tThe slowest time was "<< slowestTime<< " seconds in "<< slowestMoves<< " moves.";

    cout << "\n\t\tThe average time was "<< averageTime<< " second(s).";

    cout << "\n";

    return 0;
}


// Tower of Hanoi
char TowerOfHanoiGame()
{
    system("cls");

    cout << "\n\tThe Tower of Hanoi also called the Tower of Brahma or Lucas' Tower is a mathematical game.";
    cout << "\n\tIt consists of three pegs and a number of rings of different sizes, which can slide onto";
    cout << "\n\tany peg. The game starts with the rings in a neat stack in ascending order of size on one";
    cout << "\n\tpeg, the smallest at the top, thus making a conical shape.";
    cout << "\n\t";
    cout << "\n\tThe objective of the game is to move the entire stack from the starting peg-A to ending peg-C,";
    cout << "\n\tobeying the following simple rules:";
    cout << "\n";
    cout << "\n\t\t1. Only one disk can be moved at a time.";
    cout << "\n\t\t2. Each move consists of taking the upper disk from one of the stacks and";
    cout << "\n\t\t   placing it on top of another stack or on an empty peg.";
    cout << "\n\t\t3. No larger disk may be placed on top of a smaller disk.";
    cout << "\n\n";

    char again;

    do
    {
        int disks = inputInteger("\n\tEnter the number of rings (1..64) to begin: ",1,64);

        // Set up game
        trial.setNumberOfDisks(disks);

        int moves = 0;

        char sourcePeg = ' ';
        char targetPeg = ' ';

        // GAME LOOP
        do
        {
            system("cls");

            trial.displayPegs();

            // Check if all disks have been moved to peg C
            if (trial.isEmptyPegA() &&trial.isEmptyPegB())
            {
                cout << "\n\tCongratulations! You completed the Tower of Hanoi.";
                cout << "\n\tYou completed the tower in "<< moves<< " move(s).";
                cout << "\n";

                break;
            }

            // Get source peg
            sourcePeg = toupper(inputChar("\n\tSelect the top disk from the start peg (A, B, C, or Q-quit): ",static_cast<string>("abcq")));

            // Quit current game
            if (sourcePeg == 'Q')
            {
                break;
            }

            // Check if source peg is empty
            if ((sourcePeg == 'A' && trial.isEmptyPegA()) ||(sourcePeg == 'B' && trial.isEmptyPegB()) ||(sourcePeg == 'C' && trial.isEmptyPegC()))
            {
                cout << "\n\tERROR: The selected peg is empty.";
                cout << "\n";
                system("pause");
                continue;
            }

            // Get target peg
            targetPeg = toupper(inputChar("\n\tSelect the end peg (A, B, C or Q-quit) to move the selected disk: ",static_cast<string>("abcq")));

            if (targetPeg == 'Q')
            {
                sourcePeg = 'Q';

                break;
            }

            // Cannot move to same peg
            if (sourcePeg == targetPeg)
            {
                cout << "\n\tERROR: The start peg and destination peg cannot be the same.";
                cout << "\n";
                system("pause");
                continue;
            }

            // Check if move is legal
            int sourceDisk = 0;
            int targetDisk = 0;

            if (sourcePeg == 'A')
            {
                sourceDisk = trial.getTopPegA();
            }
            else if (sourcePeg == 'B')
            {
                sourceDisk = trial.getTopPegB();
            }
            else if (sourcePeg == 'C')
            {
                sourceDisk = trial.getTopPegC();
            }

            if (targetPeg == 'A')
            {
                targetDisk = trial.getTopPegA();
            }
            else if (targetPeg == 'B')
            {
                targetDisk = trial.getTopPegB();
            }
            else if (targetPeg == 'C')
            {
                targetDisk = trial.getTopPegC();
            }

            // Cannot place larger disk on smaller disk
            if (targetDisk != 0 &&sourceDisk > targetDisk)
            {
                cout << "\n\tERROR: A larger disk cannot be placed on top of a smaller disk.";
                cout << "\n";
                system("pause");
                continue;
            }

            // Perform move
            trial.moveDisk(sourcePeg, targetPeg);

            // Count successful move
            moves++;

        } while (true);

        // Player quit
        if (sourcePeg == 'Q')
        {
            cout << "\n\tYou quit the current game.";
            cout << "\n\tYou made "<< moves<< " move(s).";
        }

        // Play again
        again = PlayAgain();

    } while (again == 'Y');

    return 0;
}


// N-Queens
char NQueensGame()
{
    system("cls");

    cout << "\n\tThe n-queens puzzle is the problem of placing n chess queens on a n"<< char(215)<< "n chessboard";
    cout << "\n\tso that no two queens threaten each other; thus, a solution requires that no two";
    cout << "\n\tqueens share the same row, column, or diagonal. Solutions exist for all natural";
    cout << "\n\tnumbers n with the exception of n = 2 and n = 3.";
    cout << "\n";

    char again;

    // PLAY AGAIN LOOP
    do
    {
        int dimension = inputInteger("\n\tEnter the board dimension nxn: ",1,50);

        // Create board
        NQueens subject(dimension);

        // Count successful moves
        int moves = 0;

        char option;

        // GAME LOOP
        do
        {
            system("cls");

            subject.displayBoard();

            cout << "\n";

            cout << "\n\tGame Options";
            cout << "\n\t" << string(50, char(205));
            cout << "\n\tA> Place a queen";
            cout << "\n\tB> Remove an existing queen";
            cout << "\n\t" << string(50, char(196));
            cout << "\n\t0> return";
            cout << "\n\t" << string(50, char(205));

            option = toupper(inputChar("\n\tOption: ",static_cast<string>("ab0")));

            switch (option)
            {
            case 'A':
            {
                int row;
                int column;

                row = inputInteger("\n\tPosition a queen in the row (1.." +to_string(subject.getSize()) +"): ",1,subject.getSize());
                column = inputInteger("\n\tPosition a queen in the colume (1.." +to_string(subject.getSize()) +"): ",1,subject.getSize());

                // Convert 1..n to 0..n-1
                row--;
                column--;

                // Check if queen already exists
                if (subject.checkQueenCell(row, column))
                {
                    cout << "\n\tERROR: a queen has already placed in the position "<< "(row and colume). Try again.";
                    cout << "\n";

                    system("pause");

                    break;
                }

                // Check conflict
                int conflicts =subject.conflict(row, column);

                // Row conflict
                if (conflicts == 1)
                {
                    cout << "\n\tERROR: conflict with queens in existing row.Try again.";
                    cout << "\n";

                    system("pause");

                    break;
                }

                // Column conflict
                if (conflicts == 2)
                {
                    cout << "\n\tERROR: conflict with queens in existing colume.Try again.";
                    cout << "\n";

                    system("pause");

                    break;
                }

                // Diagonal conflict
                if (conflicts == 3)
                {
                    cout << "\n\tERROR: conflict with queens in existing diagnol.Try again.";
                    cout << "\n";

                    system("pause");

                    break;
                }

                // No conflict, place queen
                subject.setQueen(row, column);

                // Count successful move
                moves++;

                // Check if puzzle is solved
                if (subject.solved())
                {
                    system("cls");

                    subject.displayBoard();

                    cout << "\n\tCongratulation! You have solved "<< subject.getSize()<< "-Queens in "<< moves;

                    if (moves == 1)
                    {
                        cout << " move.";
                    }
                    else
                    {
                        cout << " moves.";
                    }

                    cout << "\n";
                }

                break;
            }

            case 'B':
            {
                int row;
                int column;

                row = inputInteger("\n\tEnter an existing queen from the row (1.." +to_string(subject.getSize()) +"): ",1,subject.getSize());
                column = inputInteger("\n\tEnter an existing queen from the colume (1.." +to_string(subject.getSize()) +"): ",1,subject.getSize());

                // Convert 1..n to 0..n-1
                row--;
                column--;

                // Check if queen exists
                if (!subject.checkQueenCell(row, column))
                {
                    cout << "\n\tERROR: No such queen existed.";
                    cout << "\n";

                    system("pause");

                    break;
                }

                // Remove queen
                subject.eraseQueen(row, column);

                // Count successful move
                moves++;

                break;
            }

            case '0':
            {
                return 0;
            }
            }

            // Leave game loop when solved
            if (subject.solved())
            {
                break;
            }

        } while (true);

        // PLAY AGAIN
        again = PlayAgain();

    } while (again == 'Y');

    return 0;
}