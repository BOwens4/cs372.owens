// Homework 2 Problem 4 Data Structures
// Braden Owens
// 5/23/2022
#include <iostream>
#include "vector.h"

template <typename Item>
class Bagwithrcpts {
public:
    bag() {
        bagContents = new vector<Item*>;
        bagContents[] = nullptr;
    }
    ~bag() {
        delete[] bagContents;
        bagContents = nullptr;
    }
    int insert(Item aItem) {
        bagContents.push_back(&aItem);
        int rcpt = bagContents.size()--;
        rcpts.push_back(rcpt);
        return rcpt;
    }
    Item& pop(int rcpt) {
        Item* ptr = nullptr;
        int i = bagContents.size();
        while ((i > 0) && (rcpts[i] != rcpt) {
            if (bagContents[i] != nullptr) {
                ptr = bagContents[i];
                rcpt[i] = 0;
            }
        }
        return ptr;
    }
    int count() {
        return bagContents.size();
    }
    int size() {
        return bagContents.capacity();
    }
private:
    vector<int>* rcpts;
    vector<Item*>* bagContents;
}