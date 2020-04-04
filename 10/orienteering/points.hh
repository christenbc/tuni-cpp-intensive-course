#ifndef POINTS_HH
#define POINTS_HH

#include <vector>
#include <map>
#include "point.hh"

using namespace std;

class Points
{
public:
    ~Points();

    void set_map_size(int width, int height);

    void add_point(std::string &name, int x, int y, int height, char marker);

    Point *getPointByName(const string &name) const;

    void print_map() const;

    void print_points() const;

private:
    int width_, height_;

    vector <Point *> grid_;

    map<string, Point *> points_;
};

#endif // POINTS_HH
