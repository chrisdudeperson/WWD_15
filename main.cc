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
    window w(argc, argv);
    string fname = argv[1], output;
    cout << "Reading file [" << fname << "]" << endl;
    ifstream file(fname);
    
    if (!file){
        cout << "Don't think that file exists mate..." << endl;
        return 1;
    }
    
    file >> P;

    return 0;
}

void draw()
{
    P.run();
}