#include "cemployee.h"

CEmployee::CEmployee(): EmployeeNr("  /") {}
CEmployee::CEmployee(string empNr) : EmployeeNr(empNr) {}

void CEmployee::load(ifstream* data) {
	char text[101];
	while (data->getline(text, 100, '\n')) {
		string tmp(text);
		if (!(tmp.find("<EmployeeNr>") == string::npos)) {
			EmployeeNr = parseLine(tmp);
		}
		else if (!(tmp.find("<Name>") == string::npos)) {
			name = parseLine(tmp);
		}
		else if (!(tmp.find("<Birthday>") == string::npos)) {
			birthday.load(data);
		}
		else if (!(tmp.find("<Address>") == string::npos)) {
			address.load(data);
		}
		else if (!(tmp.find("<CustomerNr>") == string::npos)) {
			CustomerNr = parseLine(tmp);
		}
		else if (!(tmp.find("</Chairman>") == string::npos)) {
			break;
		}
		else if (!(tmp.find("</Manager>") == string::npos)) {
			break;
		}

	}
}

CEmployee::~CEmployee() {
	cout << "Der Angestellte    '" << name << "' wird vernichtet!" << endl;
}

void CEmployee::print(){
	cout << name << " (Kundennr.: " << CustomerNr << " Personalnr.: " << EmployeeNr << ")" << endl;
	address.print(); cout << endl;
	cout << "* ";
	birthday.print();
	cout << endl;


}
