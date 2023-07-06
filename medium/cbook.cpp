#include "cbook.h"
#include <fstream>
#include <string>

CBook::CBook()				: Autor("Kein Autor hinterlegt") {}
CBook::CBook(string aut)	: Autor(aut) {}

void CBook::load(ifstream* data){
	char text[101];
	while(data->getline(text, 100, '\n')){
		string tmp(text);
		if(!(tmp.find("<Author>") == string::npos)){
			Autor = parseLine(tmp);
		}
		else if (!(tmp.find("<Pages>") == string::npos)){
			Pages = stoi(parseLine(tmp));
		}
		else if (!(tmp.find("<Title>") == string::npos)){
			titel = parseLine(tmp);
		}
		else if (!(tmp.find("<Signatur>") == string::npos)) {
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
		else if (!(tmp.find("</Book>") == string::npos)){
			break;
		}
	}
}

void CBook::print() {
	cout << "Autor:       " << Autor << endl;
	cout << "Anz. Seiten: " << Pages << endl;
	cout << "Title:       " << titel << endl;
	cout << "Signatur:    " << signatur << endl;
	cout << "Ort:         " << ort << endl;
	cout << "FSK:         freigegeben ab " << altersfreigabe << " Jahren" << endl;
	cout << "Status:      " << getstatus() << endl;
	cout << "\n";	
}

CBook::~CBook() {
	cout << "Das Buch           '" << titel << "' wird vernichtet!" << endl;
}

ostream& CBook::print(ostream& outs) {
	outs << "Autor:       " << Autor << endl;
	CPrintedMedium::print(outs);
	return outs;
}

ostream& operator<<(ostream& outs, CBook& Med) {
	return Med.print(outs);
}
