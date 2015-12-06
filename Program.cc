<<<<<<< HEAD
=======
<<<<<<< HEAD
#include "Program.hh"

Program::Program()
{
}

Program::~Program()
{
}

void Program::run()
{
=======
>>>>>>> origin/master
#include <iostream>
#include <string>
#include <map>

#include "Program.hh"

using namespace std;

//Default constructor
Program::Program(){

}

//Destructor
Program::~Program(){
	//check for npe
    //delete commands;
}

void Program::run(){

}

istream& operator>> (istream& in, Program& p){
	static enum commandString {
		NOTDEFINED,
		FORWARD,
		JUMP,
		LEFT,
		RIGHT,
		REPEAT
	};
	static std::map<std::string, commandString> commandStringMap = {
		{"FORWARD",	FORWARD},
		{"JUMP",	JUMP},
		{"LEFT",	LEFT},
		{"RIGHT",	RIGHT},
		{"REPEAT",	REPEAT}
	};
	string s;
	int arg;


	while (!in.eof()) {
		in >> s;
		in >> arg;
		if (!in.fail()){
			//cout << "Switching on: " << s << " Maps to: " << commandStringMap[s] << endl;
			switch (commandStringMap[s]){
				case FORWARD:
					cout<< "create a forward command with argument [" << arg << "]" << endl;
					break;
				case JUMP:
					cout<< "create a jump command with argument [" << arg << "]" << endl;
					break;
				case LEFT:
					cout<< "create a left command with argument [" << arg << "]" << endl;
					break;
				case RIGHT:
					cout<< "create a right command with argument [" << arg << "]" << endl;
					break;
				case REPEAT:
					cout<< "create a repeat command with argument [" << arg << "]" << endl;
					break;
				default:
					cout << "Unrecognised command [" << s << "]" << endl;
					if (!in.eof()){
						//There is something wrong with the file
						if (in.fail()){
							//Read failed due to bad file
						} else {
							//Invalid command in file
						}
					} else {
						cout << "EOF Reached" << endl;
					}
			}
		} else {
			if (in.eof())
				cout << "Finished reading file!" << endl;
		}
	}
	return in;
}