#pragma once
#ifndef CCD_H
#define CCD_H
#include <string>
#include "../cmedium.h"
#include "../ctools.h"
using namespace std;

class CCD : virtual public CMedium {
protected:
	string Interpret;
	int Tracks;

public:
	CCD();
	CCD(string, int);
	void load(ifstream*);
	void print();
	virtual ostream& print(ostream& outs);
	virtual ~CCD();

	friend ostream& operator<<(ostream&, CCD&);
};

#endif
