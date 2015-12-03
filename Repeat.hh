#pragma once
#include "Command.hh"
#include "Program.hh"

class Repeat :  public Command
{
private:
	Program prog;

public:
	Repeat(double arg, Program p);
	~Repeat();
	void exec();
};