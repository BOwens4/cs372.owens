// This code will implement two different algorithms to create a random sample of the numbers from 1 to n.
//Braden Owens
//2/6/2023
//Algorithms

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <list>
using namespace std;

int RANDOM(int a, int b) //works perfectly
{
    default_random_engine generate;
    uniform_int_distribution<int> distribute(a, b)
    int randomnum = distribute(generate);
    return randomnum;
}
void PERMUTE(vector<int>A)
{
    int i = 0;
    int n = A.size();
    for (i = 0; i < n; i++)
    {
        swap(A[i], A[RANDOM(i, n)]);
    }
}

list<int> RandomSample(int n, int samplesize) //RANDOM-SAMPLE FUNCTION
{
    list<int>list;
    if (samplesize == 0) //return empty list
    {
        return list;
    }
    else
    {
        list = RandomSample(samplesize - 1, n - 1);
        int i = RANDOM(1, n);
        int searchval = find(list.begin(), list.end(), i);
        if (searchval !=list.end())
        {
            list.push_back(n);
        }
        else
        {
            list.push_back(i);
        }
    }
    return list;
}
int main()
{
    int n = 0;
    cout << "Please enter the number of elements you wish to create a sample for " << endl;
    cin >> n;
    int m = n - 1;
    RandomSample(n, m);
    
    // other method
    vector<int>secondMethod(n);
    PERMUTE(secondMethod);
    for (int i = 0; i < m; i++)
    {
        cout << secondMethod[i] << endl;
    }


}
//Works Cited
//https://cplusplus.com/reference/random/
// https://www.geeksforgeeks.org/passing-vector-function-cpp/
//https://cplusplus.com/reference/list/list/push_back/
