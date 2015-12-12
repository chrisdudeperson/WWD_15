#ifndef __PROGRAM_HH__
#define __PROGRAM_HH__

#include <vector>

#include "Command.hh"

class BadFileException{};
class BadCommandException{};

class Program{
private:
    std::vector<Command*> commands;

public:
	//Default constructor, inlined
	Program(){};

	//Destructor
	~Program();

	//Executes each command in turn
	void run();

	//Read commands into dynamicly allocated memory and store pointers to each command in the commands vector
	friend std::istream& operator>> (std::istream& in, Program& p);
};

#endif /*__PROGRAM_HH__*/