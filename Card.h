#pragma once

#include <string>
#include "Plata.h"
class Card : public Plata {
public:
    Card(unsigned long long _cnpClient, unsigned long long _cardNumber, std::string _card, int _sum, unsigned long long _timestamp) : Plata(_sum, _timestamp),
        cnpClient(_cnpClient),
		cardNumber(_cardNumber),
        card(_card)
    {
    }

	Card(const Card& c) : Plata(c) { cnpClient = c.cnpClient; cardNumber = c.cardNumber; }
	Card() : cardNumber(0), cnpClient(0) {};
    unsigned long long GetCnpClient() {
        return cnpClient;
    }

	unsigned long long GetCardNumber() {
		return cardNumber;
	}

    std::string GetCard() {
        return card;
    }

	friend ostream& operator << (ostream& out, const Card& c);
	friend istream& operator >> (istream& in, Card& c);

	ostream& operator<< (ostream& out) override {
		out << *this;
		return out;
	}
private:
    unsigned long long cnpClient, cardNumber;
    std::string card;
};