#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string filename = "";
    cout << "Input file name: ";
    getline(cin, filename);

    ifstream file_object(filename);
    if(!file_object)
        cout << "Error: failed opening the file." << endl;
    else{
        int sum = 0;
        string line;
        while(getline(file_object, line))
            sum += stoi(line);
        file_object.close();
        cout << "Sum: " << sum << endl;
    }
}
