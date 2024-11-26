#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"
class Point
{
    public:
        Point();
        Point(float const x, float const y);
        Point(Point const &src);
        Point &operator= (Point const &src);
        ~Point();
        Fixed getX() const;
        Fixed getY() const;
    private:
        Fixed const x;
        Fixed const y;
};

#endif