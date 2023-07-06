#pragma once
#ifndef CBOOK_H
#define CBOOK_H
#include <string>
#include "cprintedmedium.h"
#include "../ctools.h"
using namespace std;

class CBook : public CPrintedMedium {
protected:
	string Autor;

public:
	CBook();
	CBook(string);
	void load(ifstream*);
	void print();
	virtual ~CBook();

	virtual ostream& print(ostream& outs);

	
	friend ostream& operator<<(ostream&, CBook&);
};

#endif
