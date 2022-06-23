// Braden Owens
// 6/22/2022
// Assignment 05
// This program will show the recursive and iterative solutions to the towers of Hanoi problem, and test them

#include <iostream>
#include <chrono>
using namespace std;
void moveDisksrecur(int, int, int, int);
void moveDisksiter(int, int, int, int);
int main()
{
	const int NUMDISKS = 5;
	const int FROMPEG = 1;
	const int TOPEG = 3;
	const int TEMPPEG = 2;
	auto start = std::chrono::steady_clock::now();
	moveDisksrecur(NUMDISKS, FROMPEG, TOPEG, TEMPPEG);
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	cout << "All the pegs are moved recursively, with a time of " << elapsed_seconds.count() << "s"<< endl;
}
void moveDisksrecur(int num, int fromPeg, int toPeg, int tempPeg)
{
	if (num > 0)
	{
		moveDisksrecur(num - 1, fromPeg, tempPeg, toPeg);
		cout << "Move a disk from peg " << fromPeg
			<< " to peg " << toPeg << endl;
		moveDisksrecur(num - 1, tempPeg, toPeg, fromPeg);
	}
}
void moveDisksiter