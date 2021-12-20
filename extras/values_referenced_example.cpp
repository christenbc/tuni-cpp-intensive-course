#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> storage1 = {3, 9, 27, 81, 243};
    deque<int>& storage2 = storage1;
    storage2[3] = 0;
    cout << storage1[3] << " " << storage2[3] << endl;

    /*
    deque<int> storage1 = {3, 9, 27, 81, 243};
    deque<int> storage2;
    storage2 = storage1;
    storage2.at(3) = 0;
    cout << storage1.at(3) << " " << storage2.at(3) << endl;
    */
}
