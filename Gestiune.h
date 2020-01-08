#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Gestiune {
public:
	Gestiune(unsigned int _capacity) : capacity(_capacity), size(0) {
		arr = new T[capacity];
	}
	~Gestiune() {
		delete[] arr;
	}

	unsigned int GetSize() {
		return size;
	}

	Gestiune& operator+=(T& rhs) {
		if (capacity == size) {
			cout << "capacity == size, nu mai putem adauga in Gestiune" << endl;
			return *this;
		}
		arr[size++] = rhs;
		return *this;
	}

	friend ostream& operator << (ostream& out, const Gestiune<T>& c)
	{
		out << "Gestiune dimensiune = " << c.size << endl;
		for (unsigned int i = 0; i < c.size; i++) {
			out << c.arr[i];
		}
		return out;
	}
private:
	T* arr;
	unsigned int capacity, size;
};