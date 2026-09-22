#include "TowerOfHanoi.h"
#include <iostream>

using namespace std;

// Constructor
TowerOfHanoi::TowerOfHanoi()
{
    numberOfDisks = 0;
}

// Reset the game
void TowerOfHanoi::reset()
{
    pegA.clear();
    pegB.clear();
    pegC.clear();

    for (int i = numberOfDisks; i >= 1; i--)
    {
        pegA.push_back(i);
    }
}

// Return number of disks
int TowerOfHanoi::getNumberOfDisks() const
{
    return numberOfDisks;
}

// Set number of disks
void TowerOfHanoi::setNumberOfDisks(int n)
{
    numberOfDisks = n;
    reset();
}

// Return top disk from peg A
int TowerOfHanoi::getTopPegA() const
{
    if (pegA.empty())
    {
        return 0;
    }

    return pegA.back();
}

// Return top disk from peg B
int TowerOfHanoi::getTopPegB() const
{
    if (pegB.empty())
    {
        return 0;
    }

    return pegB.back();
}

// Return top disk from peg C
int TowerOfHanoi::getTopPegC() const
{
    if (pegC.empty())
    {
        return 0;
    }

    return pegC.back();
}

// Move disk from one peg to another
void TowerOfHanoi::moveDisk(char sourcePeg, char targetPeg)
{
    vector<int>* source = nullptr;
    vector<int>* target = nullptr;

    // Determine source peg
    if (sourcePeg == 'A' || sourcePeg == 'a')
    {
        source = &pegA;
    }
    else if (sourcePeg == 'B' || sourcePeg == 'b')
    {
        source = &pegB;
    }
    else if (sourcePeg == 'C' || sourcePeg == 'c')
    {
        source = &pegC;
    }

    // Determine target peg
    if (targetPeg == 'A' || targetPeg == 'a')
    {
        target = &pegA;
    }
    else if (targetPeg == 'B' || targetPeg == 'b')
    {
        target = &pegB;
    }
    else if (targetPeg == 'C' || targetPeg == 'c')
    {
        target = &pegC;
    }

    // Make sure both pegs are valid
    if (source == nullptr || target == nullptr)
    {
        return;
    }

    // Cannot move from an empty peg
    if (source->empty())
    {
        return;
    }

    int disk = source->back();

    // Cannot place a larger disk on a smaller disk
    if (!target->empty() && disk > target->back())
    {
        return;
    }

    source->pop_back();
    target->push_back(disk);
}

// Check if peg A is empty
bool TowerOfHanoi::isEmptyPegA() const
{
    return pegA.empty();
}

// Check if peg B is empty
bool TowerOfHanoi::isEmptyPegB() const
{
    return pegB.empty();
}

// Check if peg C is empty
bool TowerOfHanoi::isEmptyPegC() const
{
    return pegC.empty();
}

// Display all pegs
void TowerOfHanoi::displayPegs() const
{
    cout << "\n\tTower of Hanoi\n\n";

    // Go through each level from top to bottom
    for (int level = numberOfDisks - 1; level >= 0; level--)
    {
        cout << "\t";

        // PEG A
        if (level < pegA.size())
        {
            int disk = pegA[level];

            cout << string(numberOfDisks - disk, ' ');
            cout << string(disk, char(223));
            cout << disk;
            cout << string(disk, char(223));
            cout << string(numberOfDisks - disk, ' ');
        }
        else
        {
            cout << string(numberOfDisks, ' ');
            cout << char(186);
            cout << string(numberOfDisks, ' ');
        }

        cout << " ";

        // PEG B
        if (level < pegB.size())
        {
            int disk = pegB[level];

            cout << string(numberOfDisks - disk, ' ');
            cout << string(disk, char(223));
            cout << disk;
            cout << string(disk, char(223));
            cout << string(numberOfDisks - disk, ' ');
        }
        else
        {
            cout << string(numberOfDisks, ' ');
            cout << char(186);
            cout << string(numberOfDisks, ' ');
        }

        cout << " ";

        // PEG C
        if (level < pegC.size())
        {
            int disk = pegC[level];

            cout << string(numberOfDisks - disk, ' ');
            cout << string(disk, char(223));
            cout << disk;
            cout << string(disk, char(223));
            cout << string(numberOfDisks - disk, ' ');
        }
        else
        {
            cout << string(numberOfDisks, ' ');
            cout << char(186);
            cout << string(numberOfDisks, ' ');
        }

        cout << "\n";
    }

    // Bases
    cout << "\t";

    for (int peg = 0; peg < 3; peg++)
    {
        cout << string(numberOfDisks, char(205));
        cout << char(202);
        cout << string(numberOfDisks, char(205));

        if (peg < 2)
        {
            cout << " ";
        }
    }

    cout << "\n\t";

    // Peg letters
    cout << string(numberOfDisks, ' ') << "A";
    cout << string(numberOfDisks * 2 + 1, ' ');

    cout << string(numberOfDisks, ' ') << "B";
    cout << string(numberOfDisks * 2 + 1, ' ');

    cout << string(numberOfDisks, ' ') << "C";

    cout << "\n";
}