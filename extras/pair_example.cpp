#include <iostream>
#include <utility>

using namespace std;


int main()
{
    pair<int, char> pair1;
    pair1.first = 1;
    pair1.second = 'a';

    pair<int, char> pair2 (1, 'a');

    pair<int, char> pair3;

    pair3 = make_pair(1, 'a');

    auto pair4 = make_pair(1, 'a');
}