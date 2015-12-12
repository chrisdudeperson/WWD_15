#include "Repeat.hh"

// Constructor takes the command value and istream reference to read in to program
Repeat::Repeat(double arg, std::istream& in) : Command(arg)
{
	in >> prog;
}

// Destructor
Repeat::~Repeat()
{
}

void Repeat::exec() 
{
	// Loops through a set of commands according to arg parameter
	for(int i(0); i < arg; i++)
	{
		prog.run();
	}
}
