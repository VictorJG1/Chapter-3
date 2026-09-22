#pragma once
#include <iostream>
#include <vector>
using namespace std;
class TowerOfHanoi
{
private:
	vector<int> pegA;
	vector<int> pegB;
	vector<int> pegC;

	int numberOfDisks;


public:
    // Constructor
    TowerOfHanoi();

    // Reset
    void reset();

    // Number of disks
    int getNumberOfDisks() const;
    void setNumberOfDisks(int n);

    // Get top disk of each peg
    int getTopPegA() const;
    int getTopPegB() const;
    int getTopPegC() const;

    // Move a disk
    void moveDisk(char sourcePeg, char targetPeg);

    // Check if pegs are empty
    bool isEmptyPegA() const;
    bool isEmptyPegB() const;
    bool isEmptyPegC() const;

    // Display pegs
    void displayPegs() const;

};

