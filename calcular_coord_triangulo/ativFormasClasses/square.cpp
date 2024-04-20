#include "square.hpp"

void Square::SetSquare(Point2d p1, Point2d p2){
                
    point1 = p1;    // declared in header
    point2 = p2;        
};


float Square::GetDistance(){

    float distance;
    
    distance = ( (point2.GetX() - point2.GetX()) + (point2.GetY() - point1.GetY()) ); 
    
    if (distance < 0) {distance = distance*(-1);};
    
    return (distance);
};


float Square::GetArea(){
    
    float m_distance = Square::GetDistance();
    float area = (m_distance * m_distance);
    return (area);

};

float Square::GetPerimeter(){
    
    
    float perimeter = (Square::GetDistance()*4); 
    return (perimeter);

}


        
