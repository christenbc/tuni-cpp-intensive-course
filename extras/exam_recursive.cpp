#include <iostream>
#include <vector>

using namespace std;

int greatest_element(vector<int> vec, int lower_index, int upper_index){
    if(lower_index == upper_index)
        return vec.at(lower_index);
    else if(vec.at(lower_index) > greatest_element(vec, lower_index + 1, upper_index))
        return vec.at(lower_index);
    else
        return greatest_element(vec, lower_index + 1, upper_index);
}

int main(){
    int vec_len = 0;
    cout << "enter the size of the vector: ";
    cin >> vec_len;

    vector<int> vec;

    for(int i=0; i < vec_len; i++){
        int j = 0;
        cout << "enter " << i << " element: ";
        cin >> j;
        vec.push_back(j);
    }
    cout << "Max element in the vector is " << greatest_element(vec, 0, vec_len-1) << endl;
}
