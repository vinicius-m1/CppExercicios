#include "point2d.hpp"

//implementacao de metodos


void Point2d::SetPoint2d(int x, int y)
{
    m_x = x;
    m_y = y;
}

Point2d::Point2d(int x, int y){

m_x = x;
m_y = y;

}




Point2d::Point2d(){

m_x = 0;
m_y = 0;

}



int Point2d::GetX()
{
    return m_x;
}
int Point2d::GetY()
{
    return m_y;
}
