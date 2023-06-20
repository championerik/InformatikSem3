#ifndef CLIBRARY_H
#define CLIBRARY_H
#include <string>
#include "cemployee.h"
#include "cperson.h"
#include "cmedium.h"
#include "cemployee.h"
#include "caddress.h"

#include "medium/cbook.h"
#include "medium/cdvd.h"
#include "medium/cmagazine.h"
#include "medium/ccd.h"
#include "medium/caudiobook.h"

#include <vector>
#include <iostream>
#include <fstream>

#include "tools.h"
#include <cstdio>

class CLibrary {
	private:
		string filiale;
		CAddress adresse;
		CEmployee* leiter;
		vector<CMedium *> medienliste;
	public:
		CLibrary();
		CLibrary(string, CAddress, CEmployee*);
		~CLibrary();
		void add(CMedium *);
		void print();
		void load(ifstream*);
		void clearMedienListe();

		friend ostream& operator<<(ostream&, CLibrary&);
};
#endif
