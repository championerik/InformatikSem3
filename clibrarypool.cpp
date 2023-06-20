#include "clibrarypool.h"
#include "ccustomer.h"
#include "cemployee.h"
#include "clibrary.h"

CLibraryPool::CLibraryPool(string buech, CEmployee* ch) : buechereiverbund(buech), chef(ch) {}

CLibraryPool::CLibraryPool(string data) {
	ifstream quelle;
	char text[101];
	quelle.open(data);
	if (quelle) {
		while (quelle.getline(text, 100, '\n')) {
			string tmp(text);
			if (!(tmp.find("<Name>") == string::npos)) {
				buechereiverbund = parseLine(tmp);
			}
			else if (!(tmp.find("<Chairman>") == string::npos)) {
				chef = new CEmployee();
				if (chef) {
					chef->load(&quelle);
				}
			}
			else if (!(tmp.find("<Library>") == string::npos)) {
				CLibrary* dummylib = new CLibrary();
				if (dummylib) {
					dummylib->load(&quelle);
					add(dummylib);
				}
			}
			else if (!(tmp.find("<Customer>") == string::npos)) {
				CCustomer* dummyCust = new CCustomer();
				if (dummyCust) {
					dummyCust->load(&quelle);
					add(dummyCust);
				}
			}
			else if (!(tmp.find("</LibraryPool>") == string::npos)) {
				break;
			}
		}
		quelle.close();

	}
}

CLibraryPool::~CLibraryPool() {
    delete chef;
	for (int i = 0; i < filialenliste.size(); i++) {
		filialenliste[i]->clearMedienListe(); // Angenommen, es gibt eine Funktion zum Löschen der Medienliste in der Klasse CLibrary
		delete filialenliste[i];
	}
    for (int i = 0; i < kundenliste.size(); i++) {
        delete kundenliste[i];
    }
}

void CLibraryPool::add(CLibrary* filiale) {
	filialenliste.push_back(filiale);
}
void CLibraryPool::add(CCustomer* kunde) {
	kundenliste.push_back(kunde);
}
void CLibraryPool::print() {
	cout << buechereiverbund << endl;
	cout << "Leitung "; chef->print();
	cout << "Zum Buechereiverband gehoeren " << filialenliste.size() << " Filialen:" << endl;
	cout << "\n";
	for (int i = 0; i < filialenliste.size(); i++) {
		filialenliste[i]->print();
	}
	cout << "Der Buechereiverbund hat "<< kundenliste.size() <<" Kunden:" << endl;
	cout << "\n";
	for (int j = 0; j < kundenliste.size(); j++) {
		kundenliste[j]->print();
	}
}

ostream& operator<<(ostream& outs, CLibraryPool& Pool)
{
	outs << Pool.buechereiverbund << endl;
	outs << *(Pool.chef) << endl;
	outs << "Zum Buechereiverband gehoeren " << Pool.filialenliste.size() << " Filialen:" << endl;
	outs << "\n";
	for (int i = 0; i < Pool.filialenliste.size(); i++) {
		outs << *(Pool.filialenliste[i]);
	}
	cout << "Der Buechereiverbund hat " << Pool.kundenliste.size() << " Kunden:" << endl;
	cout << "\n";
	for (int j = 0; j < Pool.kundenliste.size(); j++) {
		outs << *(Pool.kundenliste[j]);
	}

	return outs;
}
