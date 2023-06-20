#include "clocation.h"

CLocation::CLocation() {
	section = "Buero";
	rack = "Fach zum einsortieren";
}
CLocation::CLocation(string sec, string ra) : section(sec), rack(ra) {


}

void CLocation::print(){
	cout << "Abt.: " << section << "; Regal: " << rack;
}

void CLocation::load(ifstream* data) {
	char text[101];
	while (data->getline(text, 100, '\n')) {
		string tmp(text);
		if (!(tmp.find("<Section>") == string::npos)) {
			section = parseLine(tmp);
		}
		else if (!(tmp.find("<Rack>") == string::npos)) {
			rack = parseLine(tmp);
		}
		else if (!(tmp.find("</Location>") == string::npos)) {
			break;
		}
	}
}

ostream& operator<<(ostream& outstream, const CLocation& curr_location)
{
	return (outstream << "Abt.: " << curr_location.section << "; Regal: " << curr_location.rack);
}
