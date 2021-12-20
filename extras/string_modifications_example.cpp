#include <iostream>
#include <string>

using namespace std;

int main()
{
    string text = "One string to rule them all...";
    cout << text.length() << endl;
    cout << text.substr(4,14) << endl;
    text.replace(4, 6, "thing");
    cout << text << endl;
}
