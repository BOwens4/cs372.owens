// Homework 5 Problem 1 Data Structures
// Braden Owens
// 7/7/2022
// This program creates a function to implement the algorithm given
// I try to run the program and my computer just freezes. it builds sucessfully but does not run.I can not get an output,even after letting my computer sit for a few minutes.
//However I feel that most if not all of my logic is correct

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
                    if (A[i][j] == A[k][m] && !(i == k && j == m))
                        return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    int size = 0;
    double temp = 0;
    list<int> sizes = { 10,20,30,40,50,100,500,1000 };
    double sum = 0;
    double average = 0;
    int** A;
    A = (int**)malloc(size * sizeof(int*));
    auto start = chrono::steady_clock::now();
    auto end = chrono::steady_clock::now();
    for (auto size : sizes)
    {
        sum = 0;
        for (int count = 0; count <= 20; count++)
        {
            for (int row = 0; row < size; row++) {
                A[row] = (int*)malloc(size * sizeof(char));
            }
            for (int row = 0; row < size; row++) {
                for (int col = 0; col < size; col++) {
                    A[row][col] = rand();
                }
            }
            start = chrono::steady_clock::now();
            anyEqual(size, A);
            end = chrono::steady_clock::now();
            chrono::duration<double>elapsed_seconds = end - start;
            temp = elapsed_seconds.count();
            sum += temp;
            average = sum / 20;
            cout << "Array of size: " << size << " had an average of: " << average << endl;
        }
    }
    return 0;
}
