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
		(int*)malloc(stack_ > cap * sizeof(int));
	return stack;
}
void moveDisksBetweenTwoPoles(struct Stack* src, struct Stack* dest, char s, char d)
{
	int p1topdisk = pop(src);
	int p2topdisk = pop(dest);

	if (p1topdisk == int_min)
	{
		push(src, p2topdisk)
	}
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