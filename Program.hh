#ifndef Program_hh
#define Program_hh

#include <iostream>
#include <vector>

class Program{
private:
    std::vector<std::string> commands;

	const enum commandString {
		NOTDEFINED,
		FORWARD,
		JUMP,
		LEFT,
		RIGHT,
		REPEAT
	};

	static std::map<std::string, commandString> commandStringMap;

public:
	//Default constructor
	Program();

	//Destructor
	~Program();

	//Executes each command in turn
	void run();

    friend std::istream& operator>> (std::istream& in, Program& p);
};

#endif