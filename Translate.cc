#include "Translate.hh"
#include <iostream>
#include <OpenGL/gl.h>

Translate::Translate(double distance, bool d): draw(d)
{
        arg = distance;
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