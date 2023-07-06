#pragma once
#ifndef CTIME_H
#define CTIME_H
#include <fstream>
#include <iomanip>
#include "ctools.h"
using namespace std;
class CTime{
private: int hour, minute, second;
public:
	CTime();
	CTime(int, int, int = 0);
	void setTime(int, int, int = 0);
	void print();
	void load(ifstream*);

	friend ostream& operator<<(ostream&, CTime&);
};
#endif
