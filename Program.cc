#include <iostream>
#include <string>

#include "Program.hh"
#include "Repeat.hh"
#include "Rotate.hh"
#include "Translate.hh"

using namespace std;

class BadFileException{};
class BadCommandException{};

//Default constructor
Program::Program(){
    
}

//Destructor
Program::~Program(){
	//check for npe
    //delete commands in vector
}

void Program::run(){
    for(int i(0); i<commands.size(); i++){
        cout << "Executing " << i << " command" << endl;
        commands[i]->exec();
    }
}

istream& operator>> (istream& in, Program& p){
	string s;
    double arg;
    Command* p_cmd;

    while (!in.eof() && s != "]") {
		in >> s;
        cout << "s: " << s << endl;
        if (s != "]"){
            in >> arg;
            if (!in.fail()){
                if (s == "FORWARD"){
                    cout<< "create a forward command with argument [" << arg << "]" << endl;
                    p_cmd = new Translate(arg, true);
                } else if (s == "JUMP"){
                    cout<< "create a jump command with argument [" << arg << "]" << endl;
                    p_cmd = new Translate(arg, false);
                } else if (s == "LEFT"){
                    cout<< "create a left command with argument [" << arg << "]" << endl;
                    p_cmd = new Rotate(arg, true);
                } else if (s == "RIGHT"){
                    cout<< "create a right command with argument [" << arg << "]" << endl;
                    p_cmd = new Rotate(arg, false);
                } else if (s == "REPEAT"){
                    cout<< "create a repeat command with argument [" << arg << "]" << endl;
                    Program re_cmds;
                    char b;
                    in>>ws>>b>>ws;
                    if (b != '['){
                        //Invalid repeat command
                        throw BadCommandException();
                    }
                    in >> re_cmds;
                    p_cmd = new Repeat(arg, re_cmds);
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
                //Slice the command back to the base object and push to the vector
                p.commands.push_back(p_cmd);
            } else {
                if (in.eof())
                    cout << "Finished reading file!" << endl;
            }
        }
        //cout << "Peek: " << in.peek() << endl;
	}
	return in;
}
