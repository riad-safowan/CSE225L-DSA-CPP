#include<iostream>
#include "unsortedList.cpp"
using namespace std;

class StudentInfo
{
    friend bool operator==(StudentInfo s1, StudentInfo s2) {
        return s1.ID == s2.ID;
    }
    friend bool operator!=(StudentInfo s1, StudentInfo s2) {
        return s1.ID != s2.ID;
    }
private:
    long ID;
    string name;
    double cgpa;


public:

    StudentInfo() {}
    StudentInfo(long id, string name, double cgpa) {
        ID = id;
        this->name = name;
        this->cgpa = cgpa;
    }
    void SetID(long id) {
        ID = id;
    }

    void print() {
        cout << ID << " " << name << " " << cgpa << endl;
    }
    ~StudentInfo() {};
};




int main() {
    UnsortedList<int> list;

    list.InsertItem(5);
    list.InsertItem(7);
    list.InsertItem(6);
    list.InsertItem(9);

    for (int i = 0; i < list.GetLength(); i++) 
    {
        int x; list.GetNextItem(x);
        cout << x << " ";
    }
    cout << endl;
    list.ResetList();

    cout << "length of the list is : " << list.GetLength() << endl;

    list.InsertItem(1);

    for (int i = 0; i < list.GetLength(); i++)
    {
        int x; list.GetNextItem(x);
        cout << x << " ";
    }
    cout << endl;
    list.ResetList();


    int x; bool f;
    x = 4;
    list.RetrieveItem(x, f);
    cout << (f ? "Item is found" : "Item is not found") << endl;
    x = 5;
    list.RetrieveItem(x, f);
    cout << (f ? "Item is found" : "Item is not found") << endl;
    x = 9;
    list.RetrieveItem(x, f);
    cout << (f ? "Item is found" : "Item is not found") << endl;
    x = 10;
    list.RetrieveItem(x, f);
    cout << (f ? "Item is found" : "Item is not found") << endl;

    cout << (list.IsFull() ? "List is full" : "List is not full") << endl;

    list.DeleteItem(5);

    cout << (list.IsFull() ? "List is full" : "List is not full") << endl;

    list.DeleteItem(1);

    for (int i = 0; i < list.GetLength(); i++)
    {
        int x; list.GetNextItem(x);
        cout << x << " ";
    }
    cout << endl;
    list.ResetList();

    list.DeleteItem(6);

    for (int i = 0; i < list.GetLength(); i++)
    {
        int x; list.GetNextItem(x);
        cout << x << " ";
    }
    cout << endl;
    list.ResetList();

    UnsortedList<StudentInfo> students;
    students.InsertItem(StudentInfo(15234, "Jon", 2.6));
    students.InsertItem(StudentInfo(13732, "Tyrion", 3.9));
    students.InsertItem(StudentInfo(13569, "Sandor", 1.2));
    students.InsertItem(StudentInfo(15467, "Ramsey", 3.1));
    students.InsertItem(StudentInfo(16285, "Arya", 3.1));

    students.DeleteItem(StudentInfo(15467, "", 0.0));

    StudentInfo s; bool found;
    s.SetID(13569);
    students.RetrieveItem(s, found);
    if (found)
    {
        cout << "Item is found" << endl;
        s.print();
        cout << endl;
    }
    else {
        cout << "Item is not found" << endl;
    }


    for (int i = 0; i < students.GetLength(); i++)
    {
        StudentInfo x; students.GetNextItem(x);
        x.print();
    }
    cout << endl;
    students.ResetList();

    return 0;
}