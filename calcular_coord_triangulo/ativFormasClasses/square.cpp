#include "square.hpp"
#include <cmath>
void Square::SetSquare(Point2d p1, Point2d p2){
                
    point1 = p1;    // declared in header
    point2 = p2;        
};


Square::Square(Point2d p1, Point2d p2){

                
    point1 = p1;    // declared in header
    point2 = p2;        

};

Square::Square(){

                //default
    point1.SetPoint2d(0,0);
    point2.SetPoint2d(0,0);        

};

float Square::GetDistance(){

    float distance;
    
    distance = sqrt( pow((point2.GetX() - point1.GetX() ),2) + pow((point2.GetY() - point1.GetY()),2) ); 
    
    return (distance);
};


Square::Square(Point2d p1, Point2d p2);


float Square::GetArea(){
    
    float m_distance = Square::GetDistance();
    float area = (m_distance * m_distance);
    return (area);

};

float Square::GetPerimeter(){
    
    
    float perimeter = (Square::GetDistance()*4); 
    return (perimeter);

}


        
