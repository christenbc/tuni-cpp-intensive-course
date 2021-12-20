#include <iostream>
#include <map>
#include <string>

using namespace std;


int main()
{
    map<string, int> students = {
        {"Teekari, Tiina", 121121},
        {"Arkkari, Antti", 111222},
        {"Fyysikko, Ville", 212121},
        {"Teekkari, Teemu", 10001},
        {"Kone, Kimmo", 233233}
    };

    for(auto data_pair : students)
        cout << data_pair.first << " " << data_pair.second << endl;

    /*
    map<string, int>::iterator iter;
    iter = students.begin();
    while(iter != students.end()){
        cout << iter->first << " " << iter->second << endl;
        iter++;
    }
    */
}
