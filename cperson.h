#pragma once
#ifndef CPERSON_H
#define CPERSON_H
#include <string>
#include "caddress.h"
#include "ctools.h"
#include "cdate.h"

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
		virtual string getCustNr();
		virtual void setCustNr(string){}
		string getName();
		void setName(string);

		friend ostream& operator<<(ostream&, CPerson&);
		virtual ostream& print(ostream&);
};


#endif
