#pragma once
#ifndef CCUSTOMER_H
#define CCUSTOMER_H
#include <string>
#include <vector>
#include "cperson.h"
#include "ctools.h"
#include "cloan.h"
using namespace std;

class CCustomer: virtual public CPerson {
protected:
	string CustomerNr;
	vector <CLoan*>LoanList;
public:
	CCustomer();
	//CCustomer(string);
	virtual void load(ifstream*);
	virtual void print();
	virtual ~CCustomer();

	void add(CLoan*);
	string getCustNr() { return CustomerNr; }
	void setCustNr(string newcust) { CustomerNr = newcust; }

	virtual ostream& print(ostream& outs);

	friend ostream& operator<<(ostream&, CCustomer&);
};

#endif
