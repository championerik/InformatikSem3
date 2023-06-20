#ifndef CBOOK_H
#define CBOOK_H
#include "cprintedmedium.h"
#include <fstream>
class CBook : public CPrintedMedium {
protected:
	string Autor;

public:
	CBook();
	CBook(string);
	void load(ifstream*);
	void print();
	virtual ~CBook();

	
	friend ostream& operator<<(ostream&, CBook&);
};

#endif
