#ifndef ROUTE_HH
#define ROUTE_HH

#include <string>
#include <vector>
#include "point.hh"

using namespace std;

class Route
{
public:
    Route(const string& name);

    string getName() const;

    bool connect_route(Point *fromPoint, Point *toPoint);

    void print() const;

    void print_length() const;

    int getRise(Point *startPoint) const;

private:
    int getRiseFromIndex(int idx) const;

    const string name_;

    vector<Point *> route_;
};

#endif // ROUTE_HH
