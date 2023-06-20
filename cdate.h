#ifndef CDATE_H
#define CDATE_H
#include <iostream>
#include <fstream>

#include <ctime>
#include <cstdio>
#include <sys/types.h>
#include "tools.h"

using namespace std;

class CDate {
private: int day, month, year;
public:
	CDate();
	CDate(int, int, int);
	void setDate(int, int, int);
	void setCurrentDate(int, int, int);
	void print();
	void load(ifstream*);
};
#endif
