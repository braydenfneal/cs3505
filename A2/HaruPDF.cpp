
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "HaruPDF.h"
//#include "hpdf.h"
/**
 * This is a class used clto create a PDF file.
*/
HaruPDF::HaruPDF(char filename[256]){
    //char fname[256];
    // argv are the command line arguments
    // argv[0] is the name of the executable program
    // This makes an output pdf named after the program's name
    strcpy (fname, filename);
    //strcat (fname, ".pdf");

    pdf = HPDF_New (NULL, NULL);
    /* add a new page object. */
    page = HPDF_AddPage (pdf);
    HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);
//    print_grid  (pdf, page);

    HPDF_Page_BeginText (page);
    // Set the font	
    font = HPDF_GetFont (pdf, "Courier-Bold", NULL);
    HPDF_Page_SetTextLeading (page, 20);
    HPDF_Page_SetGrayStroke (page, 0);
    HPDF_Page_SetFontAndSize (page, font, 30);
}

/**
 * This function takes four inputs, '_x' and '_y' as the x and y positions of the text on the page, 
 * 'angle' as the angle of rotation for the text, and 'letter' as the text to be written.
*/
void HaruPDF::ConstructPDF(float _x, float _y, float angle, char letter){
        char buf[2];
        // C-style strings are null-terminated. The last character must a 0.
        buf[0] = letter; // The character to display
        buf[1] = 0;
        
        float letterRad = (angle - 90) / 180 * 3.141592;

        // This ugly function defines where any following text will be placed
        // on the page. The cos/sin stuff is actually defining a 2D rotation
        // matrix.
        HPDF_Page_SetTextMatrix(page,
                                cos(letterRad), sin(letterRad), -sin(letterRad), cos(letterRad),
                                _x, _y);
        HPDF_Page_ShowText (page, buf);
}

/**
 * This function is used to save the PDF document and end text operations on the page.
*/
void HaruPDF::Save(){
    HPDF_Page_EndText (page);

    /* save the document to a file */
    HPDF_SaveToFile (pdf, fname);

    /* clean up */
    HPDF_Free (pdf);
}
