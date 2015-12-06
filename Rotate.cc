#include "Rotate.hh"
#include <iostream>
#include <OpenGL/gl.h>
Rotate::Rotate(double angle, bool l): Command(angle), left(l)
{
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