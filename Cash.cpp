#include "Cash.h"

ostream& operator << (ostream& out, const Cash& c)
{
	out << "Cash: ";
	out << endl;
	out << dynamic_cast<Plata const&>(c);
	return out;
}

istream& operator >> (istream& in, Cash& c)
{
	in >> dynamic_cast<Plata&>(c);
	return in;
}
