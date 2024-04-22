#include "polygon.hpp"


void Polygon::SetPolygon(vector<Point2d> m_points){

    points = m_points;
        
};

bool Polygon::IsRegular(){

    vector<float> sides = Polygon::GetSides();
    bool isRegular = true;
    for (int i=0; i<sides.size(); i++){
        if (sides[0] != sides[i]){
            isRegular = false;
            break;
        }
    };
    
    return (isRegular);
};


float Polygon::GetArea(){

    vector<float> sides = Polygon::GetSides();
    float perimeter = Polygon::GetPerimeter();
    float apothem, area =0;
    
    // if regular polygon
    
    if (Polygon::IsRegular() == true){
        apothem = ((sides[0])/2)*tan(180/sides.size());
        area = ((apothem*perimeter)/2);
        
        return (area);
    } 
    
    // if irregular polygon
    
    float xy=0, yx=0;
    
    for (int i=0; i<points.size()-1 ; i++){
        xy = xy + ((points[i].GetX()) * (points[i+1].GetY()) );
            
        yx = yx + ((points[i].GetY()) * (points[i+1].GetX()));
            
    };
    xy = xy + ( (points[(points.size())-1].GetX()) * (points[0].GetY()) );        
    yx = yx + ( (points[(points.size())-1].GetY()) * (points[0].GetX()) ); 
        
    area = ((xy - yx)/2);
         
    return (area);
};

float Polygon::GetPerimeter(){
    float perimeter = 0;
    vector<float>sides = Polygon::GetSides();
    
    for (int i=0;i<sides.size();i++){
        perimeter = perimeter + (sides[i]);
    }
    
    return (perimeter);

};

vector<float> Polygon::GetSides(){

    vector<float> sides;
    
    for (int i=0; i<(points.size() -1 ); i++){
   
        sides.push_back( Polygon::GetDistance(points[i],points[i+1]));
    
    };
    sides.push_back( Polygon::GetDistance(points[0],points[points.size()-1]));    
    //first with last
        
    return (sides);
};


float Polygon::GetDistance(Point2d pt1, Point2d pt2){

    float distance;
    
    distance = ( (pt2.GetX() - pt1.GetX()) + (pt2.GetY() - pt1.GetY()) ); 
    
    if (distance < 0) {distance = distance*(-1);}; // cheaper than pow and sqrt?
    
    return (distance);
    
};
