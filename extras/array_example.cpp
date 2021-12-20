#include <iostream>

using namespace std;

int main()
{
    int numbers[3];

    numbers[0] = 6;
    numbers[1] = 12;
    numbers[2] = 24;

    cout << numbers[0] + numbers[2] << endl;
    cout << numbers << endl;

    int* array_ptr = nullptr;
    array_ptr = numbers;
    while (array_ptr < numbers + 3) {
        cout << *array_ptr << endl;
        ++array_ptr;
    }
    cout << numbers + 2 << "," << *(numbers + 2) << endl;
}
