#include "Fixed.hpp"
#include "Point.hpp"

Fixed fxabs(Fixed fixed)
{
    if (fixed < Fixed(0))
        return (fixed * Fixed(-1));
    else
        return (fixed);
}

Fixed areaTriangle(Point a, Point b, Point c)
{
    return (fxabs(Fixed(
        a.getX() * (b.getY() - c.getY()) +
        b.getX() * (c.getY() - a.getY()) +
        c.getX() * (a.getY()- b.getY())
    )) * Fixed(0.5f));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed totalArea = areaTriangle(a, b, c);
    Fixed area1 = areaTriangle(point, b, c);
    Fixed area2 = areaTriangle(a, point, c);
    Fixed area3 = areaTriangle(a, b, point);

    return ((area1 + area2 + area3) == totalArea && area1 != Fixed(0) && area2 != Fixed(0) && area3 != Fixed(0));
}