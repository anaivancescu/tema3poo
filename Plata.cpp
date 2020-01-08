#include "Plata.h"
unsigned long long Plata::GetTimestamp() {
	return timestamp;
}

int Plata::GetSum() {
	return sum;
}

unsigned int Plata::GetPlataId() {
	return plataId;
}

std::string timestampToReadableTime(unsigned long long timestamp)
{
	time_t t = timestamp;

	const static int MAXBUF = 500;
	char tmpstr[MAXBUF];
	if (ctime_s(tmpstr, MAXBUF, &t)) {
		return "error";
	}
	return tmpstr;
}

ostream& operator << (ostream& out, const Plata& c)
{
	out << "id = " << c.plataId << ", suma = " << c.sum << ", timestamp = " << timestampToReadableTime(c.timestamp);
	out << endl;
	return out;
}

istream& operator >> (istream& in, Plata& c)
{
	in >> c.sum >> c.timestamp;
	return in;
}


ostream& Plata::operator<< (ostream& out){
	out << *this;
	return out;
}