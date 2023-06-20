#ifndef CCD_H
#define CCD_H
#include "../cmedium.h" //hier anpassen
#include <fstream>
class CCD : virtual public CMedium {
protected:
	string Interpret;
	int Tracks;

public:
	CCD();
	CCD(string, int);
	void load(ifstream*);
	void print();
	virtual ~CCD();

	friend ostream& operator<<(ostream&, CCD&);
};

#endif
