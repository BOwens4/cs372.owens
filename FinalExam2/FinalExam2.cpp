// Final Exam P2
// Braden Owens
// 7/25/2022
#include <list>
#include <iostream>
using namespace std;
template <typename T>
T partition(T splitval,list<T>,list<T>&lessthan,list<T>&greaterthan)
{
  

}
void quickSortrecur(int splitval,list<int>&lessthan,list<int>&greaterthan)
{
    if (p < r)
    {
        int q = partition(splitval, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}
// I do not understand this question well at all.
// I know to do quicksort recursively with arrays but not lists.