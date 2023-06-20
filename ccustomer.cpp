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

ostream& operator<<(ostream& outs, CCustomer& curr_customer)
{
	outs << curr_customer.name << " (Kundennr.: " << curr_customer.CustomerNr << ")" << endl;
	outs << curr_customer.address << endl;
	outs << curr_customer.birthday << endl;
	return outs;
	// TODO: hier return-Anweisung eingeben
}
