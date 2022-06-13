//
// File:   list.h
// Author: Your Glorious Instructor
// Purpose:
// Implement the classic double linked version of a linked list.
//
#pragma once
#include <iostream>
#include "deque.h"
template <typename T>
class List
{
private:
    Deque<T>* aDeque; = new Deque<T>();
public:
    Queue() {}
    Queue(Queue& rhs) {}
    ~Queue() { delete aDeque; }
    bool empty() { return aDeque.empty(); }
    void push(T data) { aDeque.push_front(data); }
    T pop() { return aDeque.pop_back(); }
    void traverse(void(*doIt)(T data)) {
        aDeque.traverse(doIt);
    };
}



