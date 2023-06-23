#ifndef CCUSTOMER_H
#define CCUSTOMER_H
#include "cperson.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdio>
class CCustomer: virtual public CPerson {
protected:
	string CustomerNr;
	//int Status;
	//vector <CLoan*>LoanList;
public:
	CCustomer();
	CCustomer(string);
	virtual void load(ifstream*);
	virtual void print();
	virtual ~CCustomer();

	virtual ostream& print(ostream& outs);

	friend ostream& operator<<(ostream&, CCustomer&);
};

#endif
