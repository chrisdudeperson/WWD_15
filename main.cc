#include <iostream>
#include <fstream>
#include <string>

#include "window.h"
#include "Translate.hh"
#include "Rotate.hh"
#include "Program.hh"

using namespace std;

Program P;

int main(int argc, char** argv)
{
    char* fname = argv[1];
    cout << "Reading file [" << fname << "]" << endl;
    ifstream file(fname);
    
    if (!file){
        cout << "Don't think that file exists mate..." << endl;
        return 1;
    }
    
    file >> P;
    
    window w(argc, argv);

    return 0;
}

void draw()
{
    cout << "Entered draw funciton" << endl;
    P.run();
}
