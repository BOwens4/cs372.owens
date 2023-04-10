//Braden Owens
// 1/30/2022
//Homework 2
//GrayCode Towers of Hanoi
#include <vector>
#include <iostream>
#include <string>
using namespace std;
vector<string>generateGray(int n) //given function. The original had errors so this had to be tweaked.
{
    // Base case
    if (n <= 0) 
    {
        return { "0" };
    }
    if (n == 1) 
    {
        return { "0","1" };
    }
    //Recursive case
    vector<string> recAns = generateGray(n - 1);
    vector<string> mainAns;
    // Append 0 to the first half
    for (int i = 0; i < recAns.size(); i++) {
        string s = recAns[i];
        mainAns.push_back("0" + s);
    }
    // Append 1 to the second half
    for (int i = recAns.size() - 1; i >= 0; i--) {
        string s = recAns[i];
        mainAns.push_back("1" + s);
    }
    return mainAns;
}

void movedisks(int n)
{
    string f = "start";
    string r = "remaining";
    string t = "final";
    vector<string>vec2;
    vec2 = generateGray(n);
    if (n % 2 == 0) //if the number of disks is even
    {
        cout << "Because number of disks is even, the smallest disk moves from " << f << " to " << r << " to " << t << endl;


    }
    else //if number of disks is odd
    {
        cout << "Because number of disks is odd, the smallest disk moves from " << f << " to " << t << " to " << r << endl;

    }
    for (int count = 0; count < vec2.size(); count++)
    {
        cout << vec2[count] << endl;

    }

}

int main()
{
    int n = 0;
    cout << "Please input the number of disks you would like to use for the Towers of Hanoi" << endl;
    cin >> n;
    cout << "Below is the corresponding greycode steps. The bit position change indicates the peg movement" << endl;
    cout << endl;
    movedisks(n);

}

//works cited
//https://www.geeksforgeeks.org/generate-n-bit-gray-codes/