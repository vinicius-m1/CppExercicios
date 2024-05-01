#include "polygon.hpp"


void Polygon::SetPolygon(vector<Point2d> m_points){

    points = m_points;
        
};

Polygon::Polygon(vector<Point2d> m_points){

    points = m_points;
        
};

Polygon::Polygon(){

    points.clear();

};


bool Polygon::IsRegular(){

    vector<double> sides = Polygon::GetSides();
    bool isRegular = true;
    for (int i=0; i<sides.size(); i++){
        if (sides[0] != sides[i]){
            isRegular = false;
            break;
        }
    };
    
    return (isRegular);
};


void Polygon::UpdatePolygon(vector<Point2d> m_points){

    // add input checks later
    points.clear();
    
    points = m_points;

};



void Polygon::AddVertex(Point2d m_point){

    points.push_back(m_point);

};


double Polygon::GetArea(){

    vector<double> sides = Polygon::GetSides();
    double perimeter = Polygon::GetPerimeter();
    double apothem=0, area =0;
    
    // if regular polygon
    
    if (Polygon::IsRegular() == true){
        apothem = ((sides[0])/2)*tan(M_PI/sides.size());
        area = ((apothem*perimeter)/2);
        
        return (area);
    } 
    
    // if irregular polygon
    
    double xy=0, yx=0;
    
    for (int i=0; i<points.size()-1 ; i++){
        xy = xy + ((points[i].GetX()) * (points[i+1].GetY()) );
            
        yx = yx + ((points[i].GetY()) * (points[i+1].GetX()));
            
    };
    xy = xy + ( (points[(points.size())-1].GetX()) * (points[0].GetY()) );        
    yx = yx + ( (points[(points.size())-1].GetY()) * (points[0].GetX()) ); 
        
    area = ((xy - yx)/2);
         
    return (area);
};

double Polygon::GetPerimeter(){ // usar friend
    double perimeter = 0;
    vector<double>sides = Polygon::GetSides();
    
    for (int i=0;i<sides.size();i++){
        perimeter = perimeter + (sides[i]);
    }
    
    return (perimeter);

};

vector<double> Polygon::GetSides(){

    vector<double> sides;
    
    for (int i=0; i<(points.size() -1); i++){
   
        sides.push_back( Polygon::GetDistance(points[i],points[i+1]));
    
    };
    sides.push_back( Polygon::GetDistance(points[0],points[points.size()-1]));    
    //first with last
        
    return (sides);
};


double Polygon::GetDistance(Point2d pt1, Point2d pt2){
    
    return (sqrt (pow((pt2.GetX() - pt1.GetX()),2) + pow((pt2.GetY()-pt1.GetY()),2)));
    
};
