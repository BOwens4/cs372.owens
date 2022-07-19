// Braden Owens
// 6/22/2022
// Assignment 06
// The Tree Header File is attached to this project
template<typename T>
#include <iostream>
#include <algorithm>
#include <vector>
#include<memory.h>
#include <chrono>
#include "tree.h"
using namespace std;
struct Node { // struct for 3
	size_t num;
	vector<int> vector1();
	vector<int*> vector2();
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
int main()
{
	
}
