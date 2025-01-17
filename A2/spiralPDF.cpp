#include "Spiral.h"
#include "HaruPDF.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

// argc is the number of arguments. Argv is an array of character arrays, or C-style strings.
// If you call the program like ./pdfExample "Hello", then argv[1] would contain "Hello\0".
// argv[0] would be "pdfExample\0" - the name of the executing program.
int main(int argc, char **argv)
{
    char fname[256];
    char letter;
    double _x;
    double _y;
    double _angle;
    double radius;
    float letterAngle;

    if (argc < 2)
    {
        std::cout << "There is no Sample text" << std::endl;
        return 0;
    }
    // argv are the command line arguments
    // argv[0] is the name of the executable program
    // This makes an output pdf named after the program's name
    strcpy(fname, argv[0]);
    strcat(fname, ".pdf");

    char *inputText = argv[1];

    HaruPDF myPDF(fname);
    Spiral mySpiral(180, 210, 300, 0.1);

    for (size_t i = 0; i < strlen(inputText); i++)
    {
        _x = mySpiral.getSpiralX();
        _y = mySpiral.getSpiralY(); 
        _angle = mySpiral.getSpiralAngle();
        radius = _angle * 0.1;
        letter = inputText[i];
        letterAngle = (_angle - 180);
        
        myPDF.ConstructPDF(_x, _y, letterAngle, letter);
        
        mySpiral += (_angle/radius);

    }
    myPDF.Save();
}
