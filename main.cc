#include <iostream>
#include <fstream>
#include <string>

#include "window.h"
#include "Translate.hh"
#include "Rotate.hh"
#include "Program.hh"

using namespace std;

Program P;

int main(int argc, char** argv)
{
	char* fname = argv[1];
	
	ifstream file(fname);

	if (!file)
	{
		cout << "File not found: " << fname << endl;
		return 1;
	}
	else
	{
		cout << "Reading file [" << fname << "]" << endl << endl;
	}

	try {
		file >> P;
	}
	catch (BadFileException e) {
		cout << endl << "Bad file" << endl << endl;
		return 1;
	}
	catch (BadCommandException e) {
		cout << endl << "Bad command" << endl << endl;
		return 1;
	}

	window w(argc, argv);

	return 0;
}

void draw()
{
	cout << endl << "Drawing..." << endl;
	P.run();
	cout << endl;
}