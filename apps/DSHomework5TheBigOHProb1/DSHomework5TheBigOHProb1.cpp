// Homework 5 Problem 1 Data Structures
// Braden Owens
// 7/7/2022
// This program creates a function to implement the algorithm given
#include <iostream>
#include <chrono>
#include <list>
using namespace std;
int anyEqual(int n, int **A)
{
    int i, j, k, m;
    for (i = 0; i <= n; i++){
        for (j = 0; j <= n; j++){
            for (k = 0; k <= n; k++){
                for (m = 0; m <= n; m++){
                    if (**A[i][j] == **A[k][m] && !(i == k && j == n))
                        return 1;
                }
            }
        }
    }
    return 0;
}

int main() 
{
    list<int> sizes = { 10,20,30,40,50,100,500,1000 };
    int average = 0;
    auto start = chrono::steady_clock::now();
    auto end = chrono::steady_clock::now();
    for (auto size : sizes)
    {
        sum = 0;
        for (int i = 0, i <= 20; i++)
        {
            anyEqual(size, **A[][])
                average = sum / 20
        }
    }
