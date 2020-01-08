#include "Cec.h"

ostream& operator << (ostream& out, const Cec& c)
{
	out << "Cec:" << endl << "cnp client = " << c.cnpClient;
	out << endl;
	out << dynamic_cast<Plata const&>(c);
	return out;
}

istream& operator >> (istream& in, Cec& c)
{
	in >> dynamic_cast<Plata&>(c);
	in >> c.cnpClient;
	return in;
}
