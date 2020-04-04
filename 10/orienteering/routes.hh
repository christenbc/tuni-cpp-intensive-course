/*  TIE-02201 Ohjelmointi 2, K2019 / TIE-02207 Programming 2, S2019
 *  Project 3: Orienteering
 *  File: routes.hh
 *  Description: Datastructure that represents the orienteering map
 *      and handles the information of different points and routes
 *  Notes:
 *      * Students aren't allowed to make changes to the public interface!
 *      * Modifying the private part of class is allowed.
 * */

#ifndef ROUTES_HH
#define ROUTES_HH

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include "point.hh"
#include "points.hh"
#include "route.hh"

class Routes
{
public:
    Routes();
    ~Routes();

    void set_map_size(int width, int height);

    void add_point(std::string& name, int x, int y, int height, char marker);

    bool connect_route(std::string& from, std::string& to, std::string& route_name);

    void print_map() const;

    void print_route_names() const;

    void print_points() const;

    void print_route(const std::string& name) const;

    void route_length(const std::string& name) const;

    void greatest_rise(const std::string& point_name) const;

private:
    Points points_;
    std::map<std::string, Route *> routes_;
};

#endif // ROUTES_HH
