#include "caudiobook.h"
#include <fstream>
#include <string>

CAudiobook::CAudiobook()			: countCDs(-1) {}
CAudiobook::CAudiobook(int ctCD) 	: countCDs(ctCD) {}

void CAudiobook::load(ifstream* data){
	char text[101];
	while (data->getline(text, 100, '\n')){
		string tmp(text);
		if (!(tmp.find("<Title>") == string::npos)){
			titel = parseLine(tmp);
		}
		else if (!(tmp.find("<Signatur>") == string::npos)){
			signatur = parseLine(tmp);
		}
		else if (!(tmp.find("<Author>") == string::npos)){
			Autor = parseLine(tmp);   //hier aufpassen, fuer paul autor musste protected
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
		else if (!(tmp.find("<countCDs>") == string::npos)){
			countCDs = stoi(parseLine(tmp));
		}
		else if (!(tmp.find("<Pages>") == string::npos)) {
			Pages = stoi(parseLine(tmp));
		}

		else if (!(tmp.find("</Audiobook>") == string::npos)){
			break;
		}
	}
}

void CAudiobook::print() {
	cout << "Interpret:   " << Interpret << endl;
	cout << "Anz. Tracks: " << Tracks << endl;
	cout << "Anz. CDs:    " << countCDs << endl;
	cout << "Title:       " << titel << endl;
	cout << "Signatur:    " << signatur << endl;
	cout << "Ort:         "; ort.print(); cout << endl;
	cout << "FSK:         freigegeben ab " << altersfreigabe << " Jahren" << endl;
	cout << "Status:      " << getstatus() << endl;
	cout << "\n";
}


CAudiobook::~CAudiobook() {
	cout << "Das Audiobuch      '" << titel << "' wird vernichtet!" << endl;
}
