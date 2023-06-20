#ifndef CMAGAZINE_H
#define CMAGAZINE_H
#include "cprintedmedium.h"
#include <fstream>

class CMagazine : public CPrintedMedium {
private:
	string Designer;

public:
	CMagazine();
	CMagazine(string);
	void load(ifstream*);
	~CMagazine();
	void print();

	friend ostream& operator<<(ostream&, CMagazine&);
};

#endif
