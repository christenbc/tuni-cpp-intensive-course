#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <fstream>

using namespace std;

int main()
{
    string input_filename = "";
    cout << "Input file: ";
    cin >> input_filename;

    ifstream ifile(input_filename);

    if (!ifile) {
        cout << "Error! The file " << input_filename << " cannot be opened." << endl;
        return EXIT_FAILURE;
    }
    else {
        string line;
        map<string, int> dictionary;

        while (getline(ifile, line)) {
            string name = line.substr(0, line.find_first_of(":"));
            string points = line.substr(line.find_first_of(":") + 1);
            dictionary[name] = dictionary[name] + stoi(points);
        }
        cout << "Final scores:" << endl;
        for (std::map<string, int>::iterator it = dictionary.begin(); it != dictionary.end(); ++it)
            std::cout << it->first << ":  " << it->second << endl;
    }
}
