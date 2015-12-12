#include <GLUT/GLUT.h>

#include "Translate.hh"
#include "Command.hh"

// Takes distance and draw boolean and assigns them to the arg member variable of Command and draw
Translate::Translate(double distance, bool d): Command(distance) , draw(d)
{
}

Translate::~Translate()
{
}

void Translate::exec()
{
    //  If the parameter draw is true, it will draw a line of length arg
    //  If it is false it will perform a jump
    if(draw)
    {
        glBegin(GL_LINE_LOOP);
        glVertex3f(0.0,0.0f,0.0f);
        glVertex3f(arg,0.0f, 0.0f);
        glEnd();
    }
    glTranslatef(arg,0,0);
}