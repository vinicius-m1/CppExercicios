#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>

//definicao

 
using namespace std;

class Point2d
{
private:
    int m_x, m_y;

public:
    //getter and setter
    void SetPoint2d(int x, int y);
    int GetX();
    int GetY();
};

#endif
