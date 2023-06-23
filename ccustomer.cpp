#include "ccustomer.h"

CCustomer::CCustomer(): CustomerNr("  /"){}
CCustomer::CCustomer(string custnr): CustomerNr(custnr) {}

void CCustomer::load(ifstream* data) {
	char text[101];
	while (data->getline(text, 100, '\n')) {
		string tmp(text);
		if (!(tmp.find("<CustomerNr>") == string::npos)) {
			CustomerNr = parseLine(tmp);
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
		else if (!(tmp.find("</Customer>") == string::npos)) {
			break;
		}
	}
}

void CCustomer::print(){
	cout << name << " (Kundennr.: " << CustomerNr << ")" << endl;
	address.print(); cout << endl;
	cout << "* ";
	birthday.print();
	cout << endl;
}



CCustomer::~CCustomer() {
	cout << "Der Kunde          '" << name << "' wird vernichtet!" << endl;
}

ostream& CCustomer::print(ostream& outs) {
	outs << name << " (Kundennr.: " << CustomerNr << ")" << endl;
	outs << address << endl;
	outs << birthday << endl;
	return outs;
}

ostream& operator<<(ostream& outs, CCustomer& curr)
{
	return curr.print(outs);
	// TODO: hier return-Anweisung eingeben
}
