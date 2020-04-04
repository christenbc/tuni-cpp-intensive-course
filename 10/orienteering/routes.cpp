#include "routes.hh"
#include <vector>
#include <string>
#include <algorithm>

/* The code is that self-explanatory as it is well encanpsulated, that many comments are not useful*/

Routes::Routes()
{

}

Routes::~Routes()
{
    for (const auto& any : routes_)
        delete any.second;
}

void Routes::set_map_size(int width, int height)
{
    points_.set_map_size(width, height);
}

void Routes::add_point(std::string &name, int x, int y, int height, char marker)
{
    points_.add_point(name, x, y, height, marker);
}

bool Routes::connect_route(std::string &from, std::string &to, std::string &route_name)
{
    Point *fromPoint = points_.getPointByName(from);
    Point *toPoint = points_.getPointByName(to);
    if (fromPoint != nullptr && toPoint != nullptr) {
        Route *route = routes_[route_name];
        if (route == nullptr) {
            // Route does not exists, lets create it
            route = new Route(route_name);
            routes_[route_name] = route;
        }
        return route->connect_route(fromPoint, toPoint);
    }
    else {
        return false;
    }
}

void Routes::print_map() const
{
    points_.print_map();
}

void Routes::print_route_names() const
{
    vector<string> routeNames;
    for (const auto& any : routes_)
        routeNames.push_back(any.first);
    sort(routeNames.begin(), routeNames.end());
    cout << "Routes:" << endl;
    for (const auto &any : routeNames)
        cout << " - " << any << endl;
}

void Routes::print_points() const
{
    points_.print_points();
}

void Routes::print_route(const std::string &name) const
{
    std::map<std::string, Route *>::const_iterator it = routes_.find(name);
    if (it == routes_.cend()) {
        cout << "Error: Route named " << name << " can't be found" << endl;
    }
    else {
        it->second->print();
    }
}

void Routes::route_length(const std::string &name) const
{
    std::map<std::string, Route *>::const_iterator it = routes_.find(name);
    if (it == routes_.cend()) {
        cout << "Error: Route named " << name << " can't be found" << endl;
    }
    else {
        it->second->print_length();
    }
}

void Routes::greatest_rise(const std::string &point_name) const
{
    Point *startPoint = points_.getPointByName(point_name);
    if (startPoint == nullptr) {
        cout << "Error: Point named " << point_name << " can't be found" << endl;
    }
    else {
        vector <Route *> greatestRiseRoutes;
        int greatestRise = 0;
        for (const auto &any : routes_) {
            int rise = any.second->getRise(startPoint);
            if (rise > 0 && rise >= greatestRise) {
                if (rise > greatestRise) {
                    greatestRise = rise;
                    greatestRiseRoutes.clear();
                }
                greatestRiseRoutes.push_back(any.second);
            }
        }
        if (!greatestRiseRoutes.empty()) {
            cout << "Greatest rise after point " << startPoint->getName() << ", " << greatestRise << " meters, is on route(s):" << endl;
            for (const auto &any : greatestRiseRoutes)
                cout << " - " << any->getName() << endl;
        }
        else {
            cout << "No route rises after point " << startPoint->getName() << endl;
        }
    }
}
