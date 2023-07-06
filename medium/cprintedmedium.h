#pragma once
#ifndef CPRINTEDMEDIUM_H
#define CPRINTEDMEDIUM_H
#include <string>
#include "../cmedium.h"
#include "../ctools.h"
class CPrintedMedium : virtual public CMedium {
protected:
	int Pages;

public:
	CPrintedMedium();
	CPrintedMedium(int);
	virtual ~CPrintedMedium();
	virtual ostream& print(ostream& outs);
	friend ostream& operator<<(ostream&, CPrintedMedium&);
};

#endif
