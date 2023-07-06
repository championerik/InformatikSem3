#pragma once
#ifndef CLIBRARY_H
#define CLIBRARY_H
#include <string>
#include <vector>
#include "caddress.h"
#include "cperson.h"
#include "cmedium.h"
#include "ctools.h"
#include "cemployee.h"

#include "medium/cbook.h"
#include "medium/caudiobook.h"
#include "medium/ccd.h"
#include "medium/cdvd.h"
#include "medium/cmagazine.h"
#include "medium/cprintedmedium.h"


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

		vector<CMedium*> getMediumlist();

		friend ostream& operator<<(ostream&, CLibrary&);
};
#endif
