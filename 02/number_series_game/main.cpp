#include <iostream>


int main()
{
    std::cout << "How many numbers would you like to have? ";
    int i = 0;
    std::cin >> i;

    for(int number = 1; number <= i; number++){
        if(number % 3 == 0 && number % 7 == 0)
            std::cout << "zip boing" << std::endl;
        else if(number % 3 == 0)
            std::cout << "zip" << std::endl;
        else if(number % 7 == 0)
            std::cout << "boing" << std::endl;
        else
            std::cout << number << std::endl;
    }
}
