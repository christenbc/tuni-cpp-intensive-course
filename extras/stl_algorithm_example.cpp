#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student{
    public:
        Student(string name, int student_id);
        string fetch_name() const;
        int fetch_student_id() const;
        void print();
    private:
        string name_;
        int id_;
};

bool compare_ids(const Student& stud1, const Student& stud2){
    if(stud1.fetch_student_id() < stud2.fetch_student_id())
        return true;
    else
        return false;
}

bool compare_names(const Student& stud1, const Student& stud2){
   if(stud1.fetch_name() < stud2.fetch_name())
       return true;
   else
       return false;
}


int main()
{
    vector<Student> students = {
        {"Teekari, Tiina", 121121},
        {"Arkkari, Antti", 111222},
        {"Fyysikko, Ville", 212121},
        {"Teekkari, Teemu", 10001},
        {"Kone, Kimmo", 233233}
    };

    sort(students.begin(), students.end(), compare_ids);
    for(auto stud : students)
        stud.print();

    cout << string(30,'-') << endl;

    sort(students.begin(), students.end(), compare_names);
    for(auto stud : students)
        stud.print();

    vector<Student>::iterator iter;
    iter = max_element(students.begin(), students.end(), compare_ids);
    iter->print();
}
