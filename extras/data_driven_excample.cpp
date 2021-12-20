#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    enum PostalAbbreviation {AL, AK, AZ, AR, CA, CO, ERROR_CODE};

    // Version 2: Data driven programming
    struct StateInfo{
        string name;
        PostalAbbreviation abbreviation;
    }

    const vector<StateInfo> STATES = {
        {"Alabama", AL},
        {"Alaska", AK},
        {"Arkansas", AR},
        {"California", CA},
        {"Colorado", CO}
    };

    PostalAbbreviation name_to_abbreviation(string name){
        for(auto s:STATES)
            if(name == s.name)
                return s.abbreviation;

        return ERROR_CODE;
    }

    // Version 1
    /*
    PostalAbbreviation name_to_abbreviation(string name){
        if(name == "Alabama")
            return AL;
        else if(name == "Alaska")
            return AK;
        else if(name == "Arizona")
            return AR;
        else if(name == "Arkansas")
            return AR;
        else if(name == "California")
            return CA;
        else if(name == "Colorado")
            return CO;
        else
            return ERROR_CODE;
    }
    */
}
