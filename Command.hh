#pragma once

class Command
{
protected:
	double arg;

public:
	Command(double arg);
	virtual ~Command();
	virtual void exec() = 0;
};