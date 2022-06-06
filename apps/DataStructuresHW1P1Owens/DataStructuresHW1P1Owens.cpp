// Homework 1 Problem 1 Data Structures
// Braden Owens
// 5/23/2022

#include <iostream>
#include <string>
using namespace std;
string p = " ";
//Problem 1 Part A
void problem1PartAfun()
{
	cout << "---------------------------------------" << endl;
	cout << "Part A:" << endl;
	const int size = 25;
	int* arrayPtr;
	arrayPtr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arrayPtr[i];
	}
	int* arrayPtr2;
	arrayPtr2 = arrayPtr;
	delete[]arrayPtr;
	for (int i = 0; i < 10; i++)
	{
		cout<<arrayPtr2[i]<<" "<<endl;
	}

}
//Problem 1 Part B
void problem1PartBfun()
{
	cout << "---------------------------------------" << endl;
	cout << "Part B:" << endl;
	const int size = 25;
	int* arrayPtr;
	arrayPtr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arrayPtr[i];
	}
	int* arrayPtr2;
	arrayPtr2 = arrayPtr;
	delete arrayPtr;
	cout << "The address of Pointer2 is: " << &arrayPtr2 << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << arrayPtr2[i] << " " << endl;
	}

}


//Problem 1 Part C
string pointertoStr1()

{ 
	cout << "---------------------------------------" << endl;
	cout << "Part C:" << endl;
	string str = " ";
	string* p;
	p = new string("abcdefghijkl");
	return *p;

}

void pointertoStr2()
{
	string str =p;
	cout << str << endl;
}


int main()
{
	problem1PartAfun();
	problem1PartBfun();
	pointertoStr1();
	pointertoStr2();
}