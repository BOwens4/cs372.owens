// Homework 3 Problem 1 Data Structures
// Braden Owens
// 6/12/2022
// 
# include "list.h"
# include "queue.h"
# include "vector.h"
# include <iostream>
# include <string>
# include "tasks.txt"
# include <fstream>
using namespace std;


int main()
{
	ifstream infile("tasks.txt");
	infile.open("tasks.txt");
	int decision = 0;
	cout << "Welcome to the Data Structures Task Manager Mr. Owens!" << endl;
	cout << "This application allows you to track the tasks on your homework, because your grades make it evident you need it." << endl;


	while (decision != 4) 
	{
		cout<<
		switch (decision) {
		case 1:
			cout << "You have selected to display all tasks!" << endl;
			cout << "The following list below includes all tasks to complete for this assignment, whether done or undone." << endl;
			break;
		case 2: 
			cout << "You have selected to display a selected task!" << endl;
			cout << "Please enter the name of the task you wish to view" << endl;
			break;
		case 3: 
			cout << "You have selected to mark a task as done!" << endl;
			break;
	}

		infile.close("tasks.txt");
}