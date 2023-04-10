// This will create an Vector Permuation function we can use later
//Braden Owens
//2/6/2023

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;
int RANDOM(int a, int b)
{
    default_random_engine generate;
    uniform_int_distribution<int> distribute(a, b);
    int randomnum = distribute(generate);
    return randomnum;
}

void PERMUTE(vector<int>A)
{
    int i = 0;
    int n = A.size();
    for (i = 0; i < n; i++)
    {
        swap(A[i], A[RANDOM(i,n)]);
    }
}

int main()
{
    vector<int>A;
    int n = A.size();
    int input = 0;
    cout << "How many numbers do you wish to input into the vector?" << endl;
    cin >> n;
    cout << "Enter the values to implement into your vector" << endl;
    //fill vector
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        A.push_back(input);
    }
    PERMUTE(A);
    //print result
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << endl;
    }

    return 0;



}

//Works Cited
//https://cplusplus.com/reference/random/
// https://www.geeksforgeeks.org/passing-vector-function-cpp/
//https://cplusplus.com/reference/list/list/push_back/