#include <math.h>
#include "point.hh"

Point::Point(const string &name, int x, int y, int height, char marker)
    : name_(name), x_(x), y_(y), height_(height), marker_(marker)
{

}

string Point::getName() const
{
    return name_;
}

int Point::getX() const
{
    return x_;
}

int Point::getY() const
{
    return y_;
}

int Point::getHeight() const
{
    return height_;
}

char Point::getMarker() const
{
    return marker_;
}

float Point::getDistance(Point *toPoint) const
{
    return sqrt(pow(x_ - toPoint->getX(), 2.0) + pow(y_ - toPoint->getY(), 2.0));
}
