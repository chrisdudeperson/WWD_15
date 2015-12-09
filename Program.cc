#include <iostream>
#include <string>

#include "Program.hh"
#include "Repeat.hh"
#include "Rotate.hh"
#include "Translate.hh"

using namespace std;

//Default constructor
Program::Program()
{
}

//Destructor
Program::~Program()
{
	for (int i(0); i < commands.size(); i++) {
		delete commands[i];
	}
}

void Program::run()
{
	for (int i(0); i<commands.size(); i++) {
		commands[i]->exec();
	}
}

istream& operator>> (istream& in, Program& p)
{
	string s;
	double arg;
	Command* p_cmd;

	while (!in.eof() && s != "]") {
		in >> ws >> s >> ws;

		if (s != "]") {
			in >> ws >> arg >> ws;

			if (!in.fail()) {
				if (s == "FORWARD") {
					cout << "FOWARD [" << arg << "]" << endl;
					p_cmd = new Translate(arg, true);
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
						throw BadCommandException();	//Invalid repeat command
					}
					p_cmd = new Repeat(arg, in);
				}
				else {
					cout << "Unrecognised command [ " << s << " ]" << endl;
					if (!in.eof()) {
						throw BadCommandException();	//Invalid command in file
					}
					else {
						cout << "EOF Reached" << endl;
					}
				}
				
				//Slice the command back to the base object and push to the vector
				p.commands.push_back(p_cmd);
			}
			else {
				if (in.fail() && s != "]") {
					throw BadFileException();	//Read failed due to bad file
				}
				if (in.eof()) {
					cout << "Finished reading file!" << endl;
				}
			}
		}
	}
	return in;
}
