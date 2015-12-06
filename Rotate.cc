#include "Rotate.hh"
#include <iostream>
#include <OpenGL/gl.h>
Rotate::Rotate(double angle, bool l): left(l)
{
    arg = angle;
}

Rotate::~Rotate()
{
    
}

void Rotate::exec()
{
   if(left)
   {
    glRotatef(arg,0,0,1);
   }else
   {
    glRotatef(-arg,0,0,1);
   }
}