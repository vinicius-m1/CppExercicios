#include "circle.hpp"

void Circle::SetCircle(float ratio, Point2d ref) // definicao metodo setcircle
{
    m_ref = ref;
    m_ratio = ratio;
}



void Circle::SetCircle(float ratio, int xref, int yref)
{
    Point2d tmp;
    tmp.SetPoint2d(xref, yref);
    SetCircle(ratio, tmp);
}

int Circle::GetRatio()
{
    return m_ratio;
}

Point2d Circle::GetReference()
{
    return m_ref;
}
