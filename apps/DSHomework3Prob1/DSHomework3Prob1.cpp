// Homework 3 Problem 1 Data Structures
// Braden Owens
// 6/12/2022
// 
# include <iostream>
#include <iomanip>
# include <string>
# include <fstream>
# include "tasks.txt"
# include "list.h"
# include "vector.h"
using namespace std;

// The thing i struggled with most in this program is the act of marking things as done due to having to skip a couple characters in the file to get to the U or D. 
// I tried to implement it the only way i know how, but it is still not correct. I am not sure what I am missing.

int main()
{
	// open files for reading/ writing
	ifstream infile;
	ofstream ofile;
	infile.open("tasks.txt");
	ofile.open("tasks.txt");


	int decisionforswitch = 0;
	int userin = 0;
	int linecounter = 0;
	int userin2 = 0;
	string tasks;
	string taskslist;

	//vector and list
	vector<string>tasks;
	list<string>taskslist;
	cout << "Welcome to the Data Structures Task Manager Mr. Owens!" << endl;
	cout << "This application allows you to track the tasks on your homework, because your grades make it evident you need it." << endl;

	// switch to display the menu
	while (decisionforswitch != 4) 
	{
		cout << "Please consider the menu, and make a selection based on the action you wish the task manager to execute!" << endl;
		cout << "--------------------------------------------------------------------------------------------------------" << endl;
		cout << "Option 1: Display All Tasks." << endl;
		cout << "Option 2: Display A Task of your choice." << endl;
		cout << "Option 3: Mark a specific task as done." << endl;
		cout << "Option 4: Exit Task Manager"
		cout << "--------------------------------------------------------------------------------------------------------" << endl;
		//push the contents of the file into a vector for printing, and a list for manipulation
		while (getline(infile, tasks))
		{
			linecounter++;
			tasks.push_back()
		}
		while (getline(infile, taskslist))
		{
			linecounter++;
			taskslist.push_back();
		}
		int lengthtasks = tasks.length;
		switch (decisionforswitch) {
		case 1:
			cout << "You have selected to display all tasks!" << endl;
			cout << "The following list below includes all tasks to complete for this assignment" << endl;
			cout << " There are " << lengthtasks() << " task(s) in the task manager" << endl;
			if (infile.is_open())
			{ 
				while (infile)
				{
					tasks.traverse(); //traverses the vector and prints to the screen
					cout << endl;
				}
			else
			{
				cout << "The file is empty, you are done with your homework!" << endl;
				cout << "At the next menu prompt, please enter a 4 to exit." << endl;
			}
			break;
		case 2:
			cout << "You have selected to display a selected task!" << endl;
			cout << "Please enter the number of the task you wish to view" << endl;
			cin >> userin;
			cout << tasks[userin]; //displays the line of the task the user wishes to see from vector
			break;
		case 3:
			//This is the biggest issue i faced was trying to figure out how to implement this case correctly
			cout << "You have selected to mark a task as done!" << endl;
			cout << "Please enter the number of the task you would like to mark as done!" << endl;
			cin >> userin2;
			//code here to change the U to a D? This is the part I cant wrap my head around
			taskslist.pop_back(userin2); //pop it off the list before sending to the file
			break;
		case 4: 
			cout << "You have selected to exit the program." << endl;
			vector<string>finished(taskslist.begin(), taskslist.end()); // copy the list to a vector for printing
			while (ofile)
			{
				ofile >> finished;//prints the vector to the file
				ofile >> endl;
			}
			break;
		default:
			cout << "You have chosen a value that is not in the the menu. Please try again." << endl;
			break;
		}
	}
	cout << "Thank you for using the task manager!" << endl;
	cout << "Have a great day!" << endl;
	infile.close("tasks.txt");
	ofile.close("tasks.txt");
	return 0;
}