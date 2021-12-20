#include <iostream>
#include <string>

using namespace std;

class Person{
public:
    Person(string name, int age);
    string get_name() const;
    void celebrate_birthday(int next_age);
    void print() const;
private:
    string name_;
    int age_;
};

int main()
{
    Person pal("Matt", 18);
    cout << pal.get_name() << endl;
    pal.print();
    pal.celebrate_birthday(19);
    pal.print();
}

Person::Person(string name, int age):
    name_(name), age_(age)
{

}

string Person::get_name() const
{
    return name_;
}

void Person::celebrate_birthday(int next_age)
{
    age_ = next_age;
}

void Person::print() const
{
    cout << name_ << " : " << age_ << endl;
}
