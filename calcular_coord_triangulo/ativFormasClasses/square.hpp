

#include "point2d.hpp"

class Square
{
    private:
        Point2d point1;
        Point2d point2;    
        
    public:
    
        void SetSquare(Point2d p1, Point2d p2); //era pra receber 2 Point2d
        
        float GetArea();
        float GetPerimeter();
        float GetDistance();


};
