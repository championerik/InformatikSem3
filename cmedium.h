#ifndef CMEDIUM_H
#define CMEDIUM_H
#include "clocation.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>

#include "tools.h"


class CMedium {
	protected:
		string titel, signatur;
		CLocation ort;
		int altersfreigabe;
	public:
		enum status{verfuegbar, ausgeliehen, bestellt, reserviert, NA};
		status Status;

		CMedium();
		CMedium(string, string, CLocation, int, status);

		virtual void print();
		virtual ostream& print(ostream&);
		virtual void load(ifstream*);
		virtual ~CMedium();

		string getstatus();
		status getstatus(int);

		friend ostream& operator<<(ostream&, CMedium&);
};
#endif
