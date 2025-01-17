#ifndef SPIRAL_H
#define SPIRAL_H

#include <iostream>
class Spiral{
double centerX;
double centerY;
double startAngle;
double scaleFactor;
double radius;
double spiralRadian;
double x;
double y;

public:
Spiral(double centerX, double centerY, double startAngle, double scaleFactor);
Spiral& operator+=(int angle);
double getSpiralX();
double getSpiralY();
double getSpiralAngle();

};
#endif