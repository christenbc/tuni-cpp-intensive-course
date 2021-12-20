#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    struct Product{
        string product_name;
        double price;
    };

    Product item = {"soap", 1.23};

    item.price *= 0.9;
    cout << item.product_name << ": " << item.price << endl;
    item = {"orange", 0.45};
}
