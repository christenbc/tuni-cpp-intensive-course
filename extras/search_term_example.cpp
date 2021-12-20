#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name = "";
    string::size_type temp = 0;

    cout << "Input your name: ";
    getline(cin, name);
    
    temp = name.length();
    cout << "Your name has " << temp << " characters" << endl;
    temp = name.find("nen");
    if(temp == string::npos)
        cout << "Your name does not contain \"nen\"." << endl;
    else
        cout << "Combination \"nen\" is located starting from " << temp << endl;
}
