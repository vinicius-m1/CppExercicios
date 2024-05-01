#include "triangle.hpp"
#include <cmath>
void Triangle::SetTriangle(Point2d tp1, Point2d tp2, Point2d tp3){

    point1 = tp1;
    point2 = tp2;
    point3 = tp3;

};

vector<double> Triangle::GetAngle(){
    vector<double> angles;
    vector<double> sides = {Triangle::GetSides()};
    double hypotenuse = Triangle::GetHypotenuse(sides);

    angles.clear(); 
    angles.push_back(asin(sides[0] / hypotenuse));
    angles.push_back(asin(sides[1] / hypotenuse));
    angles.push_back(asin(sides[2] / hypotenuse));
    
    return (angles);

};

Triangle::Triangle(Point2d tp1, Point2d tp2, Point2d tp3){

    point1 = tp1;
    point2 = tp2;
    point3 = tp3;

};


Triangle::Triangle(){
};

vector<double> Triangle::GetSides(){

    vector<double> sides;
    
    sides.clear();
    sides.push_back(Polygon::GetDistance(point1, point2));
    sides.push_back(Polygon::GetDistance(point2, point3));
    sides.push_back(Polygon::GetDistance(point1, point3));
    
    return (sides);
};


//double Triangle::GetDistance(Point2d pt1, Point2d pt2){

//    return (sqrt( pow((pt2.GetX() - pt1.GetX() ),2) + pow((pt2.GetY() - pt1.GetY()),2) ));
    
//};

double Triangle::GetHypotenuse(vector<double> sides){

    double hypotenuse = sides[0];
    if (sides[1] > hypotenuse)
        hypotenuse = sides[1];
    if (sides[2] > hypotenuse)
        hypotenuse = sides[2];
         
    return (hypotenuse);
};


double Triangle::GetArea(){
    vector<double> sides = {Triangle::GetSides()}; // DEPOIS TESTAR SE SIDES PODE SER DEFINIDO SO UMA VEZ NO HPP
    
    double s = ((sides[0]+sides[1]+sides[2])/2);
    
    return (sqrt(s*((s-sides[0])*(s-sides[1])*(s-sides[2]))));
};

double Triangle::GetPerimeter(){
    vector<double> sides = {Triangle::GetSides()};
    
    return (sides[0]+sides[1]+sides[2]); 

};


