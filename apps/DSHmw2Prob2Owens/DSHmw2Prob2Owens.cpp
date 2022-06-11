// Homework 2 Problem 2 Data Structures
// Braden Owens
// 5/23/2022
// Besides changing the vector in private of this class, and adding a delete section to the list header included, this is all i know that needs to be changed in the code for it to work
//Is there anything i am missing to make it work?

#pragma once
#include <iostream>
#include "list.h"

template <typename Thing>
class Bag {
public:
    void push_back(Thing aThing) {
        bagContents.push_back(aThing);
        bagSize++;
    }
    Thing& pop_back() {
        Thing aThing;
        if (bagContents.size() > 0) {
            aThing = bagContents[bagSize];
            bagSize--;
        }
        else {
            std::cerr << "Can't pop out of an empty bag" << std::endl;
        }
        return aThing;
    }
    int size() {
        return bagSize;
    }
    int count(Thing aThing) {
        int bagCount = 0;
        for (int i = 0; i < bagSize; i++) {
            if (bagContents[i] == aThing) {
                bagCount++;
            }
        }
        return bagCount;
    }
private:
    list<Thing> bagContents;
    int bagSize = 0;
};