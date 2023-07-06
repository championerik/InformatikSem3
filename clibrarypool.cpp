#include "clibrarypool.h"
#include "cloan.h"



CLibraryPool::CLibraryPool(string buech, CEmployee* ch) : buechereiverbund(buech), chef(ch) {}

CLibraryPool::CLibraryPool(string data) {
	ifstream quelle;
	cout << "Datei: " << data << " wird geoeffnet - ";
	if (!data.find(".xml")) {
		cout << "error" << endl << "Keine gueltige XML-Datei";
		exit(1);
	}
	quelle.open(data);
	if (quelle) {
		cout << "ok" << endl << "Datei wird eingelesen - ";
		char text[101];
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
			else if (!(tmp.find("<Loan>") == string::npos)) {
				CLoan* dummyloan = new CLoan(new CCustomer());
				if (dummyloan) {
					string tag = dummyloan->load(&quelle);
					dummyloan->getCustomer()->setCustNr(tag);
					LoanList.push_back(dummyloan);
				}
			}

			else if (!(tmp.find("</LibraryPool>") == string::npos)) {
				cout << " ok" << endl << endl;
				break;
			}
		}
		quelle.close();

		for (CList<CLoan*>::iterator it = LoanList.begin(); it != LoanList.end(); it++) {
			if (mapLoans(*it)) {
				cout << "Kunde/Medium nicht gefunden" << endl;
			}
		}

	}
}

CLibraryPool::~CLibraryPool() {
	for (int i = 0; i < filialenliste.size(); i++) {
		filialenliste[i]->clearMedienListe(); // Angenommen, es gibt eine Funktion zum Löschen der Medienliste in der Klasse CLibrary
		delete filialenliste[i];
	}
    for (int i = 0; i < kundenliste.size(); i++) {
        delete kundenliste[i];
    }
	for (CList<CLoan*>::iterator it = LoanList.begin(); it != LoanList.end(); it++) {
		LoanList.erase(it);
	}
	delete chef;
}

void CLibraryPool::add(CLibrary* filiale) {
	filialenliste.push_back(filiale);
}
void CLibraryPool::add(CCustomer* kunde) {
	kundenliste.push_back(kunde);
}
/*
void CLibraryPool::add(CLoan* item) {
	leihliste.push_back(item);
}

void CLibraryPool::mapLoans() {
	string sigA, sigB;
	for (int i = 0; i < leihliste.size(); i++) {
		for (int j = 0; j < filialenliste.size(); j++){
			vector<CMedium*> medlist = filialenliste[j]->getMediumlist();
			for (int k = 0; k < medlist.size(); k++)
			{
				sigA = medlist[k]->getsig();
				CMedium* sigBl = leihliste[i]->getMedium();
				sigB = sigBl->getsig();
				if ( sigA == sigB )
				{
					CMedium* medium = leihliste[i]->getMedium();
					leihliste[i]->setMedium(medlist[k]);
					medlist[k]->setstatus(CMedium::status::ausgeliehen);
					delete medium;
					break;
				}
			}
			if (sigA == sigB)
				break;
		}
		for (int l = 0; l < kundenliste.size(); l++) {
			string CustA = kundenliste[l]->getCustNr();
			string CustB = leihliste[i]->getCustomer()->getCustNr();
			if (CustA == CustB) {
				CPerson* pers = leihliste[i]->getCustomer();
				leihliste[i]->setCustomer(kundenliste[l]);
				delete pers;
				break;
			}
		}
	}
}
*/

int CLibraryPool::mapLoans(CLoan* loan) {
	int check1 = 1, check2 = 1;
	for (int i = 0; i < kundenliste.size(); i++) {
		string CustA = kundenliste[i]->getCustNr();
		CPerson* CustBl = loan->getCustomer();
		string CustB = CustBl->getCustNr();
		if (CustA == CustB) {
			delete loan->getCustomer();
			loan->setCustomer(kundenliste[i]);
			check1 = 0;
			break;
		}
	}
	for (int i = 0; i < filialenliste.size(); i++) {
		vector<CMedium*> medien = filialenliste[i]->getMediumlist();
		for (int j = 0; j < medien.size(); j++) {
			if (medien[j]->getsig() == loan->getMedium()->getsig()) {
				delete loan->getMedium();
				loan->setMedium(medien[j]);
				medien[j]->setstatus(1);
				check2 = 0;
				break;
			}
		}
	}

	return check1 | check2;
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
	return Pool.print(outs);
}

ostream& CLibraryPool::print(ostream& outs){
	outs << buechereiverbund << endl;
	outs << *(chef) << endl;
	outs << "Zum Buechereiverband gehoeren " << filialenliste.size() << " Filialen:" << endl;
	outs << "\n";
	for (int i = 0; i < filialenliste.size(); i++) {
		outs << *(filialenliste[i]);
	}
	cout << "Der Buechereiverbund hat " << kundenliste.size() << " Kunden:" << endl;
	cout << "\n";
	for (int j = 0; j < kundenliste.size(); j++) {
		outs << *(kundenliste[j]);
	}
	cout << "Folgende " << LoanList.size() << " Medien sind ausgeliehen:" << endl;
	cout << "\n";
	for (CList<CLoan*>::iterator it = LoanList.begin(); it != LoanList.end(); it++) {
		cout << **it << endl;
	}
	return outs;
}
