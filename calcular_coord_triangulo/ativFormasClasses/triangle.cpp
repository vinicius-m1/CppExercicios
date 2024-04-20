#include "triangle.hpp"

void Triangle::SetTriangle(Point2d tp1, Point2d tp2, Point2d tp3){

    point1 = tp1;
    point2 = tp2;
    point3 = tp3;

};

array<float,3> Triangle::GetAngle(){
    array<float,3> angles;
    array<float,3> sides = {Triangle::GetSides()};
    float hypotenuse = Triangle::GetHypotenuse(sides);

    angles[0] = (asin(sides[0] / hypotenuse));
    angles[1] = (asin(sides[1] / hypotenuse));
    angles[2] = (asin(sides[2] / hypotenuse));
    
    return (angles);

};


array<float,3> Triangle::GetSides(){

    array<float,3> sides;
    
    sides[0] = Triangle::GetDistance(point1, point2);
    sides[1] = Triangle::GetDistance(point2, point3);
    sides[2] = Triangle::GetDistance(point1, point3);
    
    return (sides);
};


float Triangle::GetDistance(Point2d pt1, Point2d pt2){

    float distance;
    
    distance = ( (pt2.GetX() - pt2.GetX()) + (pt2.GetY() - pt1.GetY()) ); 
    
    if (distance < 0) {distance = distance*(-1);};
    
    return (distance);
    
};

float Triangle::GetHypotenuse(array<float,3> sides){

    float hypotenuse = sides[0];
    if (sides[1] > hypotenuse)
        hypotenuse = sides[1];
    if (sides[2] > hypotenuse)
        hypotenuse = sides[2];
         
    return (hypotenuse);
};


float Triangle::GetArea(){
    array<float,3> sides = {Triangle::GetSides()}; // DEPOIS TESTAR SE SIDES PODE SER DEFINIDO SO UMA VEZ NO HPP
    
    float s = ((sides[0]+sides[1]+sides[2])/2);
    
    return (sqrt(s*(s-sides[0])*(s-sides[1])*(s-sides[2])));
};

float Triangle::GetPerimeter(){
    array<float,3> sides = {Triangle::GetSides()};
    
    return (sides[0]+sides[1]+sides[2]); 

};


