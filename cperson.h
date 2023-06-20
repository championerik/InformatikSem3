#ifndef CPERSON_H
#define CPERSON_H
#include <string>
#include "caddress.h"
#include "cdate.h"
#include <cstdio>
#include <iostream>
#include "tools.h"

using namespace std;
class CPerson {
	protected:
		string name;
		CAddress address;
		CDate birthday;

	public:
		CPerson();
		CPerson(string, CAddress, CDate);
		virtual void print();
		virtual void load(ifstream*);
		virtual ~CPerson();
};


#endif
