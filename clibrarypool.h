#ifndef CLIBRARYPOOL_H
#define CLIBRARYPOOL_H
#include <string>
#include <vector>
#include <fstream>
#include "clibrary.h"
#include "cemployee.h"
#include "ccustomer.h"
#include "cloan.h"
#include "clist.h"


class CLoan;
class CLibraryPool{
	protected:
		string buechereiverbund;
		CEmployee* chef;
		string dateiname;
		vector<CLibrary *> filialenliste;
		vector<CCustomer *> kundenliste;
		CList<CLoan*> LoanList;

		
	public:
		CLibraryPool(string, CEmployee*);
		CLibraryPool(string);
		~CLibraryPool();
		void add(CLibrary*);
		void add(CCustomer*);
		//void add(CLoan*);
		//void mapLoans();
		void print();

		ostream& print(ostream&);
		
		friend ostream& operator<<(ostream&, CLibraryPool&);

	private:
	int mapLoans(CLoan*);
};
#endif
