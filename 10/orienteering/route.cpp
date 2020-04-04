#include <iostream>
#include <iomanip> // so we can use setw, setprecision, etc,...
#include <assert.h>
#include "route.hh"

Route::Route(const string &name)
    : name_(name)
{

}

string Route::getName() const
{
    return name_;
}

bool Route::connect_route(Point *fromPoint, Point *toPoint)
{
    if (route_.empty()) {
        route_.push_back(fromPoint);
        route_.push_back(toPoint);
        return true;
    }
    else if (*route_.crbegin() == fromPoint) {
        route_.push_back(toPoint);
        return true;
    }
    else {
        return false;
    }
}

void Route::print() const
{
    bool startPoint = true;
    for (const auto &any : route_) {
        if (!startPoint) {
            cout << " -> ";
        }
        else {
            startPoint = false;
        }
        cout << any->getName() << endl;
    }
}

void Route::print_length() const
{
    float length = 0.0;
    for (unsigned i = 1; i < route_.size(); i++) {
        length += route_[i - 1]->getDistance(route_[i]);
    }
    cout << "Route " << name_ << " length was " << setprecision(2) << length << endl;
}

int Route::getRise(Point *startPoint) const
{
    assert(!route_.empty());
    int maxRise = 0;
    for (unsigned i = 0; i < route_.size(); i++) {
        if (route_[i] == startPoint) {
            int rise = getRiseFromIndex(i);
            if (rise > maxRise) {
                maxRise = rise;
            }
        }
    }
    return maxRise;
}

int Route::getRiseFromIndex(int idx) const
{
    int startHeight = route_.at(idx)->getHeight();
    int lastHeight = startHeight;
    for (unsigned i = idx + 1; i < route_.size(); i++) {
        int height = route_.at(i)->getHeight();
        if (height < lastHeight) {
            break;
        }
        lastHeight = height;
    }
    return lastHeight - startHeight;
}
