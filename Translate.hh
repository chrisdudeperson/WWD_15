#pragma once
#include "Command.hh"

class Translate: public Command
{
    public:
            Translate(double arg, bool d);
            ~Translate();
            void exec();
    
    private:
            bool draw;
};