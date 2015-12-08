#include <iostream>
#include <GL/glut.h>

#include "Rotate.hh"

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
   }
   else
   {
	   glRotatef(-arg,0,0,1);
   }
}