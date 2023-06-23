#ifndef CPRINTEDMEDIUM_H
#define CPRINTEDMEDIUM_H
#include "../cmedium.h" //hier anpassen
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
