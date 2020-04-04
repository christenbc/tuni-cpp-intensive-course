#include <iostream>


using namespace std;

int main()
{
    string limitstr;
    cout << "Enter an upper bound: ";
    getline(cin, limitstr);

    cout << "Prime numbers smaller than " << limitstr << ':' << endl;
    int limit = stoi(limitstr);

    for(int var = 2; var <= limit; var++){
        int counter = 0;
        for(int i = 2; i <= var/2; i++){
            if(var % i == 0) counter++;
        }
        if(counter == 0) cout << var << " ";
    }
    cout << endl;
    return 0;
}
