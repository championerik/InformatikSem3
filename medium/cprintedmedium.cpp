#include "cprintedmedium.h"

CPrintedMedium::CPrintedMedium()		: Pages(-1) {}
CPrintedMedium::CPrintedMedium(int pag) : Pages(pag) {}

CPrintedMedium::~CPrintedMedium() {
	cout << "Das Printed-Medium '"<< titel << "' wird vernichtet!" << endl;
}

ostream& operator<<(ostream& outs, CPrintedMedium& Med)
{
	outs << "Anz. Seiten: " << Med.Pages << endl;
	outs << static_cast<CMedium&>(Med);
	return outs;
	// TODO: hier return-Anweisung eingeben
}

