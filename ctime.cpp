#include "ctools.h"
#include <fstream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
#include "ctime.h"
#include <iostream>

CTime::CTime() {
	time_t NOW = time(nullptr);
	struct tm* t = localtime(&NOW);
	hour = t->tm_hour;
	minute = t->tm_min;
	second = t->tm_sec;
}
CTime::CTime(int h, int min, int s) : hour(h), minute(min), second(s) {}

void CTime::load(ifstream* data){
	string zeile;
	getline(*data,zeile); //Skip von <Time>

	while (getline(*data,zeile)){
		if (!(zeile.find("<Hour>") == string::npos)){
			hour = stoi(parseLine(zeile));
		}
		else if (!(zeile.find("<Minute>") == string::npos)){
			minute = stoi(parseLine(zeile));
		}
		else if (!(zeile.find("<Seconds>") == string::npos)){
			second = stoi(parseLine(zeile));
		}
		else if (!(zeile.find("</Time>") == string::npos)) {
			break;
		}
	}

	getline(*data,zeile); //Skip von </Time>
}
void CTime::setTime(int H, int M, int S) {
	hour = H;
	minute = M;
	second = S;
}


void CTime::print() {
	char old = cout.fill();
	cout.fill('0');
	cout.width(2);
	cout << hour << ":" << minute << ":" << second;
	cout.fill(old);
}

ostream& operator<<(ostream& outs, CTime& item)
{
	char old = outs.fill();
	outs.fill('0');
	outs.width(2);
	outs << item.hour << ":" << item.minute << ":" << item.second;
	outs.fill(old);
	return outs;
	// TODO: hier return-Anweisung eingeben
}
