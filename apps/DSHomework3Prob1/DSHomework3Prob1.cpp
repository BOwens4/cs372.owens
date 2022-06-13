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
		cout << "Please consider the menu, and make a selection based on the action you wish the task manager to execute!" << endl;
		cout << "--------------------------------------------------------------------------------------------------------" << endl;
		cout << "Option 1: Display All Tasks." << endl;
		cout << "Option 2: Display A Task of your choice." << endl;
		cout << "Option 3: Mark a specific task as done." << endl;
		cout << "Option 4: "
		cout << "--------------------------------------------------------------------------------------------------------" << endl;

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
	}
	cout << "Thank you for using the task manager!" << endl;
	cout << "Have a great day!" << endl;
	infile.close("tasks.txt");
	return 0;
}