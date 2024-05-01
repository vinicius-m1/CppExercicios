#ifndef POLYGON_H
#define POLYGON_H
#include "point2d.hpp"
#include <vector>
#include <cmath>
#include "triangle.hpp"
class Polygon {



    private:
    
        vector<Point2d> points;    
        friend class Triangle;

    public:
    
        void SetPolygon(vector<Point2d> m_points);
        
        bool IsRegular();
        
        ~Polygon(){};
        Polygon(); // default init
        Polygon(vector<Point2d> m_points);
        void AddVertex(Point2d point);
        void UpdatePolygon(vector<Point2d> m_points);
        double GetArea();
        double GetPerimeter();
        vector<double> GetSides();
        static double GetDistance(Point2d pt1, Point2d pt2); // static bcs friend access 

};


#endif
