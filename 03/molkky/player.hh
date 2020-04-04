#ifndef PLAYER_HH
#define PLAYER_HH

#include <string>

using namespace std;

class Player{
public: // methods
    Player(string name); // constructor
    string get_name() const;
    int get_points() const;
    void add_points(int ptsToAdd);
    bool has_won() const;
    
private: // attributes
    string name_;
    int points_;
};

#endif // PLAYER_HH
