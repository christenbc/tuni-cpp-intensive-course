#include "player.hh"
#include <iostream>
#include <string>

using namespace std;

// constructor, useful to initialize attributes
Player::Player(string name):
    name_(name), points_(0){
}

string Player::get_name() const{
    return name_;
}

int Player::get_points() const{
    return points_;
}

void Player::add_points(int ptsToAdd){
        points_ += ptsToAdd;
        if (points_ > 50)
            points_ = 25;
}

bool Player::has_won() const{
    return points_ == 50;
}
