#pragma once

#include "Plata.h"
class Cec : public Plata {
public:
    Cec(unsigned long long _cnpClient, int _sum, unsigned long long _timestamp) : Plata(_sum, _timestamp),
        cnpClient(_cnpClient)
    {
    }

	Cec(const Cec& c) : Plata(c) { cnpClient = c.cnpClient;  }
	Cec() : cnpClient(0) {};
    unsigned long long GetCnpClient() {
        return cnpClient;
    }

	ostream& operator<< (ostream& out) override {
		out << *this;
		return out;
	}

	friend ostream& operator << (ostream& out, const Cec& c);
	friend istream& operator >> (istream& in, Cec& c);
private:
    unsigned long long cnpClient;
};