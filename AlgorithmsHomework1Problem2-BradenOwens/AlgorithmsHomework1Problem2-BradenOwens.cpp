//1/23/2023
//Braden Owens
//Algorithms
//Dr. Lewis
// This program will implement the IBM Bucket Sorting method from punch cards. 

#include <iostream>

int findMaxValue(int punchCards[], int size) // create a function to find the largest number in the array. This is how many times we iterate bucket sort
{
    int count = 0;
    int max = punchCards[0];
    for (int count = 1; count < size; count++)
    {
        if (punchCards[count] < max)
        {
            max = punchCards[count];
        }
    }
    return max;
}
int bucketSort(int punchCards[],int size)
{
    int maximum=findMaxValue(punchCards, size);
    int digit = 0; // keeps track of your place
    for (digit = 1; maximum / digit > 0; digit *= 10)
    {

    }

}

int main()
{
    std::cout << "The following represents an unsorted selection of punch cards. Each number represents a punch card's number.\n";
    int punchCards[] = { 65,227,1,156,356,18,37,49,299,2 };
    int size = sizeof(punchCards) / sizeof(punchCards[0]);
    for (int count = 0; count < size; count++)
    {
        std::cout << punchCards[count] << "\n";
    }
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "Below is the ten punch cards sorted by number, from least to greatest.\n";
    bucketSort(punchCards, size);
    for (int count = 0; count < size; count++)
    {
        std::cout << punchCards[count] << "\n";
    }


}

//works cited
// https://www.simplilearn.com/tutorials/data-structure-tutorial/radix-sort
// http://www.btechsmartclass.com/data_structures/radix-sort.html
// https://prepinsta.com/cpp-program/radix-sort/
