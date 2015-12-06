
#pragma once
#include <vector>
#include "Command.hh"

class Program
{
private:
	std::vector<Command> commands;

public:
	Program();
	~Program();
	void run();
};

#ifndef Program_hh
#define Program_hh

#include <iostream>
#include <vector>
#include <Command.h>

class Program{
private:
    std::vector<std::command> commands;

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

