#pragma once
#include "Command.hh"

class Rotate : public Command
{
public:
    Rotate(double arg, bool d);
    ~Rotate();
    void exec();
    
private:
    bool left;
};