#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main(){
    string input_filename = "";
    cout << "Input file: ";
    cin >> input_filename;

    string output_filename = "";
    cout << "Output file: ";
    cin >> output_filename;

    ifstream ifile(input_filename);
    if(not ifile){
        cout << "Error! The file " << input_filename << " cannot be opened." << endl;
        return EXIT_FAILURE;
    }else{
        int sum = 1;
        string line = "";
        ofstream ofile;
        ofile.open(output_filename);
        while(getline(ifile, line)){
            ofile << sum++ << " " << line << endl;
        }
    ofile.close();
    }
    ifile.close();
}
