#include <iostream>
#include <memory>

using namespace std;

int main()
{
    shared_ptr<int> int_ptr_1(new int(1));
    shared_ptr<int> int_ptr_2(make_shared<int> (9));

    cout << *int_ptr_1 << " " << *int_ptr_2 << endl;
    cout << int_ptr_1 << " " << int_ptr_2 << endl;
    cout << int_ptr_1.use_count() << " " << int_ptr_2.use_count() << endl << endl;

    *int_ptr_2 = *int_ptr_2 - 4;
    int_ptr_1 = int_ptr_2;

    cout << *int_ptr_1 << " " << *int_ptr_2 << endl;
    cout << int_ptr_1 << " " << int_ptr_2 << endl;
    cout << int_ptr_1.use_count() << " " << int_ptr_2.use_count() << endl;
}
