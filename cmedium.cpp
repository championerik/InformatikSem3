#include "cmedium.h"

CMedium::CMedium(): titel("Kein Titel angegeben"), signatur("Keine Signatur angegeben"), altersfreigabe(0), Status(verfuegbar) {return;}

CMedium::CMedium(string tit, string sig, CLocation o, int fsk, status stat) : titel(tit), signatur(sig), ort(o), altersfreigabe(fsk), Status(stat) {}

CMedium::CMedium(string sig): signatur(sig), Status(verfuegbar) {}

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

void CMedium::setstatus(status stat)
{
	switch (stat) {
	case NA: Status = NA;
		break;
	case verfuegbar: Status = verfuegbar;
		break;
	case ausgeliehen: Status = ausgeliehen;
		break;
	case bestellt: Status = bestellt;
		break;
	case reserviert: Status = reserviert;
		break;
	default: Status = NA;
	}
}

void CMedium::setstatus(int stat)
{
	switch (stat) {
	case -1: this->Status = NA; break;
	case 0:  this->Status = verfuegbar; break;
	case 1: this->Status = ausgeliehen; break;
	case 2: this->Status = bestellt; break;
	case 3: this->Status = reserviert; break;
	default: this->Status = NA; break;
	}
}

void CMedium::setsig(string newsig)
{
	signatur = newsig;
}


CMedium::~CMedium() {
	cout << "Das Medium         '" << titel << "' mit der Signatur '" << signatur << "' wird vernichtet!" << endl;
}

void CMedium::load(ifstream* data) {
	char text[101];
	while (data->getline(text, 100, '\n')) {
		string tmp(text);
		if (!(tmp.find("<Title>") == string::npos)) {
			titel = parseLine(tmp);
		}
		else if (!(tmp.find("<Signatur>") == string::npos)) {
			signatur = parseLine(tmp);
		}
		else if (!(tmp.find("<FSK>") == string::npos)) {
			altersfreigabe = stoi(parseLine(tmp));
		}
		else if (!(tmp.find("<Status>") == string::npos)) {
			Status = getstatus(stoi((parseLine(tmp))));
		}
		else if (!(tmp.find("<Location>") == string::npos)) {
			ort.load(data);
		}
		else if (!(tmp.find("</Medium>") == string::npos)) {
			break;
		}
	}
}

ostream& CMedium::print(ostream& outs) {
	return (outs << "Title:       " << titel << endl
			<< "Signatur:    " << signatur << endl
			<< "Ort:         " << ort << endl
			<< "FSK:         freigegeben ab " << altersfreigabe << " Jahren" << endl
			<< "Status:      " << getstatus() << endl
			<< "\n");
}

ostream& operator<<(ostream& outs, CMedium& Med)
{
	return Med.print(outs);
}

void CMedium::print() {
	cout << "Title:       " << titel << endl;
	cout << "Signatur:    " << signatur << endl;
	cout << "Ort:         " << ort << endl;
	cout << "FSK:         freigegeben ab " << altersfreigabe << " Jahren" << endl;
	cout << "Status:      " << getstatus() << endl;
}

