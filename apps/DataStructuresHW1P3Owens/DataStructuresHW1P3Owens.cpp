// Homework 1 Problem 3 Data Structures
// Braden Owens
// 5/23/2022
// Circular List implementation of Lists
//I know I link the front to the back and back to the front node of the list, but I am not really sure on how to implement this
#pragma once
#include <iostream>
template <typename T>
class CircularLinkedList
{
private:
    class Node {
    public:
        T  data;
        Node* prev;
        Node* next;
    };
    Node* head = nullptr;
    Node* tail = nullptr;
    void setupCircularLinkedList() {
        Node* newNode = new Node();
        newNode->next = nullptr;
        newNode->prev = nullptr;
        head = newNode;
        tail = newNode;
    }
    void deleteCircularLinkedListContents() {
        Node* temp = nullptr;
        Node* current = head;
        while (current != tail) {
            temp = current->next;
            delete current;
            current = temp;
        }
    }
public:
    CircularLinkedList() : head(nullptr), tail(nullptr) {}

    CircularLinkedList(T newData) {
        setupCircularLinkedList();
        head->data = newData;
    }

    CircularLinkedList(CircularLinkedList& rhs) { // copy constructor
        deleteCircularLinkedListContents();
        head = rhs.head;
        tail = rhs.tail;
    }

    ~CircularLinkedList() {// And a destructor
        deleteCircularLinkedListContents();
    }

    bool  empty() {
        return (head == nullptr);
    }

    void push_front(T data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        newNode->prev = tail;
        if (empty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(T data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = tail;
        if (empty()) {
            tail = newNode;
            head = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_back() {
        Node* lastNode = tail;
        if (lastNode != head) {
            tail = tail->prev;
            tail->next = head;
            delete lastNode;
        }
    }

    T& front() {
        if (!empty()) {
            return head->data;
        }
        else {
            // This is drastic, and should be handled using an exception handler
            std::cout << "Exception: CircularLinkedList is empty." << std::endl;
            exit(1);
        }
    }

    T& back() {
        if (!empty()) {
            return tail->data;
        }
        else {
            // This is drastic, and should be handled using an exception handler
            std::cout << "Exception: CircularLinkedList is empty." << std::endl;
            exit(1);
        }
    }

    void traverse(void (*doIt)(T& data)) {
        Node* current = head;
        if (head == tail) {
            doIt(head->data);
        }
        else
        {
            while (current != tail)
            {
                doIt(current->data);
                current = current->next;
            }
            doIt(tail->data)
        }
    }
};
