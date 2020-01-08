#include "Card.h"

ostream& operator << (ostream& out, const Card& c)
{
	out << "Card:" << endl << "cnp client = " << c.cnpClient << ", card number = " << c.cardNumber;
	out << endl;
	out << dynamic_cast<Plata const&>(c);
	return out;
}

istream& operator >> (istream& in, Card& c)
{
	in >> dynamic_cast<Plata&>(c);
	

		in >> c.cnpClient >> c.cardNumber;
		
			if (c.cnpClient <pow(10,12) || c.cnpClient> pow(10,13))
			throw invalid_argument("invalid cnp");
		
	
	return in;
}
