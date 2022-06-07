// Homework 1 Problem 3 Data Structures
// Braden Owens
// 5/23/2022
// Circular List implementation of Lists
//I know I link the 
#pragma once
#include <iostream>
template <typename T>
class LinkedList
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
    void setupLinkedList() {
        Node* newNode = new Node();
        newNode->next = nullptr;
        newNode->prev = nullptr;
        head = newNode;
        tail = newNode;
    }
    void deleteLinkedListContents() {
        Node* temp = nullptr;
        Node* current = head;
        while (current != nullptr) {
            temp = current->next;
            delete current;
            current = temp;
        }
    }
public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    LinkedList(T newData) {
        setupLinkedList();
        head->data = newData;
    }

    LinkedList(LinkedList& rhs) { // copy constructor
        deleteLinkedListContents();
        head = rhs.head;
        tail = rhs.tail;
    }

    ~LinkedList() {// And a destructor
        deleteLinkedListContents();
    }

    bool  empty() {
        return (head == nullptr);
    }

    void push_front(T data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        newNode->prev = nullptr;
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
        if (lastNode != nullptr) {
            tail = tail->prev;
            tail->next = nullptr;
            delete lastNode;
        }
    }

    T& front() {
        if (!empty()) {
            return head->data;
        }
        else {
            // This is drastic, and should be handled using an exception handler
            std::cout << "Exception: LinkedList is empty." << std::endl;
            exit(1);
        }
    }

    T& back() {
        if (!empty()) {
            return tail->data;
        }
        else {
            // This is drastic, and should be handled using an exception handler
            std::cout << "Exception: LinkedList is empty." << std::endl;
            exit(1);
        }
    }

    void traverse(void (*doIt)(T& data)) {
        Node* current = head;
        while (current != nullptr) {
            doIt(current->data);
            current = current->next;
        }
    }
};
