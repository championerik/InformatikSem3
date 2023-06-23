#include "cmagazine.h"
#include <fstream>

CMagazine::CMagazine()				: Designer("Kein Designer hinterlegt"){}
CMagazine::CMagazine(string des) 	: Designer(des) {}

void CMagazine::load(ifstream* data){
	char text[101];
	while (data->getline(text, 100, '\n')) {
		string tmp(text);
		if (!(tmp.find("<Designer>") == string::npos)){
			Designer = parseLine(tmp);
		}
		else if (!(tmp.find("<Pages>") == string::npos)){
			Pages = stoi(parseLine(tmp));
		}
		else if (!(tmp.find("<Title>") == string::npos)){
			titel = parseLine(tmp);
		}
		else if (!(tmp.find("<Signatur>") == string::npos)){
			signatur = parseLine(tmp);
		}
		else if (!(tmp.find("<Location>") == string::npos)){
			ort.load(data);
		}
		else if (!(tmp.find("<FSK>") == string::npos)){
			altersfreigabe = stoi(parseLine(tmp));
		}
		else if (!(tmp.find("<Status>") == string::npos)){
			Status = getstatus(stoi((parseLine(tmp))));
		}
		else if (!(tmp.find("</Magazine>") == string::npos)) {
			break;
		}
	}
}

CMagazine::~CMagazine() {
	cout << "Das Magazin        '" << titel << "' wird vernichtet!" << endl;
}

void CMagazine::print()
{
	cout << "Designer:    " << Designer << endl;
	cout << "Anz. Seiten: " << Pages << endl;
	cout << "Title:       " << titel << endl;
	cout << "Signatur:    " << signatur << endl;
	cout << "Ort:         " << ort << endl;
	cout << "FSK:         freigegeben ab " << altersfreigabe << " Jahren" << endl;
	cout << "Status:      " << getstatus() << endl;
	cout << "\n";
}

ostream& CMagazine::print(ostream& outs) {
	outs << "Designer:    " << Designer << endl;
	CPrintedMedium::print(outs);
	return outs;
}

ostream& operator<<(ostream& outs, CMagazine& Med) {
	return Med.print(outs);
}
