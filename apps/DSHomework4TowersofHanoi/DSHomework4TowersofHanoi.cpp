// Braden Owens
// 6/22/2022
// Assignment 05
// This program will show the recursive and iterative solutions to the towers of Hanoi problem, and test them

#include <iostream>
#include <chrono>

using namespace std;
void moveDisksrecur(int, int, int, int);
//void moveDisksiter(int, int, int, int);
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
	if (isFull(stack))
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
void moveDisksBetweenTwoPoles(struct Stack* src, struct Stack* dest, char s, char d)
{
	int p1topdisk = pop(src);
	int p2topdisk = pop(dest);

	if (p1topdisk == INT_MIN)
	{
		push(src, p2topdisk);
		moveDisk(d, s, p2topdisk);
	}
	else if (p2topdisk == INT_MIN)
	{
		push(dest, p1topdisk);
		moveDisk(s, d, p1topdisk);
	}
	else if (p1topdisk > p2topdisk)
	{
		push(src, p1topdisk);
		push(src, p2topdisk);
		moveDisk(d, s, p2topdisk);
	}
	else
	{
		push(dest, p2topdisk);
		push(dest, p1topdisk);
		moveDisk(s, d, p1topdisk);
	}
}
void movedisksiterative(int num_of_disks, struct Stack* src, struct Stack* aux, struct Stack* dest) {
	int total_num_of_moves;
	int i;
	char s = 'X', d = 'Y', a = 'Z';

	if (num_of_disks % 2 == 0) {
		char temp = d;
		d = a;
		a = temp;
	}
	total_num_of_moves = pow(2, num_of_disks) - 1;

	for (i = num_of_disks; i >= 1; i--) {
		push(src, i);
	}

	for (i = 1; i <= total_num_of_moves; i++) {
		if (i % 3 == 1) {
			moveDisksBetweenTwoPoles(src, dest, s, d);
		}

		else if (i % 3 == 2) {
			moveDisksBetweenTwoPoles(src, aux, s, a);
		}

		else if (i % 3 == 0) {
			moveDisksBetweenTwoPoles(aux, dest, a, d);
		}
	}
}

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
//void moveDisksiter