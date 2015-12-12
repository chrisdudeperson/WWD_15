#ifndef __TRANSLATE_HH__
#define __TRANSLATE_HH__

#include "Command.hh"

class Translate: public Command
{
	private:
        // Draw variable defines if this class performs a draw or a jump
        bool draw;

    public:     
        Translate(double arg, bool d);
            ~Translate();
            void exec();
};

#endif /*__TRANSLATE_HH__*/