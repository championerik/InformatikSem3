#include "cmedium.h"

CMedium::CMedium(): titel("Kein Titel angegeben"), signatur("Keine Signatur angegeben"), altersfreigabe(0), Status(NA) {return;}

CMedium::CMedium(string tit, string sig, CLocation o, int fsk, status stat) : titel(tit), signatur(sig), ort(o), altersfreigabe(fsk), Status(stat) {}

string CMedium::getstatus() {
	switch (Status) {
	case verfuegbar: return "verfuegbar";
		break;
	case ausgeliehen: return "ausgeliehen";
		break;
	case bestellt: return "bestellt";
		break;
	case reserviert: return "reserviert";
		break;
	case NA: return "nicht verfuegbar";
		break;
	default: return "N/A";
	}
}
CMedium::status CMedium::getstatus(int stat) {
	switch (stat) {
	case -1: return status::NA;
		break;
	case 0: return status::verfuegbar;
		break;
	case 1: return status::ausgeliehen;
		break;
	case 2: return status::bestellt;
		break;
	case 3: return status::reserviert;
		break;
	default: return status::NA;
	}
}

CMedium::~CMedium() {
	cout << "Das Medium         '" << titel << "' mit der Signatur '" << signatur << "' wird vernichtet!" << endl;
}

void CMedium::load(ifstream* data) {
	string zeile;


	while (getline(*data, zeile)) {

		if (!(zeile.find("<Title>") == string::npos)) {
			titel = parseLine(zeile);
		}
		else if (!(zeile.find("<Signatur>") == string::npos)) {
			signatur = parseLine(zeile);
		}
		else if (!(zeile.find("<FSK>") == string::npos)) {
			altersfreigabe = stoi(parseLine(zeile));
		}
		else if (!(zeile.find("<Status>") == string::npos)) {
			int hallo = stoi((parseLine(zeile)));
			Status = getstatus(hallo);
		}
		else if (!(zeile.find("<Location>") == string::npos)) {
			ort.load(data);
		}
		else if (!(zeile.find("</Medium>") == string::npos)) {
			break;
		}
	}

}

ostream& operator<<(ostream& outs, const CMedium& Med)
{
	return (outs << Med << endl
				 << "Title:       " << Med.titel << endl
				 << "Signatur:    " << Med.signatur << endl
				 << "Ort:         " << Med.ort << endl
				 << "FSK:         freigegeben ab " << Med.altersfreigabe << " Jahren" << endl
				 << "Status:      " << Med.Status << endl
				 << "\n");
}

void CMedium::print() {
	cout << "Title:       " << titel << endl;
	cout << "Signatur:    " << signatur << endl;
	cout << "Ort:         " << ort << endl;
	cout << "FSK:         freigegeben ab " << altersfreigabe << " Jahren" << endl;
	cout << "Status:      " << getstatus() << endl;
	cout << "\n";
}

