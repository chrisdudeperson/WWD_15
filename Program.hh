#ifndef __PROGRAM_HH__
#define __PROGRAM_HH__

#include <iostream>
#include <vector>
#include <map>

#include "Command.hh"

class BadFileException{};
class BadCommandException{};

class Program{
private:
    std::vector<Command *> commands;

public:
	//Default constructor
	Program();

	//Destructor
	~Program();

	//Executes each command in turn
	void run();

    friend std::istream& operator>> (std::istream& in, Program& p);
};

#endif /*__PROGRAM_HH__*/