#include "tools.h"

string parseLine(string zeile) {
	string content;
	int start = zeile.find('>') + 1;
	int ende = zeile.rfind('<');
	content = zeile.substr(start, ende - start);
	return content;
}
