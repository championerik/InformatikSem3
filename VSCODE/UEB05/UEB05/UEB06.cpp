#include <iostream>

using namespace std;

//#include "clibrarypool.h"
#include "../../../clibrarypool.h"

int main()
{
	CLibraryPool LP("data.xml");

	LP.print();
	cout << endl;
	
	//cout << LP << endl;
	

	return 0;
}