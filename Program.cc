#include <iostream>
#include <string>
#include <map>

#include "Program.hh"

using namespace std;

class BadFileException{};
class BadCommandException{};

//Default constructor
Program::Program(){
	commandStringMap = {
		{ "FORWARD", FORWARD },
		{ "JUMP", JUMP },
		{ "LEFT", LEFT },
		{ "RIGHT", RIGHT },
		{ "REPEAT", REPEAT }
	};
}

//Destructor
Program::~Program(){
	//check for npe
    //delete commands;
}

void Program::run(){

}

istream& operator>> (istream& in, Program& p){
	string s;
	int arg;

	while (!in.eof()) {
		in >> s;
		in >> arg;
		if (!in.fail()){
			//cout << "Switching on: " << s << " Maps to: " << commandStringMap[s] << endl;
			switch (Program::commandStringMap[s]){
			case Program::commandString::FORWARD:
					cout<< "create a forward command with argument [" << arg << "]" << endl;
					break;
			case Program::commandString::JUMP:
					cout<< "create a jump command with argument [" << arg << "]" << endl;
					break;
			case Program::commandString::LEFT:
					cout<< "create a left command with argument [" << arg << "]" << endl;
					break;
			case Program::commandString::RIGHT:
					cout<< "create a right command with argument [" << arg << "]" << endl;
					break;
			case Program::commandString::REPEAT:
					cout<< "create a repeat command with argument [" << arg << "]" << endl;
					break;
				default:
					cout << "Unrecognised command [" << s << "]" << endl;
					if (!in.eof()){
						//There is something wrong with the file
						if (in.fail()){
							//Read failed due to bad file
							throw BadFileException();
						} else {
							//Invalid command in file
							throw BadCommandException();
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