
#include <iostream>
#include <unordered_map>
#include <fstream>

#include "Cash.h"
#include "Cec.h"
#include "Card.h"
#include "Gestiune.h"

unordered_map<unsigned int, Plata*> plati; // map < id plata : plata > 
using namespace std;

void citestePlati() {

}

void afiseaza() {
	for (const auto& it : plati) {
		// operatorul << ca membru al functiei e virtual, deci va afisa ca si cum e Cash / Card etc.
		*it.second << cout;
	}
	cout << endl;
}
void citeste() {

	/*
		formatul de citire e
		< n > // cate linii sunt
		// A B C - valorile specifice pt tipul X
	*/
	{
		ifstream fin("PlatiCash.txt");
		int n;
		fin >> n;
		for (int i = 0; i < n; i++) {
			Cash* x = new Cash();
			fin >> *x;
			plati[x->GetPlataId()] = x;
		}
	}

	{
		ifstream fin("PlatiCec.txt");
		int n;
		fin >> n;
		for (int i = 0; i < n; i++) {
			Cec* x = new Cec();
			fin >> *x;
			plati[x->GetPlataId()] = x;
		}
	}

	{
		ifstream fin("PlatiCard.txt");
		
		int n;
		fin >> n;
		//Card* x = new Card();
		for (int i = 0; i < n; i++) {
			Card* x = new Card();
			try {
				
				fin >>*x ;
			}
			catch (const invalid_argument & ia) {
				cout << "Eroare intampinata =  " << ia.what() << '\n';
				//continue;
			}
			
			//	fin >> *x;
			plati[x->GetPlataId()] = x;
			
		}
		
	}
}

void gestiune() {
	cout << endl << endl << "test_gestiune:" << endl;
	Gestiune<Card> g(100);
	ifstream fin("PlatiCard.txt");
	int n;
	fin >> n;
	for (int i = 0; i < n; i++) {
		Card x;
		try {
			
			fin >> x;
		}
		catch (const invalid_argument & ia) {
			cout << "Eroare intampinata =  " << ia.what() << '\n';

		}
		//Card x;
		//fin >> x;
		g += x;
	}
	cout << g;
}
void test() {
	citeste();
	afiseaza();

	gestiune();
}
int main()
{
	
    test();
}