#include <iostream>
#include <string>

#include "Program.hh"
#include "Repeat.hh"
#include "Rotate.hh"
#include "Translate.hh"

using std::string;
using std::istream;
using std::cout;
using std::ws;
using std::endl;

// Destructor
Program::~Program()
{
	// Iterates through commands and deletes eahc element
	for (int i(0); i < commands.size(); i++) {
		delete commands[i];
	}
}

//Executes each command in turn
void Program::run()
{
	for (int i(0); i<commands.size(); i++) {
		commands[i]->exec();
	}
}

//Read commands into dynamicly allocated memory and store pointers to each command in the commands vector
istream& operator>> (istream& in, Program& p)
{
	string s;
	double arg;
	Command* p_cmd;

	while (!in.eof() && s != "]") {
		in >> ws >> s >> ws;

		if (s != "]") { // ] signifies end of repeat commands
			in >> ws >> arg >> ws;

			if (!in.fail()) { // Dynamicly create memory for each command then create a Command* to it
				if (s == "FORWARD") {
					cout << "FOWARD [" << arg << "]" << endl;
					p_cmd = new Translate(arg, true); //true tells
				}
				else if (s == "JUMP") {
					cout << "JUMP [" << arg << "]" << endl;
					p_cmd = new Translate(arg, false);
				}
				else if (s == "LEFT") {
					cout << "LEFT [" << arg << "]" << endl;
					p_cmd = new Rotate(arg, true);
				}
				else if (s == "RIGHT") {
					cout << "RIGHT [" << arg << "]" << endl;
					p_cmd = new Rotate(arg, false);
				}
				else if (s == "REPEAT") {
					cout << "REPEAT [" << arg << "]" << endl;
					char b;
					in >> ws >> b >> ws;
					if (b != '['){
						throw BadCommandException();	// Invalid repeat command
					}
					p_cmd = new Repeat(arg, in);
				}
				else {
					cout << "Unrecognised command [ " << s << " ]" << endl;
					if (!in.eof()) {
						throw BadCommandException();	// Invalid command in file
					}
					else {
						cout << "EOF Reached" << endl;
					}
				}
				
				// Push the Command pointer to the vector
				p.commands.push_back(p_cmd);
			}
			else {
				if (in.fail() && s != "]") {
					throw BadFileException();	// Read failed due to bad file
				}
				if (in.eof()) {
					cout << "Finished reading file!" << endl;
				}
			}
		}
	}
	return in;
}
