// Homework 2 Problem 4 Data Structures
// Braden Owens
// 5/23/2022
#include <iostream>
#include <random>
#include "vector.h"

template <typename Thing>
class Bag {
public:
    bag() {
        bagContents = new vector<Thing*>;
        bagContents[0] = nullptr;
    }
    ~bag() {
        delete[] bagContents;
        bagContents = nullptr;
    }
    int insert(Thing aThing) {
        bagContents.push_back(&aThing);
        int receipt = bagContents.size() - 1;
        receipts.push_back(receipt);
        return receipt;
    }
    Thing* pop(int receipt) {
        Thing* ptrToAThing = nullptr;
        int i = bagContents.size();
        bool thingIsNull = true;
        while (thingIsNull && (i > 0) && (receipts[i] != receipt) {
            if (bagContents[i] != nullptr) {
                ptrToAThing = bagContents[i];
                thingIsNull = false;
                receipt[i] = 0;
            }
        }
        return ptrToAThing;
    }
    int size() {
        return bagContents.capacity();
    }
    int count() {
        return bagContents.size();
    }
private:
    vector<Thing*>* bagContents;
    vector<int>* receipts;
}