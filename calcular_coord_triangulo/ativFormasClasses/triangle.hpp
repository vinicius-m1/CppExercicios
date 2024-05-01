#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "point2d.hpp"
#include "polygon.hpp"
#include <cmath>
#include <vector>
class Triangle{

    private:
        Point2d point1, point2, point3;
        double GetDistance(Point2d pt1, Point2d pt2);
        double GetHypotenuse(vector<double> sides);       
    
    public:
        
        void SetTriangle(Point2d tp1, Point2d tp2, Point2d tp3);
        
        vector<double> GetAngle();
        vector<double> GetSides();
        double GetArea();
        
        Triangle();
        Triangle(Point2d tp1, Point2d tp2, Point2d tp3);
        
        // fazer os contruct que inicializam tudo null
        
        ~Triangle(){};
        double GetPerimeter();    
        
};

#endif
