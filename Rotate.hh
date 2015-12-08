#ifndef __ROTATE_HH__
#define __ROTATE_HH__

#include "Command.hh"

class Rotate : public Command
{
	private:
		bool left;

	public:
		Rotate(double arg, bool d);
		~Rotate();
		void exec();
};

#endif /*__ROTATE_HH__*/