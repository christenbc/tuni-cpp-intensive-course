#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<double> numbers = {1.0, 1.5, 2.0, 2.75};
    vector<double>::iterator vec_iter;

    vec_iter = numbers.begin();
    while (vec_iter != numbers.end()) {
        cout << *vec_iter << " ";
        ++vec_iter;
    }
}