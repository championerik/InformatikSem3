#pragma once
#ifndef CLOAN_H
#define CLOAN_H
#include <string>
#include "cmedium.h"
#include "cperson.h"
#include "cdate.h"
#include "ctools.h"

class CLibraryPool;
class CLoan{
	private:
		CMedium* Medium;
		CPerson* Customer;
		CDate LoanDate, Expiration;

	public:
		CLoan();
		CLoan(CPerson*);
		//void load(ifstream*, CLibraryPool&);

		CMedium* getMedium();
		CPerson* getCustomer();
		string load(ifstream*);
		void setMedium(CMedium*);
		void setCustomer(CPerson*);

		
		friend ostream& operator<<(ostream&, CLoan&);
		virtual ostream& print(ostream&);
};
#endif // !CLOAN_H