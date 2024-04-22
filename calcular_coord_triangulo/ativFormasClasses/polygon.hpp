#include "point2d.hpp"
#include <vector>
#include <cmath>
class Polygon {



    private:
    
        vector<Point2d> points;    
    

    public:
    
        void SetPolygon(vector<Point2d> m_points);
        
        bool IsRegular();
        float GetArea();
        float GetPerimeter();
        vector<float> GetSides();
        float GetDistance(Point2d pt1, Point2d pt2);

};
