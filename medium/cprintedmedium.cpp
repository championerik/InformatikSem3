#include "cprintedmedium.h"

CPrintedMedium::CPrintedMedium()		: Pages(-1) {}
CPrintedMedium::CPrintedMedium(int pag) : Pages(pag) {}

CPrintedMedium::~CPrintedMedium() {
	cout << "Das Printed-Medium '"<< titel << "' wird vernichtet!" << endl;
}

ostream& CPrintedMedium::print(ostream& outs) {
	outs << "Anz. Seiten: " << Pages << endl;
	CMedium::print(outs);
	return outs;
}

ostream& operator<<(ostream& outs, CPrintedMedium& Med)
{
	return Med.print(outs);
	// TODO: hier return-Anweisung eingeben
}

