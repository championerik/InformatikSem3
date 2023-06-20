#include "cprintedmedium.h"

CPrintedMedium::CPrintedMedium()		: Pages(-1) {}
CPrintedMedium::CPrintedMedium(int pag) : Pages(pag) {}

CPrintedMedium::~CPrintedMedium() {
	cout << "Das Printed-Medium '"<< titel << "' wird vernichtet!" << endl;
}
