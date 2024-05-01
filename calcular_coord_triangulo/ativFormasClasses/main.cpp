#include "circle.hpp"
#include "square.hpp"
#include "triangle.hpp"
#include "polygon.hpp"
#include <vector>

int main()
{
    //teste de point anterior
    /*Point2d pt1, pt2, pt3;
    pt1.SetPoint2d(10,15);
    pt2 = pt1;
    pt3.SetPoint2d(20,35);

    vector<Point2d> vecPoints;
    vecPoints.push_back(pt1);
    vecPoints.push_back(pt2);
    vecPoints.push_back(pt3);

    for(size_t i=0; i<vecPoints.size(); i++)
    {
        cout << vecPoints.at(i).GetX() << "-" << vecPoints.at(i).GetY() << endl;
    }*/

    Point2d pt1, pt2, pt3;
    pt1.SetPoint2d(10,15);
    pt2 = pt1;
    pt3.SetPoint2d(20,35);

    Circle c1,c2,c3,c4;
    c1.SetCircle(10, pt1);
    c2.SetCircle(15, 5,5);
    c3.SetCircle(20, pt2);
    c4.SetCircle(30, pt3);

    vector<Circle> vecCircle;
    vecCircle.push_back(c1);
    vecCircle.push_back(c2);
    vecCircle.push_back(c3);
    vecCircle.push_back(c4);
    
    // Square
    
    
    Point2d sp1, sp2; //SquarePoint
    
    sp1.SetPoint2d(3,5);
    sp2.SetPoint2d(8,10);
    
    Square s1; // creating instance
    
    s1.SetSquare(sp1,sp2); //giving values to instance
    
    
    vector<Square> vecSquare;
    vecSquare.push_back(s1);
    
    // Triangle
    
    Point2d tp1, tp2, tp3;
    
    tp1.SetPoint2d(1,1);    
    tp2.SetPoint2d(3,4);
    tp3.SetPoint2d(6,1);
    
    Triangle t1;    
        
    t1.SetTriangle(tp1, tp2, tp3);
    
    vector<Triangle> vecTriangle;
    vecTriangle.push_back(t1);    
    
    // Polygon
    
    Point2d pp1, pp2, pp3, pp4, pp5, pp6;
    pp1.SetPoint2d(2.9,-2);
    pp2.SetPoint2d(-4.5,2.9);
    pp3.SetPoint2d(-6.5,1.1); // desmos
    pp4.SetPoint2d(-1.3,-5.3);
    pp5.SetPoint2d(-2,-1.2);
    pp6.SetPoint2d(-0.7,0.9);
    
    vector<Point2d> points;
    
    points.push_back(pp1);
    points.push_back(pp2);
    points.push_back(pp3);
    points.push_back(pp4);
    points.push_back(pp5);
    points.push_back(pp6);
    
    Polygon p1;
    p1.SetPolygon(points);
    vector<Polygon> vecPolygon;
    vecPolygon.push_back(p1); 
    
    
    
       
    
    cout << endl << " === CIRCLE ⚪️ === " << endl;

    for(size_t i=0; i<vecCircle.size(); i++)
    {
        cout << "Ratio: " << vecCircle.at(i).GetRatio() << "|" << "PosXY: " << vecCircle.at(i).GetReference().GetX() << "|" << vecCircle.at(i).GetReference().GetY() << endl;
    }
    
    cout << endl << " === SQUARE ⬜️ === " << endl;
    
    for (size_t i=0; i<vecSquare.size(); i++){
    
        cout << "Side size: "<< vecSquare[i].GetDistance() << " | Area: " << vecSquare[i].GetArea() << "| Perimeter: "<< vecSquare[i].GetPerimeter() <<endl;
    
    };
    
    cout << endl << " === TRIANGLE 📐️ === " << endl;
    
    for (size_t i=0; i<vecTriangle.size(); i++){
                                                // botar resto dos lados
        cout << "Sides size: "<< vecTriangle[i].GetSides()[0] << " "<< vecTriangle[i].GetSides()[1] << " "<< vecTriangle[i].GetSides()[2] << " | Area: " << vecTriangle[i].GetArea() << "| Perimeter: "<< vecTriangle[i].GetPerimeter() << "| Angles: "<< vecTriangle[i].GetAngle().at(0)  <<" "<< vecTriangle[i].GetAngle().at(1) << " " << vecTriangle[i].GetAngle().at(2)  <<endl;
    
    };    
    
    cout << endl << " === POLYGON 🔰️ === " << endl;
    
    for (size_t i=0; i<vecPolygon.size(); i++){
    
        cout << "Area: " << vecPolygon[i].GetArea() << " | Perimeter: "<< vecPolygon[i].GetPerimeter() <<endl;
        for (int j=0; j<vecPolygon[i].GetSides().size(); j++){
            cout << endl<< "distance " <<j << ": " << vecPolygon[i].GetSides()[j];
        }  
    
    };    
    
    

    return 0;
}
