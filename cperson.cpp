#include "cperson.h"
#include "ccustomer.h"

CPerson::CPerson(): name("Kein Name") {}
CPerson::CPerson(string nm, CAddress addr, CDate birth)
	:name(nm), address(addr), birthday(birth) {}

void CPerson::print() {
	cout << name << " " << "(* "; birthday.print();	cout << ")" << endl;
	address.print(); cout << endl;

}
CPerson::~CPerson() {
	cout << "Die Person         '" << name << "' wird vernichtet!" << endl;


}
void CPerson::load(ifstream* data) {
	char text[101];
	while (data->getline(text, 100, '\n')) {
		string tmp(text);
		if (!(tmp.find("<Name>") == string::npos)) {
			name = parseLine(tmp);
		}
		else if (!(tmp.find("<Birthday>") == string::npos)) {
			birthday.load(data);
		}
		else if (!(tmp.find("<Address>") == string::npos)) {
			address.load(data);
		}
		else if (!(tmp.find("</Person>") == string::npos)) {
			break;
		}
		else {
			//cout << "CPerson Lesefehler du!" << endl;
		}
	}
	return;
}
