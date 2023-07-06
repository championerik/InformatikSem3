#pragma once
#ifndef CDATE_H
#define CDATE_H
#include <fstream>
#include <iostream>
#include <iomanip>
#include "ctools.h"

using namespace std;

class CDate {
private: int day, month, year;
public:
	CDate();
	CDate(int, int, int);
	void setDate(int, int, int);
	void setCurrentDate();
	void print();
	void load(ifstream*);



	friend ostream& operator<<(ostream&, const CDate&);
	CDate& operator++(int);
	CDate& operator+=(int);
};
#endif
