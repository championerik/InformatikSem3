#ifndef CTIME_H
#define CTIME_H
#include <iostream>
#include <ctime>
#include <cstdio>
#include <sys/types.h>
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
