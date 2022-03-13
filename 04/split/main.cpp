#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //solves std is not a member of std

// TODO: Implement split function here
// Do not change main function

std::vector<std::string> split(std::string line, char separator, bool ignore = false)
{
    std::vector<std::string> result; //define a result vector of string type
    std::string temp = "";           //define temp string variable
    if (!ignore)
    { //don't ignore, include empty parts
        for (std::string::size_type i = 0; i < line.length(); i++)
        { //size_type is compatible with line.size
            if (line[i] == separator)
            {                               //if the character matches with separator
                result.push_back(temp);     //in the defined vector, you add new elements one by one at the end
                temp = "";                  //??
                if (i == line.length() - 1) //prior arriving the very end, it adds the last element
                    result.push_back(temp); // so blank spaces are made
            }
            else if (line[i] != separator)
            {                               //if the character is different than the separator
                temp += line[i];            //it will accumulate the characters contained in the input vector
                if (i == line.length() - 1) // when it gets to the very end, it adds the accumulated characters
                    result.push_back(temp);
            }
        }
    }
    else
    {   //ignore separators
        bool mark = false; //??
        for (std::string::size_type i = 0; i < line.length(); i++)
        {
            if (i == 0 && line[i] == separator) //if in the first character there is a separator
                mark = true;                    //??
            else if (line[i] == separator && !mark)
            { //if there is a separator but not in the first character
                mark = true;
                result.push_back(temp);
                temp = ""; //??
            }
            else if (line[i] != separator)
            { //if there is no separator on that character
                mark = false;
                temp += line[i];
                if (i == line.size() - 1)
                    result.push_back(temp);
            }
        }
    }
    return result;
}

int main()
{
    std::string line = "";
    std::cout << "Enter a string: ";
    getline(std::cin, line);
    std::cout << "Enter the separator character: ";
    char separator = getchar();

    std::vector<std::string> parts = split(line, separator);
    std::cout << "Splitted string including empty parts: " << std::endl;
    for (auto i : parts)
    {
        std::cout << i << std::endl;
    }

    std::vector<std::string> parts_no_empty = split(line, separator, true);
    std::cout << "Splitted string ignoring empty parts: " << std::endl;
    for (auto i : parts_no_empty)
    {
        std::cout << i << std::endl;
    }
}
