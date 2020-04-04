#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>


//include split function
std::vector<std::string> split(std::string text, char separator, bool ignore_empty_parts = false){
    std::vector<std::string> result; //define a result vector of string type
    std::string temp = text; //define temp string variable
    while(temp.find(separator) != std::string::npos){
        std::string word = temp.substr(0, temp.find(separator));
        temp = temp.substr(temp.find(separator) + 1, temp.size());

        if(not(ignore_empty_parts and word.empty())){
            result.push_back(word);
        }
    }

    if(not(ignore_empty_parts and temp.empty())){
        result.push_back(temp);
    }
    return result;
}

int main(){

    std::string input_filename = "";
    std::cout << "Input file: ";
    std::cin >> input_filename;

    std::fstream ifile(input_filename);
    if(not ifile){
        std::cout << "Error! The file " << input_filename
                  << " cannot be opened." << std::endl;
        return EXIT_FAILURE;
    }

    std::string line = "";
    int line_number = 1;
    std::map<std::string, std::set<int>> container; //set can have one value once

    while(getline(ifile, line)){
        std::vector<std::string> word_by_word = split(line, ' ', true);

        for(std::string word : word_by_word){
            container[word].insert(line_number);
        }

        ++line_number;
    }
    ifile.close();
    for(auto data:container){
        std::set<int> the_set = data.second;
        std::cout << data.first << " " << the_set.size() << ": ";

        // this is for distinguishing whether put a comma or not
        // iterators cannot know whethere they are greater or lower, only == or !=
        // for(std::set<int>::iterator iter = the_set.begin(); iter != the_set.end(); ++iter)

        for(auto iter = the_set.begin(); iter != the_set.end(); ++iter){
            if(iter != the_set.begin()){
                std::cout << ", ";
            }
            std::cout << *iter;
        }
        std::cout << std::endl;
    }
}
