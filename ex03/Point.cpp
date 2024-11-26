#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}
Point::Point(float const x, float const y) : x(x), y(y)
{
}
Point::Point(Point const &src) : x(src.x), y(src.y)
{
}
Point &Point ::operator= (Point const &src)
{
    if (this != &src)
        std::cerr << "copy failed due to const members." << std::endl;
    (void)src;
    return *this;
}

Point::~Point()
{
}

Fixed Point::getX() const
{
    return (this->x);
}

Fixed Point::getY() const
{
    return (this->y);
}