#include "cdvd.h"

CDVD::CDVD()						: Actors("Keine Schauspieler hinterlegt")  {} //PlayingTime(-1,-1,-1)
CDVD::CDVD(string act, CTime plTi)	: Actors(act), PlayingTime(plTi) {}

void CDVD::load(ifstream* data){
	char text[101];
	while (data->getline(text, 100, '\n')){
		string tmp(text);
		if (!(tmp.find("<Actors>") == string::npos)){
			Actors = parseLine(tmp);
		}
		else if (!(tmp.find("<PlayingTime>") == string::npos)){
			PlayingTime.load(data);
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
		else if (!(tmp.find("</DVD>") == string::npos)) {
			break;
		}
	}
}
void CDVD::print() {
	cout << "Schauspieler:" << Actors << endl;
	cout << "Spieldauer:  ";
	PlayingTime.print();
	cout << endl;
	cout << "Title:       " << titel << endl;
	cout << "Signatur:    " << signatur << endl;
	cout << "Ort:         " << ort << endl;
	cout << "FSK:         freigegeben ab " << altersfreigabe << " Jahren" << endl;
	cout << "Status:      " << getstatus() << endl;
	cout << "\n";
}

ostream& CDVD::print(ostream& outs) {
	outs << "Schauspieler:" << Actors << endl
		 << "Spieldauer:  " << PlayingTime << endl;
	CMedium::print(outs);
	return outs;
}
ostream& operator<<(ostream& outs, CDVD& Med) {
	return Med.print(outs);
}

CDVD::~CDVD() {
	cout << "Die DVD            '" << titel << "' wird vernichtet!" << endl;
}
