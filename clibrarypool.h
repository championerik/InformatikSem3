#ifndef CLIBRARYPOOL_H
#define CLIBRARYPOOL_H
#include <vector>
#include <string>
#include "ccustomer.h"
#include "cemployee.h"
#include "cperson.h"
#include "clibrary.h"
#include <cstdio>
#include <fstream>
#include <iostream>
#include "tools.h"

class CLibraryPool{
	private:
		string buechereiverbund;
		CEmployee* chef;
		string dateiname;
		vector<CLibrary *> filialenliste;
		vector<CCustomer *> kundenliste;
	public:
		CLibraryPool(string, CEmployee*);
		CLibraryPool(string);
		~CLibraryPool();
		void add(CLibrary*);
		void add(CCustomer*);
		void print();
		void load(ifstream);
		void parseline(string);

		friend ostream& operator<<(ostream&, CLibraryPool&);
};
#endif
