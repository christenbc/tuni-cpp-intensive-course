#include <iostream>
#include <vector>
#include <string>

using namespace std;

int step_by_step(string integer, unsigned i){
    if(i == integer.length())
        return integer.back();
    else{
        cout << integer.at(i) << endl;
        i++;
        return step_by_step(integer, i);
    }
}

int main(){
    string integer = "";
    cout << "enter an integer: ";
    cin >> integer;

    step_by_step(integer, 0);
}
