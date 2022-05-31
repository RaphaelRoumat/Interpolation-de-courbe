#pragma once

#include "Point.hpp"

Point::Point(int x, int y)
: x(x), y(y)
{
}

int Point::getX()
{
    return x;
}

int Point::getY()
{
    return y;
}