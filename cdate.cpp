#define _CRT_SECURE_NO_WARNINGS
#include "cdate.h"

CDate::CDate() {
	time_t NOW = time(nullptr);
	struct tm* t = localtime(&NOW);
	day = t->tm_mday;
	month = t->tm_mon + 1;
	year = t->tm_year + 1900;
}
CDate::CDate(int d, int m, int y) : day(d), month(m), year(y) {}
void CDate::print() {
	char old = cout.fill();
	cout.fill('0');
	cout.width(2);
	cout << day << "." << month << "." << year;
	cout.fill(old);
}
void CDate::load(ifstream* data) {
	char text[101];
	while (data->getline(text, 100, '\n')) {
		string tmp(text);
		if (!(tmp.find("<Day>") == string::npos)) {
			day = stoi(parseLine(tmp));
		}
		else if (!(tmp.find("<Month>") == string::npos)) {
			month = stoi(parseLine(tmp));
		}
		else if (!(tmp.find("<Year>") == string::npos)) {
			year = stoi(parseLine(tmp));
		}
		else if (!(tmp.find("</Date>") == string::npos)) {
			break;
		}
	}
	return;
}

ostream& operator<<(ostream& outs, const CDate& item)
{
	char old = outs.fill();
	outs.fill('0');
	outs.width(2);
	outs << item.day << "." << item.month << "." << item.year;
	outs.fill(old);
	return outs;
	// TODO: hier return-Anweisung eingeben
}
