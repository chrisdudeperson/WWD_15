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