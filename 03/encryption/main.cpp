#include <iostream>
#include <cctype>
#include <string>

using namespace std;
const string ALPHABET = "abcdefghijklmnopqrstuvwxyz";

int main(){
    string key = "";
    cout << "Enter the description key: ";
    getline(cin, key);

    if(key.length() != ALPHABET.length()){
        cout << "Error! The encryption key must contain 26 characters." << endl;
        return EXIT_FAILURE;
    }

    for(unsigned i = 0; i < key.length(); i++){
        if(isupper(key.at(i))){ //include cctype
            cout << "Error! The encryption key must contain only lower case characters." << endl;
            return EXIT_FAILURE;
        }else if(key.find(ALPHABET.at(i)) == string::npos){
            cout << "Error! The encryption key must contain all alphabets a-z." <<endl;
            return EXIT_FAILURE;
        }
    }

    string text = "";
    cout << "Enter the text to be encrypted: ";
    getline(cin, text);

    string encryption = "";
    unsigned location = 0;

    for(unsigned i = 0; i < text.length(); i++){
        location = ALPHABET.find(text.at(i));
        encryption += key.at(location);
    }
    cout << "Encrypted text: " << encryption << endl;
}
