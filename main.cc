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
	// Read in argument and open file
	char* fname = argv[1];
	ifstream file(fname);

	// If file could not open, print error and exit
	if (!file)
	{
		cout << "File not found: " << fname << endl;
		return 1;
	} 
	else
	{
		cout << "Reading file [" << fname << "]" << endl << endl;
	}

	// Read file contents into program, and catch errors in file
	try {
		file >> P;
	} catch (BadFileException e) {
		cout << endl << "Bad file" << endl << endl;
		return 1;
	} catch (BadCommandException e) {
		cout << endl << "Bad command" << endl << endl;
		return 1;
	}

	// Executes window
	window w(argc, argv);

	return 0;
}

// Runs list of commands
void draw()
{
	cout << endl << "Drawing..." << endl;
	P.run();
	cout << endl;
}
