#include "cloan.h"

CLoan::CLoan(){
}

CLoan::CLoan(CPerson* p): Medium(new CMedium()), Customer(p), LoanDate(CDate()), Expiration(CDate()) {}

string CLoan::load(ifstream* data) {
	string tmp;
	string customerNr;
		while (getline(*data, tmp)) {
			if (!(tmp.find("<LoanDate>") == string::npos)) {
				LoanDate.load(data);
			}
			else if (!(tmp.find("<Signature>") == string::npos)) {
				Medium = new CMedium();
				Medium->setsig(parseLine(tmp));
			}
			else if (!(tmp.find("<CustomerNr>") == string::npos)) {
				customerNr = parseLine(tmp);
			}
			else if (!(tmp.find("<LoanDays>") == string::npos)) {
				int zeitadd = stoi(parseLine(tmp));
				Expiration = LoanDate;
				Expiration += zeitadd;
			}
			else if (!(tmp.find("</Loan>") == string::npos)) {
				return customerNr;
			}
		}
}
void CLoan::setMedium(CMedium* newitem)
{
	Medium = newitem;
}
void CLoan::setCustomer(CPerson* newperson)
{
	Customer = newperson;
}
CMedium* CLoan::getMedium()
{
	return Medium;
}
CPerson* CLoan::getCustomer()
{
	return Customer;
}
ostream& CLoan::print(ostream& outs) {
	outs << "Ausleihe vom " << LoanDate << endl;
	outs << "Rueckgabe bis spaetestens " << Expiration << endl;
	outs << *(Medium);
	outs << "ausgeliehen von " << Customer->getName() << endl;
	outs << "\n";
	return outs;
	
}

ostream& operator<<(ostream&outs, CLoan& item)
{
	return item.print(outs);
	// TODO: hier return-Anweisung eingeben
}
