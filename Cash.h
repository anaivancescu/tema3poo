#pragma once

#include "Plata.h"
class Cash : public Plata {

public:
    Cash(int _sum, unsigned long long _timestamp) : Plata(_sum, _timestamp) {
    }

	Cash() {};
	Cash(const Cash& c) : Plata(c) { }
	friend ostream& operator << (ostream& out, const Cash& c);
	friend istream& operator >> (istream& in, Cash& c);

	ostream& operator<< (ostream& out) override {
		out << *this;
		return out;
	}
};