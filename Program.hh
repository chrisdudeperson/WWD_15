#ifndef Program_hh
#define Program_hh

#include <iostream>
#include <vector>

class Program{
private:
    std::vector<std::string> commands;

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