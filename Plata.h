#pragma once

#include <ctime> 
#include <string>
#include <iostream>

using namespace std;
class Plata {

public:
    Plata(int _sum, unsigned long long _timestamp) : sum(_sum), timestamp(_timestamp), plataId(getCount()) {
    }
	Plata() : plataId(getCount()) {};
	Plata(const Plata& c) { plataId = c.plataId; sum = c.sum; timestamp = c.timestamp; }
	unsigned long long GetTimestamp();
	int GetSum();
	unsigned int GetPlataId();

	friend ostream& operator << (ostream& out, const Plata& c);
	friend istream& operator >> (istream& in, Plata& c);

	/*
		Ca sa le putem face virtuale si, implicit, sa putem face asta:

		Plata* x = cast<Plata*>(Cash*)
		x << cout; // va apela operatorul de ostream al lui cash
	*/
	virtual ostream& operator<< (ostream& out);

private:
	unsigned long long timestamp;
	int sum;
	unsigned int plataId;

	static int getCount()
	{
		static int theCount = 0;
		return theCount ++;
	}
};
