#ifndef __ROTATE_HH__
#define __ROTATE_HH__

#include "Command.hh"

class Rotate : public Command
{
	private:
        // Left variable defines if this class performs a left rotation or a right rotation
        bool left;

	public:
		Rotate(double arg, bool l);
		~Rotate();
		void exec();
};

#endif /*__ROTATE_HH__*/