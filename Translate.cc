#include <iostream>
#include <GL/glut.h>

#include "Translate.hh"
#include "Command.hh"

Translate::Translate(double distance, bool d): Command(distance) , draw(d)
{
}

Translate::~Translate()
{
}

void Translate::exec()
{
    if(draw)
    {
        glBegin(GL_LINE_LOOP);
        glVertex3f(0.0,0.0f,0.0f);
        glVertex3f(arg,0.0f, 0.0f);
        glEnd();
    }
    glTranslatef(arg,0,0);
}