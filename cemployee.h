#ifndef CEMPLOYEE_H
#define CEMPLOYEE_H
#include "ccustomer.h"
#include "cperson.h"
#include <iostream>
#include <fstream>
#include <cstdio>
class CEmployee : virtual public CPerson, public CCustomer{
protected:
	string EmployeeNr;

public:
	CEmployee();
	CEmployee(string);
	virtual ~CEmployee();
	void load(ifstream*);
	void print();

	virtual ostream& print(ostream& outs);

	friend ostream& operator<<(ostream&, CEmployee&);
};

#endif
