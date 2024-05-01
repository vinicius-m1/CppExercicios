

#include "point2d.hpp"

class Square
{
    private:
        Point2d point1;
        Point2d point2;    
        
    public:
    
        void SetSquare(Point2d p1, Point2d p2);
        
        
        
        ~Square(){};
        Square();
        
        Square(Point2d p1, Point2d p2);
        float GetArea();
        float GetPerimeter();
        float GetDistance();


};
