#include "Repeat.hh"

Repeat::Repeat(double arg, Program p) : Command(arg), prog(p)
{
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
