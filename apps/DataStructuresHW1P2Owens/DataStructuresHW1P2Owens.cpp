// Homework 1 Problem 2 Data Structures
// Braden Owens
// 5/23/2022
// Test Cases For lists
//
// File:   listtest.cpp
// Author: Your Glorious Instructor <adam.lewis@athens.edu>
// Purpose:
// Demonstrate the use of our List class.
//
//
// File:   listtest.cpp
// Author: Your Glorious Instructor <adam.lewis@athens.edu>
// Purpose:
// Demonstrate the use of our List class.
//

// Some other test cases would be to 
// 1. Test to see if list can pushed front 20 int correctly
// 2. Test to see if list can pop back all of those ints
// 3. Test to see if list can push back 25
// 4. Test to see if list can push back 32
// 5. Test to see if list pushes back 42.
#include <iostream>
#include "header.h";
template <typename T>
void printItem(int& item) 
{
    std::cout << item << " ";
}

int main()
{
    List<int> aListOfIntegers;
    if (aListOfIntegers.empty()) {
        std::cout << "Yep, the new list is empty. " << std::endl;
    }
    for (int i = 10; i >= 0; i--) {
        aListOfIntegers.push_front(i);
    }
    for (int i = 20; i >= 0; i--) {
        aListOfIntegers.push_front(i);
    }
    aListOfIntegers.traverse(printItem);
    std::cout << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << aListOfIntegers.back() << " ";
        aListOfIntegers.pop_back();
    }
    for (int i = 0; i < 10; i++) {
        std::cout << aListOfIntegers.back() << " ";
        aListOfIntegers.pop_back();
    }
    if (!aListOfIntegers.empty()) {
        aListOfIntegers.traverse(printItem);
        std::cout << std::endl;
    }
    aListOfIntegers.push_back(42);
    aListOfIntegers.push_back(25);
    aListOfIntegers.push_back(32);
    aListOfIntegers.traverse(printItem);
    std::cout << std::endl;
    return 0;
}