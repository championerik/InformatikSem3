#include <iostream>

using namespace std;

//#include "clibrarypool.h"
#include "../../../clibrarypool.h"

int main()
{
	CLibraryPool LP("data.xml"); //data05.xml old

	cout << LP << endl;
	

	return 0;
}