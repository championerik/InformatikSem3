#ifndef CDVD_H
#define CDVD_H
#include "../ctime.h"
#include "../cmedium.h" //hier anpassen
#include <fstream>
class CDVD : virtual public CMedium {
private:
	string Actors;
	CTime PlayingTime;

public:
	CDVD();
	CDVD(string, CTime);
	void load(ifstream*);
	void print();
	virtual ostream& print(ostream&);
	virtual ~CDVD();

	explicit operator CDVD() const {
		CDVD dvd;
		return dvd;
	};
	friend ostream& operator<<(ostream&, CDVD&);
};

#endif
