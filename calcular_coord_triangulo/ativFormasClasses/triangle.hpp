#include "point2d.hpp"
#include <cmath>
#include<array>
class Triangle{

    private:
        Point2d point1, point2, point3;
        float GetDistance(Point2d pt1, Point2d pt2);
        float GetHypotenuse(array<float,3> sides);       
    
    public:
        
        void SetTriangle(Point2d tp1, Point2d tp2, Point2d tp3);
        
        array<float,3> GetAngle();
        array<float,3> GetSides();
        float GetArea();
        float GetPerimeter();    
        
};
