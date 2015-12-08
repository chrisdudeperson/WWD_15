#ifndef __REPEAT_HH__
#define __REPEAT_HH__

#include "Command.hh"
#include "Program.hh"

class Repeat :  public Command
{
	private:
		Program prog;

	public:
		Repeat(double arg, std::istream& in);
		~Repeat();
		void exec();
};

#endif /*__REPEAT_HH__*/