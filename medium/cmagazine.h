#pragma once
#ifndef CMAGAZINE_H
#define CMAGAZINE_H
#include <string>
#include "cprintedmedium.h"
#include "../ctools.h"

class CMagazine : public CPrintedMedium {
private:
	string Designer;

public:
	CMagazine();
	CMagazine(string);
	void load(ifstream*);
	~CMagazine();
	void print();

	virtual ostream& print(ostream& outs);

	friend ostream& operator<<(ostream&, CMagazine&);
};

#endif
