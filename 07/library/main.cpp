/* Author: Christen Blom-Dahl Casanova
 *
 * This project has a struct which contains the
 * book data in the libraries
 * Also it search which books are
 * lonable, all the libraries, the author of
 * a book and its reservation, where you can
 * take a book where it has the minimum
 * reservations.
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <map>
#include <utility>

using namespace std;

// Requierement of struct Book
// If book reservation "on the shelf", reservation = 0
struct Book {
    string title;
    string author;
    int reservations;
};

// Function pre-declaration
vector<string> split(const string& s, const char delimiter, bool ignore_empty = false);
map<string,list<Book>> store_info(vector<string> line_split, map<string,list<Book>> info);
void interface(vector<string> line_split, map<string,list<Book>> info);
void print_libraries(map<string,list<Book>> info);
void print_books(string author, list<Book> books);
void print_reservable(string book, map<string,list<Book>> info);
void print_lonable_books(map<string, list<Book>> info);


int main(){
    //Strucute with all libraries and books information
    map<string,list<Book>> info;

    // Data obtainance input from a file and error check
    string filename = "";
    cout << "Input file: ";
    getline(cin, filename);
    ifstream file_object(filename);
    //Errors
    if ( not file_object ){
        cout << "Error: the input file cannot be opened" << endl;
        return EXIT_FAILURE;
    }
    string line;
    vector<string> line_split;
    while (getline(file_object,line)){
        line_split = split(line,';',true);
        //Check if correct content of the file
        if (line_split.size() != 4){
            cout << "Error: empty field" << endl;
            return EXIT_FAILURE;
        }
        info = store_info(line_split,info);
    }

    // Quit user interface by command
    while(line != "quit"){
        cout << "> ";
        getline(cin,line);
        if(line != "quit"){
            line_split = split(line,' ');
            interface(line_split, info);
        }
    }
    return EXIT_SUCCESS;
}


void print_lonable_books(map<string, list<Book>> info){
    /* parameter_1: book, the book title we want to search
     * print all lonable books in their correspondent libraries
     */
    list<pair<string,string>> author_title;
    for(auto const& library : info){
        for(auto const& book : library.second){
            if (book.reservations == 0){
                pair<string,string> temp (book.author,book.title);
                author_title.push_back(temp);
            }
        }
    }
    author_title.sort();
    for(auto const& param : author_title)
       cout << param.first << ": " << param.second << endl;
}

void print_reservable(string book, map<string,list<Book>> info){
    /* parameter_1: book, the book title we want to search
     * parameter_2: info, data structure with the whole information
     * print all libraries which have the book with the least demanded
     */

    // Additional structures
    map<int,list<string>> reserve_library;
    map<int,list<string>>::iterator it;
    list<Book> books;

    // Search book with reservation
    for (auto const& library : info){
        books = library.second;
        for(auto const& i_book : books){
            if(i_book.title == book){
                it = reserve_library.find(i_book.reservations);
                list<string> libraries;
                if(it != reserve_library.end())
                    libraries = it->second;
                libraries.push_back(library.first);
                reserve_library[i_book.reservations] = libraries;
            }
        }
    }

    //Print libraries and reservaion
    if (reserve_library.empty())
        cout << "Book is not a library book." << endl;
    else if (reserve_library.begin()->first >= 100)
        cout << "The book is not reservable from any library." << endl;
    else{
        if (reserve_library.begin()->first == 0)
            cout << "on the shelf" << endl;
        else
            cout << reserve_library.begin()->first << " reservations" << endl;
        for(auto const& library : reserve_library.begin()->second)
            cout << "--- " << library << endl;
    }
}

void print_books(string author, list<Book> books){
    /* param1 = author, author of the books to search
     * param2 = books, list of the books to search
     * return = None
     * Prints in order the books of a specific author
     * and its reservations
     */

    /*Create a map to not repeat books when print and
    to be in order */
    map<string,int> books_reservations;
    for (auto const& i : books){
        if (i.author == author)
            books_reservations[i.title] = i.reservations;
    }
    for (auto const& i :books_reservations){
        if(i.second == 0)
            cout << i.first << " --- " << "on the shelf" << endl;
        else
            cout << i.first << " --- " << i.second << " reservations" << endl;
    }
    if (books_reservations.empty())
        cout << "Error: unknown author" << endl;
}

void print_material(list<Book> books){
    /* param1: list os Books an its titles, authors
     * and reservations
     * return: None
     * Prints a orderer list of books with its authors
     */
    books.sort([](const Book& a,const Book& b){
        return a.author < b.author;});

    //Create a pair to not repeat books when print
    pair<string,string> last_book("","");
    for(auto const& i : books){
        if (last_book.first != i.author or last_book.second != i.title){
            cout << i.author << ": " << i.title << endl;
            last_book.first = i.author;
            last_book.second = i.title;
        }
    }
}

void print_libraries(map<string,list<Book>> info){
    /* param1: info, data structure with all information
     * return: None
     * Print all libraries in alphabetical order
     */

    map<string, list<Book>>::iterator it;
    for(it = info.begin(); it != info.end(); it++)
        cout << it->first << endl;
}

void interface(vector<string> line_split, map<string,list<Book>> info){
    /* param1: line_split, line write by user by console
     * param2: info, data structure with all information
     * return: None
     * This function is the user interface and calls the rest of
     * the methonds necesaries in the program
     */

    if (line_split[0] == "libraries"){
        if (line_split.size() != 1)
            cout << "Error: error in command libraries" << endl;
        else
            print_libraries(info);

    }else if(line_split[0] == "material"){
        if (line_split.size() != 2)
            cout << "Error: error in command material" << endl;
        else {
            map<string,list<Book>>::iterator it = info.find(line_split[1]);
            if(it == info.end())
                cout << "Error: unknown library name" << endl;
            else
                print_material(it->second);
        }

    }else if(line_split[0] == "books"){
        if (line_split.size() != 3)
            cout << "Error: error in command books" << endl;
        else {
            map<string,list<Book>>::iterator it = info.find(line_split[1]);
            if(it != info.end())
                print_books(line_split[2],it->second);
            else
                cout << "Error: unknown library name" << endl;
        }

    }else if(line_split[0] ==  "reservable"){
        if (line_split.size() == 1)
            cout << "Error: error in command reservable" << endl;
        else {
            /* As in split we have a vector separate with ' ' we have
             to append the words of the book */
            string name_book = "";
            for(unsigned long i = 1; i < line_split.size(); i++){
                if (i == line_split.size()-1)
                    name_book += line_split[i];
                else
                    name_book += line_split[i] + " ";
            }
            print_reservable(name_book,info);
        }

    }else if(line_split[0] == "loanable"){
        if (line_split.size() != 1)
            cout << "Error: error in command loanable" << endl;
        else
            print_lonable_books(info);

    }else
        cout << "Error: Unknown command: " << line_split[0] << endl;
}

map<string,list<Book>> store_info(vector<string> line_split, map<string,list<Book>> info){
    /* param1: line_split, line reade from the file split in parts
     * param2: info, map that contains all libraries and books info
     * return: None
     * This function store the line_split in the info
     */

    //Create the struct
    Book book;
    if (line_split[3] == "on-the-shelf")
        book = {line_split[2],line_split[1],0};
    else
        book = {line_split[2],line_split[1],stoi(line_split[3])};

    //Store the struct in map
    map<string,list<Book>>::iterator it = info.find(line_split[0]);
    if (it == info.end()){
        list<Book> books;
        books.push_back(book);
        info[line_split[0]] = books;
    }else {
        list<Book> books = it->second;
        books.push_back(book);
        info.erase(it);
        info[line_split[0]] = books;
    }
    return info;
}

//Function implemented in exercise 6.5 sum
vector<string> split(const string& s, const char delimiter, bool ignore_empty){
    vector<std::string> result;
    string tmp = s;
    while(tmp.find(delimiter) != string::npos){
        string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter)+1, tmp.size());
        if(not (ignore_empty and new_part.empty()))
            result.push_back(new_part);
    }
    if(not (ignore_empty and tmp.empty()))
        result.push_back(tmp);
    return result;
}
