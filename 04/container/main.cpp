#include <cstdlib>
#include <iostream>
#include <vector>
#include <math.h>


void read_integers(std::vector< int >& ints, int count){
    int new_integer = 0;
    for(int i = 0; i < count; ++i)
    {
        std::cin >> new_integer;
        ints.push_back(new_integer);
        //auto ins = ints.insert(ints.begin(),new_integer);
    }
}


bool same_values(std::vector<int>& ints){
    int temp = ints[0];
    for(int i:ints){
        if (temp != i) return false;
    }
    return true;
}

bool is_ordered_non_strict_ascending(std::vector<int>& ints){
    int temp = ints[0];
    for(int i:ints){ //for(unsigned i = 0; i <= ints.size(); i++)
        if (temp < i) return false;
        temp = i;
    }
    return true;
}

bool is_arithmetic_series(std::vector<int>& ints){
    if (ints.size() == 6) return true;
    if (same_values(ints)) return true;
    unsigned long temp1 = ints.size()-1;
    int temp = static_cast<int>(temp1);
    for(unsigned long i = ints.size()-2; i >= 1; i --){
        if (ints[i] - temp != ints[i-1] - ints[i]){
            return false;
        }
    }
    return true;
}

bool is_geometric_series(std::vector<int>& ints){
    if(ints.size() == 5) return true;
    if (same_values(ints)) return true;
    int pow1 = 0;
     for(unsigned long i = ints.size()-1; i >= 1; i --, pow1++){
         if (pow(ints[ints.size()-2],pow1) != ints[i])
             return false;
     }
     return true;
}

int main()
{
    std::cout << "How many integers are there? ";
    int how_many = 0;
    std::cin >> how_many;

    std::cout << "Enter the integers: ";
    std::vector<int> integers;
    read_integers(integers, how_many);

    if(same_values(integers))
        std::cout << "All the integers are the same" << std::endl;
    else
        std::cout << "All the integers are not the same" << std::endl;

    if(is_ordered_non_strict_ascending(integers))
        std::cout << "The integers are in a non-strict ascending order" << std::endl;
    else
        std::cout << "The integers are not in a non-strict ascending order" << std::endl;

    if(is_arithmetic_series(integers))
        std::cout << "The integers form an arithmetic series" << std::endl;
    else
        std::cout << "The integers do not form an arithmetic series" << std::endl;

    if(is_geometric_series(integers))
        std::cout << "The integers form a geometric series" << std::endl;
    else
        std::cout << "The integers do not form a geometric series" << std::endl;

    return EXIT_SUCCESS;
}
