// Braden Owens
// 6/22/2022
// Assignment 05
// This program will show the recursive and iterative solutions to the towers of Hanoi problem, and test them
#include <chrono>
#include <iostream>

using namespace std;
void moveDisksrecur(int, char, char, char);
// code for iterative soln to work.

struct Stack
{
	int top;
	int* arr;
	unsigned cap;
};


struct Stack* create(unsigned cap)
{
	struct Stack* stack =
		(struct Stack*)malloc(sizeof(struct Stack));
	stack->cap = cap;
	stack->top = -1;
	stack->arr =
		(int*)malloc(stack-> cap * sizeof(int));
	return stack;
}

// helper functions needed for iterative soln
int empty(struct Stack* stack)
{
	return(stack->top == -1);
}


int pop(struct Stack* stack)
{
	if (empty(stack))
		return INT_MIN;
	return stack->arr[stack->top--];
}

void push(struct Stack* stack, int item)
{
	if (full(stack))
		return;
	stack-> arr[++stack->top] = item;
}

int full(struct Stack* stack)
{
	return (stack->top == stack->cap-1)
}

void moveDisk(char fromPeg, char toPeg, int disk)
{
	cout << "Move disk" << disk << "from" << fromPeg << "to" << toPeg << endl;
}

void movediskstwo(struct Stack* src, struct Stack* dest, char a, char b )
{
	int p1tdisk = pop(src);
	int p2tdisk = pop(dest);

	if (p1tdisk == INT_MIN)
	{
		push(src, p2tdisk);
		moveDisk(b, a, p2tdisk);
	}
	else if (p2tdisk == INT_MIN)
	{
		push(dest, p1tdisk);
		moveDisk(a, b, p1tdisk);
	}
	else if (p1tdisk > p2tdisk)
	{
		push(src, p1tdisk);
		push(src, p2tdisk);
		moveDisk(b, a, p2tdisk);
	}
	else
	{
		push(dest, p2tdisk);
		push(dest, p1tdisk);
		moveDisk(a, b, p1tdisk);
	}
}
// the final function that ties helper functions together, and moves the disks iteratively


void movedisksiterative(int diskcount1, struct Stack* src, struct Stack* aux, struct Stack* dest) {
	// local vars
	int totalmoves;
	int iterator;
	char s = '', d = 'Y', a = 'Z';



	if (diskcount1 % 2 == 0) {
		char temp = d;
		d = a;
		a = temp;
	}
	totalmoves = pow(2, diskcount1) - 1;

	for (iterator = diskcount1; iterator >= 1; i--) {
		push(src, i);
	}

	for (iterator = 1; i <= totalmoves; i++) {
		if (iterator % 3 == 1) {
			movediskstwo(src, dest, s, d);
		}

		else if (iterator % 3 == 2) {
			movediskstwo(src, aux, s, a);
		}

		else if (iterator % 3 == 0) {
			movediskstwo(aux, dest, a, d);
		}
	}
}

int main()
{
	int dec = 0;
	int disks = 0;
	cout << "Please select whether you would like to do solve the Towers of Hanoi Problem recursively, iteratively, or exit the menu!" << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout << "1. Solve Iteratively" << endl;
	cout << "2. Solve Recursively" << endl;
	cout << "3. Exit" << endl;
	cin >> dec;
	switch (dec)
	{
	case 1:
		cout << "You have chosen the Iterative method!" << endl;
		cout << "Please enter the number of disks you wish to solve the towers of Hanoi for." << endl;
		cin >> disks;
		auto start = chrono::steady_clock::now();
		A = create(disks);
		B = create(disks);
		C = create(disks);
		movedisksiterative(disks, A, B, C);
		auto end = chrono::steady_clock::now();
		cout << endl;
		break;

	case 2:
		cout << "You have chosen the Recursive method!" << endl;
		cout << "Please enter the number of disks you wish to solve the towers of Hanoi for." << endl;
		cin >> disks;
		auto start = chrono::steady_clock::now();
		movedisksiterative(disks, 'A', 'B', 'C');
		auto end = chrono::steady_clock::now();
		cout << endl;
		break;
	case 3:
		cout << "Thanks for using this towers of Hanoi program!" << endl;
		return 1;
	default:
		cout << "try another number, you have made an invalid selection" << endl;
		break;

	}

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