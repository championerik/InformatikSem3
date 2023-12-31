#pragma once
#ifndef CAUDIOBOOK_H
#define CAUDIOBOOK_H
#include "cbook.h"
#include "ccd.h"
#include "../ctools.h"
using namespace std;

class CAudiobook : public CBook, public CCD {
private:
	int countCDs;

public:
	CAudiobook();
	CAudiobook(int);
	void load(ifstream*);
	void print();
	~CAudiobook();

	virtual ostream& print(ostream& outs);

	friend ostream& operator<<(ostream&, CAudiobook&);
};

#endif
