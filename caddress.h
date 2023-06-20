#ifndef CADDRESS_H
#define CADDRESS_H
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include "tools.h"
using namespace std;

class CAddress {
	private:
		 string street, number, zipcode, town;
	public:
		CAddress();
		CAddress(string, string, string, string);
		void print();
		void load(ifstream*);

		friend ostream& operator<<(ostream&, const CAddress&);
};
#endif
