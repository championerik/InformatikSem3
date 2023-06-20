#ifndef CMEDIUM_H
#define CMEDIUM_H
#include "clocation.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include "clocation.h"
#include "tools.h"

class CMedium {
	protected:
		string titel, signatur;
		CLocation ort;
		int altersfreigabe;
	public:
		enum status{verfuegbar, ausgeliehen, bestellt, reserviert, NA};
		status Status;

		virtual ~CMedium();
		CMedium();
		CMedium(string, string, CLocation, int, status);

		virtual void print();
		virtual void load(ifstream*);

		string getstatus();
		status getstatus(int);
};
#endif
