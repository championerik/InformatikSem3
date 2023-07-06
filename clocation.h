#pragma once
#ifndef CLOCATION_H
#define CLOCATION_H
#include <string>
#include "ctools.h"
#include <fstream>
#include <iostream>

using namespace std;
class CLocation {
	private:
		string section, rack;
	public:
		CLocation();
		CLocation(string, string);
		void load(ifstream*);
		void print();

		friend ostream& operator<<(ostream& stream, const CLocation& item);
};

#endif
