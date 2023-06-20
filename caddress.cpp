#include "caddress.h"

CAddress::CAddress(): street("Keine Strassee"),number("No House-Number"),zipcode("No ZipCode"),town("No Town") {}
CAddress::CAddress(string str, string nr, string zip, string tn) : street(str), number(nr), zipcode(zip), town(tn) {}

void CAddress::print() {
	cout << street << " " << number << "; " << zipcode << " " << town;
}
void CAddress::load(ifstream* data) {
	char text[101];
	while (data->getline(text, 100, '\n')) {
		string tmp(text);
		if (!(tmp.find("<Street>") == string::npos)) {
			street = parseLine(tmp);
		}
		else if (!(tmp.find("<Number>") == string::npos)) {
			number = parseLine(tmp);
		}
		else if (!(tmp.find("<Zipcode>") == string::npos)) {
			zipcode = parseLine(tmp);
		}
		else if (!(tmp.find("<Town>") == string::npos)) {
			town = parseLine(tmp);
		}
		else if (!(tmp.find("</Address>") == string::npos)) {
			break;
		}
	}
}
