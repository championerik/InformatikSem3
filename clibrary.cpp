#include "clibrary.h"



CLibrary::CLibrary() {}
CLibrary::CLibrary(string fil, CAddress addr, CEmployee* chef) : filiale(fil), adresse(addr), leiter(chef) {}

void CLibrary::add(CMedium* medium) {
	medienliste.push_back(medium);
}

void CLibrary::print() {
	cout << "Buecherei Filiale " << filiale << endl;
	adresse.print(); cout << endl;
	cout << "Filialleiter: "; leiter->print(); cout << endl;
	cout << "Es stehen " << medienliste.size() <<" Medien zur Verfuegung:" << endl;
	cout << "\n";
	for (int i = 0; i < medienliste.size(); i++) {
		cout << "Medium Nr. " << i + 1 << endl;
		medienliste[i]->print();
	}
}

ostream& operator<<(ostream& outs, CLibrary& Lib)
{
	outs << "Buecherei Filiale " << Lib.filiale << endl;
	outs << Lib.adresse << endl;
	outs << "Filialleiter: " << *(Lib.leiter) << endl;
	outs << "Es stehen " << Lib.medienliste.size() <<" Medien zur Verfuegung: " << endl;
	outs << "\n";
	for (int i = 0; i < Lib.medienliste.size(); i++) {
		outs << "Medium Nr. " << i + 1 << endl;
		outs << *(Lib.medienliste[i]);
		outs << "\n";
	}
	return outs;
}



void CLibrary::load(ifstream* data) {
	char text[101];
	while (data->getline(text, 100, '\n')) {
		string tmp(text);
		if (!(tmp.find("<Name>") == string::npos)) {
			filiale = parseLine(tmp);
		}
		else if (!(tmp.find("<Address>") == string::npos)) {
			adresse.load(data);
		}
		else if (!(tmp.find("<Book>") == string::npos)) {
			CBook* dummyMed = new CBook();
			if (dummyMed) {
				dummyMed->load(data);
				add(dummyMed);
			}
		}
		else if (!(tmp.find("<CD>") == string::npos)) {
			CCD* dummyMed = new CCD();
			if (dummyMed) {
				dummyMed->load(data);
				add(dummyMed);
			}
		}
		else if (!(tmp.find("<DVD>") == string::npos)) {
			CDVD* dummyMed = new CDVD();
			if (dummyMed) {
				dummyMed->load(data);
				add(dummyMed);
			}
		}
		else if (!(tmp.find("<Magazine>") == string::npos)) {
			CMagazine* dummyMed = new CMagazine();
			if (dummyMed) {
				dummyMed->load(data);
				add(dummyMed);
			}
		}
		else if (!(tmp.find("<Audiobook>") == string::npos)) {
			CAudiobook* dummyMed = new CAudiobook();
			if (dummyMed) {
				dummyMed->load(data);
				add(dummyMed);
			}
		}
		else if (!(tmp.find("<Manager>") == string::npos)) {
			leiter = new CEmployee();
			if (leiter) {
				leiter->load(data);
			}
		}
		else if (!(tmp.find("</Library>") == string::npos)) {
			break;
		}
	}
}

void CLibrary::clearMedienListe() {
    for (int i = 0; i < medienliste.size(); i++) {
        delete medienliste[i];
    }
}

vector<CMedium*> CLibrary::getMediumlist()
{
	return medienliste;
}

CLibrary::~CLibrary(){
	delete leiter;
}
