#include <iostream>
#include <string>
#include <map>
#include <vector>


using std::map
using std::string

Class Galaxy{
	public:
		Galaxy(string name, vector<string> stars,
		map<string,vector<string>> solar_system,
		map<string,vector<string>> planet):
			name_(name), stars_(stars), solar_system_(solar_system), planet_(planet)){
				
		}
		
		
	
	
	
	
	
	
	private:
		vector<string> stars_;
		map< string, vector<string> > solar_system_; // string of star & vector of planets
		map< string, vector<string> > planet_; // string of planet & vector of spaceships orbiting planets
		string name_;
};
	