#include "Spiral.h"
#include <iostream>
#include <math.h>

/**
 * This class generates x,y locations on a spiral centered on a point on the page.
 * 
 * @param centerX - X coordinate of the center point of the spiral.
 * @param centerY - Y coordinate of the center point of the spiral.
 * @param startAngle - Starting angle of the spiral in degrees.
 * @param scaleFactor - Scaling factor to control the size of the spiral.
 */
Spiral::Spiral(double centerX, double centerY, double startAngle, double scaleFactor): centerX(centerX), centerY(centerY), startAngle(startAngle), scaleFactor(scaleFactor) {

radius = startAngle * scaleFactor;
//If starting angle is negative, change to positive
if (startAngle < 0){
    startAngle = 1;
}

// Convert the starting angle to radians
spiralRadian = startAngle / 180 * 3.141592;

x = centerX + cos(spiralRadian) * radius;
y = centerY + sin(spiralRadian) * radius;

}

/**
 * Overloaded operator to increment the angle of the spiral by a certain number of degrees.
 * 
 * @param angle - Number of degrees to increment the angle by.
 * 
 * @return The updated spiral object.
 */
Spiral& Spiral:: operator+=(int angle){
startAngle += (-angle);


spiralRadian = startAngle / 180 * 3.141592;
//spiralRadian -= 15/radius;
radius = startAngle * scaleFactor;
//radius = radius+1;

 x = centerX + cos(spiralRadian) * radius;
 y = centerY + sin(spiralRadian) * radius;

startAngle -= 10/radius;

return *this;
}

/**
 * Getter for the current x coordinate of the spiral
*/
double Spiral::getSpiralX(){
//centerX = cos(spiralRadian) * radius;
return x;
}

/**
 * Getter for the current y coordinate of the spiral
*/
double Spiral::getSpiralY(){
//centerY = sin(spiralRadian) * radius;
return y;
}

/**
 * Getter for what the current angle of the spiral is at.
*/
double Spiral::getSpiralAngle(){
return startAngle;
}



