#include <iostream>

using namespace std;

void lottery(int total, int drawn){
    if(drawn < 0 || total < 0){
        cout << "The number of balls must be a positive number." << endl;
    }else if(drawn > total){
        cout << "The maximum number of drawn balls is the total amount of balls." << endl;
    }else{
        int fact_total = 1;
        for(int i = total; i >= 1; i--)
            fact_total *= i;

        int fact_drawn = 1;
        for(int i = drawn; i >= 1; i--)
            fact_drawn *= i;

        int fact_substr = 1;
        for(int i = total - drawn; i >= 1; i--)
            fact_substr *= i;

        int comb = 0;
        comb = fact_total / (fact_substr * fact_drawn);
        cout << "The probability of guessing all " << drawn << " balls correctly is " << "1/" << comb << endl;
    }
}

int main()
{

    cout << "Enter the total number of lottery balls: ";
    int a = 0;
    cin >> a;

    cout << "Enter the number of drawn balls: ";
    int b = 0;
    cin >> b;

    lottery(a, b);
    return 0;
}
