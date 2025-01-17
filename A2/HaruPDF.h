#ifndef HARUPDF_H
#define HARUPDF_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "HaruPDF.h"
#include "hpdf.h"
class HaruPDF
{
public:
    
    HPDF_Doc pdf;
    HPDF_Page page;
    HPDF_Font font;
    char fname[256];

    HaruPDF(char filename[256]);
    void ConstructPDF(float x, float y, float angle, char letter);
    void Save();

};
#endif