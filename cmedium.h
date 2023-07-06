#pragma once
#ifndef CMEDIUM_H
#define CMEDIUM_H
#include <string>
#include "clocation.h"
#include "ctools.h"



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
		CMedium(string);

		virtual void print();
		virtual ostream& print(ostream&);
		virtual void load(ifstream*);
		virtual ~CMedium();

		string getstatus();
		status getstatus(int);
		void setstatus(int);
		void setstatus(status);

		void setsig(string);
		string getsig()	{return signatur;}



		friend ostream& operator<<(ostream&, CMedium&);
};
#endif
