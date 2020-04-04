#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a number: ";
    int i = 0;
    cin >> i;

    int value = 1;
    for(int number = 1; number <= i; number++)
        value *= i;
    if(value < 0){
        cout << "Error! The cube of << " << i << " is not " << value << "." << endl;
    }else{
        cout << "The cube of " << i << " is " << value << "." << endl;
    }
}
