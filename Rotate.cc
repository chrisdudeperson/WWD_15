#include <GLUT/GLUT.h>

#include "Rotate.hh"

// Takes angle and left boolean and assigns them to the arg member variable of Command and left
Rotate::Rotate(double angle, bool l): Command(angle), left(l)
{
}

Rotate::~Rotate()
{
}

void Rotate::exec()
{
    // If left is true it will execute a rotate to the left of angle arg
    // If left is false it will execute a rotate to the right of angle -arg
   if(left)
   {
	   glRotatef(arg,0,0,1);
   }
   else
   {
	   glRotatef(-arg,0,0,1);
   }
}