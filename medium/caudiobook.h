#ifndef CAUDIOBOOK_H
#define CAUDIOBOOK_H
#include "cbook.h"
#include "ccd.h"
#include <fstream>
class CAudiobook : public CBook, public CCD {
private:
	int countCDs;

public:
	CAudiobook();
	CAudiobook(int);
	void load(ifstream*);
	void print();
	~CAudiobook();
};

#endif
