#ifndef POINT_HH
#define POINT_HH

#include <string>

using namespace std;

class Point
{
public:
    Point(const string &name, int x, int y, int height, char marker);

    string getName() const;

    int getX() const;

    int getY() const;

    int getHeight() const;

    char getMarker() const;

    float getDistance(Point *toPoint) const;

private:
    string name_;
    int x_;
    int y_;
    int height_;
    char marker_;
};

#endif // POINT_HH
