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
	friend ostream& operator<<(ostream&, CPrintedMedium&);
};

#endif
