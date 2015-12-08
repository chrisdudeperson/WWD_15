#ifndef __TRANSLATE_HH__
#define __TRANSLATE_HH__

#include "Command.hh"

class Translate: public Command
{
	private:
		bool draw;

    public:
            Translate(double arg, bool d);
            ~Translate();
            void exec();
};

#endif /*__TRANSLATE_HH__*/