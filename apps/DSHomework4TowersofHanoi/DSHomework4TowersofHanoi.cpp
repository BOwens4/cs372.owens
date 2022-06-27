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

int full(struct Stack* stack)
{
	return (stack->top == stack->cap - 1);
}

void push(struct Stack* stack, int item)
{
	if (full(stack))
		return;
	stack->arr[++stack->top] = item;
}

void move(char fromPeg, char toPeg, int disk)
{
	cout << "Move disk" << disk << "from" << fromPeg << "to" << toPeg << endl;
}

void movetwo(struct Stack* src, struct Stack* dest, char s, char d )
{
	int p1tdisk = pop(src);
	int p2tdisk = pop(dest);

	if (p1tdisk == INT_MIN)
	{
		push(src, p2tdisk);
		move(d, s, p2tdisk);
	}
	else if (p2tdisk == INT_MIN)
	{
		push(dest, p1tdisk);
		move(s, d, p1tdisk);
	}
	else if (p1tdisk > p2tdisk)
	{
		push(src, p1tdisk);
		push(src, p2tdisk);
		move(d, s, p2tdisk);
	}
	else
	{
		push(dest, p2tdisk);
		push(dest, p1tdisk);
		move(s, d, p1tdisk);
	}
}
// the final function that ties helper functions together, and moves the disks iteratively


void movedisksiterative(int diskc, struct Stack* src, struct Stack* aux, struct Stack* dest) {
	// local vars
	int totalmoves;
	int iterator;
	char s = 'S', d = 'D', a = 'A';



	if (diskc % 2 == 0) {
		char temp = d;
		d = a;
		a = temp;
	}
	totalmoves = pow(2, diskc) - 1;

	for (iterator = diskc; iterator >= 1; iterator--) {
		push(src, iterator);
	}

	for (iterator = 1; iterator <= totalmoves; iterator++) {
		if (iterator % 3 == 1) {
			movetwo(src, dest, s, d);
		}

		else if (iterator % 3 == 2) {
			movetwo(src, aux, s, a);
		}

		else if (iterator % 3 == 0) {
			movetwo(aux, dest, a, d);
		}
	}
}

int main()
{
	int dec = 0;
	int disks = 0;
	struct Stack* A, * C, * B;
	cout << "Please select whether you would like to do solve the Towers of Hanoi Problem recursively, iteratively, or exit the menu!" << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout << "1. Solve Iteratively" << endl;
	cout << "2. Solve Recursively" << endl;
	cout << "3. Exit" << endl;
	cin >> dec;
	auto start = chrono::steady_clock::now();
	auto end = chrono::steady_clock::now();
	while (dec != 3)
	{
		switch (dec)
		{
		case 1:
			cout << "You have chosen the Iterative method!" << endl;
			cout << "Please enter the number of disks you wish to solve the towers of Hanoi for." << endl;
			cin >> disks;
			start = chrono::steady_clock::now();
			A = create(disks);
			B = create(disks);
			C = create(disks);
			movedisksiterative(disks, A, B, C);
			cout << endl;
			break;

		case 2:
			cout << "You have chosen the Recursive method!" << endl;
			cout << "Please enter the number of disks you wish to solve the towers of Hanoi for." << endl;
			cin >> disks;
			start = chrono::steady_clock::now();
			moveDisksrecur(disks, 'A', 'B', 'C');
			cout << endl;
			break;
		case 3:
			cout << "Thanks for using this towers of Hanoi program!" << endl;
			break;
		default:
			cout << "Try another number, you have made an invalid selection" << endl;
			break;

		}
		end = chrono::steady_clock::now();
		chrono::duration<double>elapsed_seconds = end - start;
		cout << "This took:" << endl;
		cout << elapsed_seconds.count() << endl;
		cout << "Please make another selection" << endl;
		cin >> dec;
	}
	return 0;
}
void moveDisksrecur(int disks, char A, char B, char C)
{
	if (disks == 1)
	{
		cout << "Move disk number " << disks << "from " << A << "to " << C << endl;
		return;
	}
	moveDisksrecur(disks - 1, A, C, B);
	cout << "Move disk number " << disks << "from " << A << "to " << C << endl;
	moveDisksrecur(disks - 1, B, A, C);
}