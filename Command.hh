#ifndef __COMMAND_HH__
#define __COMMAND_HH__

class Command
{
protected:
	double arg;

public:
	Command(double arg) : arg(arg){};
	virtual ~Command(){};
	virtual void exec() = 0;
};

#endif /*__COMMAND_HH__*/