// Homework 2 Problem 1 Data Structures
// Braden Owens
// 5/23/2022
// This program will create an array class

#pragma once
#include <iostream>

template <typename T>
class array {
public:
	array() {
		arr = new T[1];
		vCapacity = 1;
		length = 0;
		size_t = sizeof(arr);
	}
	~array() {
		delete[] arr;
		arr = nullptr;
	}

	void put(T data, int index) {
		if (index == vCapacity) {
			push_back(data);
		}
		else {
			arr[index] = data;
		}
	}

	void push_back(T data) {
		// if number of elements is equal to capacity
			// than we need to reallocate and deep copy
		if (length == vCapacity) {
			expand(2 * vCapacity);
		}
		arr[length] = data;
		length++;
	}

	T& at(int index) {
		if (index < 0 || index > length) {
			std::cerr << "array: index out of bounds on access" << std::endl;
			exit(1);
		}
		else {
			return arr[index];
		}
	}

	int size() {
		return length;
	}

	int capacity() {
		return vCapacity;
	}

	void traverse() {
		for (int i = 0; i < length; i++) {
			std::cout << arr[i] << std::endl;
		}
		std::cout << std::endl;
	}

	bool operator==(array& other) const {
		if (other.size() != length) {
			return false;
		}
		else {
			for (int i = 0; i < length; i++) {
				if (arr[i] != other.get(i)) {
					return false;
				}
			}
		}
		return true;
	};

	T& operator[](int i) {
		if ((i < 0) || (i >= length)) {
			std::cerr << std::endl << "array index out of bounds" << std::endl;
		}
		return at(i);
	}

	array& operator=(const array& source) {
		// Do a self check.
		if (this == &source)
		{
			return *this;
		}
		// Reset self
		delete[] arr;
		arr = new T[1];
		vCapacity = 1;
		length = 1;
		size_t = 1;
		for (int i = 0; i < source.size(); i++) {
			push_back(source.at(i));
		}
		return *this;
	}
private:
	T* arr = new T[1];
	int vCapacity = 1;
	int length = 1;
	int size_t = 1;

	void expand(int newCapacity) {
		if (newCapacity > vCapacity) {
			T* temp = new T[newCapacity];
			for (int i = 0; i < length; i++) {
				temp[i] = arr[i];
			}
			delete[] arr;
			vCapacity = newCapacity;
			arr = temp;
		}
		else {
			std::cerr << "array::expand: new capacity is less than equal to current\n";
		}
	}
};