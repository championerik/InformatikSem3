#ifndef CLOCATION_H
#define CLOCATION_H
#include <string>
#include <cstdio>
#include <iostream>
#include <fstream>
#include "tools.h"

using namespace std;
class CLocation {
	private:
		string section, rack;
	public:
		CLocation();
		CLocation(string, string);
		void load(ifstream*);
		void print();
};

#endif
