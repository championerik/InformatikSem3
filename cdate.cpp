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

bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void CDate::setCurrentDate() {
	time_t now = time(0);
	struct tm* t = localtime(&now);
	day = t->tm_mday;
	month = t->tm_mon + 1;
	year = t->tm_year + 1900;
}
void CDate::setDate(int D, int M, int Y) {
	day = D;
	month = M;
	year = Y;
}


CDate& CDate::operator++(int)
{
	int daysInMonth = 0;

	if (month == 2) {
		if (isLeapYear(year)) {
			daysInMonth = 29;
		}
		else {
			daysInMonth = 28;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		daysInMonth = 30;
	}
	else {
		daysInMonth = 31;
	}

	if (day < daysInMonth) {
		day++;
	}
	else {
		day = 1;
		if (month < 12) {
			month++;
		}
		else {
			month = 1;
			year++;
		}
	}

	return *this;
}

CDate& CDate::operator+=(int days)
{
	for (int i = 0; i < days; i++) {
		(*this)++;
	}
	return *this;
}

ostream& operator<<(ostream& outs, const CDate& item)
{
	char old = outs.fill();
	outs.fill('0');
	outs.width(2);
	outs << item.day << "." << item.month << "." << item.year;
	outs.fill(old);
	return outs;
}