// Braden Owens
// 6/27/2022
// Midterm Data Structures
// Problem 2
#include <iostream>
#include <stack>
using namespace std;
void checkparen();
int main()
{
	checkparen();
	return 0;
}
void checkparen()
{
	stack<char> temp;
	string userin;
	int check = 0;
	cout << "Enter the string you would like to check for matching parentheses" << endl;
	cin >> userin;
	for (int count = 0; count < userin.length(); count++)
	{
		if (userin[count] == '{' || userin[count] == '[' || userin[count] == '(')
		{
			temp.push(userin[count]);
			check = 1;
		}
		if (!temp.empty())
		{
			if (userin[count] == '}')
			{
				if (temp.top() == '{')
				{
					temp.pop();
					continue;
				}
				else
					break;
			}
			if (userin[count] == ']')
			{
				if (temp.top() == '[')
				{
					temp.pop();
					continue;
				}
				else
					break;

			}

			if (userin[count] == ')')
			{
				if (temp.top() == '(')
				{
					temp.pop();
					continue;
				}
				else
					break;
			}
		}
	}
	if ((temp.empty()) && (check == 1))
		cout << "Balanced" << endl;
	else
		cout << "Not balanced" << endl;

}
