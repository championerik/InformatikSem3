#include "ccd.h"
#include <fstream>
#include <string>

CCD::CCD()						: Interpret("Kein Interpret hinterlegt"), Tracks(-1) {}
CCD::CCD(string inter, int tra) : Interpret(inter), Tracks(tra) {}

void CCD::load(ifstream* data){
	char text[101];
	while (data->getline(text, 100, '\n')){
		string tmp(text);
		if (!(tmp.find("<Title>") == string::npos)){
			titel = parseLine(tmp);
		}
		else if (!(tmp.find("<Signatur>") == string::npos)){
			signatur = parseLine(tmp);
		}
		else if (!(tmp.find("<Location>") == string::npos)){
			ort.load(data);
		}
		else if (!(tmp.find("<Status>") == string::npos)){
			Status = getstatus(stoi((parseLine(tmp))));
		}
		else if (!(tmp.find("<Interpret>") == string::npos)){
			Interpret = parseLine(tmp);
		}
		else if (!(tmp.find("<Tracks>") == string::npos)){
			Tracks = stoi(parseLine(tmp));
		}
		else if (!(tmp.find("</CD>") == string::npos)) {
			break;
		}
	}
}

void CCD::print() {
	cout << "Interpret:   " << Interpret << endl;
	cout << "Anz. Tracks: " << Tracks << endl;
	cout << "Title:       " << titel << endl;
	cout << "Signatur:    " << signatur << endl;
	cout << "Ort:         " << ort << endl;
	cout << "FSK:         freigegeben ab " << altersfreigabe << " Jahren" << endl;
	cout << "Status:      " << getstatus() << endl;
	cout << "\n";
}

ostream& operator<<(ostream& outs, CCD& Med) {

	return(outs << "Interpret:   " << Med.Interpret << endl
				<< "Anz. Tracks: " << Med.Tracks << endl
				<< static_cast<CMedium&>(Med));
}

CCD::~CCD() {
	cout << "Die CD             '" << titel << "' wird vernichtet!" << endl;
}
