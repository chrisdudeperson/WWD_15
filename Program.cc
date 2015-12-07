#include <iostream>
#include <string>

#include "Program.hh"

using namespace std;

class BadFileException{};
class BadCommandException{};

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
	string s;
	int arg;

	while (!in.eof()) {
		in >> s;
		in >> arg;
		if (!in.fail()){
			//cout << "Switching on: " << s << " Maps to: " << commandStringMap[s] << endl;
            if (s == "FORWARD"){
                cout<< "create a forward command with argument [" << arg << "]" << endl;
            } else if (s == "JUMP"){
                cout<< "create a jump command with argument [" << arg << "]" << endl;
			} else if (s == "LEFT"){
				cout<< "create a left command with argument [" << arg << "]" << endl;
			} else if (s == "RIGHT"){
				cout<< "create a right command with argument [" << arg << "]" << endl;
			} else if (s == "REPEAT"){
				cout<< "create a repeat command with argument [" << arg << "]" << endl;
			} else {
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