#include <iostream>
#include <iomanip>
#include <algorithm>
#include <assert.h>
#include "points.hh"

Points::~Points()
{
    for (const auto& any : points_)
        delete any.second;
}

void Points::set_map_size(int width, int height)
{
    assert(points_.size() == 0);
    width_ = width;
    height_ = height;
    grid_.resize(width_ * height_);
}

void Points::add_point(string &name, int x, int y, int height, char marker)
{
    if ((points_.find(name) == points_.cend()) && (x > 0) && (x <= width_) && (y > 0) && (y <= height_) &&
            (grid_[(y - 1) * width_ + (x - 1)] == nullptr)) {
        Point *point = new Point(name, x, y, height, marker);
        points_[name] = point;
        grid_[(y - 1) * width_ + (x - 1)] = point;
    }
}

Point *Points::getPointByName(const string &name) const
{
    map<string, Point *>::const_iterator it = points_.find(name);
    if (it == points_.cend()) {
        return nullptr;
    }
    else {
        return it->second;
    }
}

void Points::print_map() const
{
    // Print header
    cout << "  ";
    for (int x = 0; x < width_; x++) {
        // std::setw initializes stream field size
        cout << setw(3) /* << std::center */ << x + 1;
    }
    cout << endl;
    // Print body
    for (int y = 0; y < height_; y++) {
        cout << setw(2) << y + 1;
        for (int x = 0; x < width_; x++) {
            int i = y * width_ + x;
            Point *point = grid_[i];
            if (point == nullptr) {
                cout << setw(3) << std::right << ".";
            }
            else {
                cout << setw(3) << std::right << point->getMarker();
            }
        }
        cout << endl;
    }
}

void Points::print_points() const
{
    vector<string> pointNames;
    for (const auto &any : points_)
        pointNames.push_back(any.first);
    sort(pointNames.begin(), pointNames.end());
    cout << "Points:" << endl;
    for (const auto &any : pointNames) {
        Point *point = points_.at(any);
        cout << " - " << point->getName() << " : " << point->getMarker() << endl;
    }
}
