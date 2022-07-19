// Braden Owens
// 6/22/2022
// Assignment 06
// The Tree Header File is attached to this project
// I had a lot of trouble understanding the second half of this assignment. I got the structure of the tree from the lecture 
// and understand how it works but am having trouble understanding the semantics of the comparisons in the last question.
template<typename T>
#include <iostream>
#include <algorithm>
#include <vector>
#include<memory.h>
#include<list>
#include <chrono>
#include "tree.h"
using namespace std;
struct Node { // struct for 3
	size_t num;
	vector<int*> vector1();
	Tree<T> *x = new Tree<T>();
};
bool binarySearch(vector<T> &vector1, T search)
{
	int upBound = vector1.size();
	int midPoint=0;
	int lowBound = 0;
	while (true)
	{
		midPoint = lowBound + (upBound - lowBound) / 2;
		if (upBound < lowBound)
		{
			return false;
		}
		if (vector1[midPoint] == search)
			return true;
		if (vector1[midPoint] < search)
			lowBound = midPoint + 1;
		if (vector1[midPoint] > search)
			lowBound = midPoint - 1;
	}
}
void fillsortinsert(vector<T>& vector1, int num, Tree<T>* y)
{
	//this fills the vector with random numbers
	int counter = 0;
	while (counter < num) {
		vector1.push_back(rand());
		counter++;
	}
	// this sorts
	sort(vector1);
	//insert to tree
	for (int i = 0; i < vector1.size(); i++) {
		y->insert(vector1[i]);
	}
}

int main(vector<T>& vector1)
{
	int size = 0;
	double temp = 0;
	list<int> sizes = { 1000,2500,5000,10000,50000};
	auto start = chrono::steady_clock::now();
	auto end = chrono::steady_clock::now();
	cout << "This program will compare the execution time of binary search vs. lookup times in a BST." << endl;
	cout << "We will do this comparison with vectors of 1000, 2500, 5000, 10,000, and 50,000 elements." << endl;
	for (auto size : sizes)
	{
		vector1<int>(size);
		for (int i = 0; i < 100; i++)
		{
			vector<int>(rand());
		}
		start = chrono::steady_clock::now();

	}
}
// This is where I dont understand. I understood that we should use the same sort of method as the big oh assignment to loop through all the
//lookup times, but implementing the code I have to work with inserting to the tree and comparing that to just traditonal binary search isnt clear to me