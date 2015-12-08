#include "Repeat.hh"

Repeat::Repeat(double arg, std::istream& in) : Command(arg)
{
	in >> prog;
}

Repeat::~Repeat()
{
}

void Repeat::exec() 
{
    for(int i(0); i < arg; i++)
    {
        prog.run();
    }
}
