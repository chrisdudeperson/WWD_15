#include "Repeat.hh"

Repeat::Repeat(double arg, Program p) : Command(arg), prog(p)
{
}

Repeat::~Repeat()
{
}

void Repeat::exec() 
{
	prog.run();
}