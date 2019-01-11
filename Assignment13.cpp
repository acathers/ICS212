/* Name: Anthony Cathers
 * Core Concept: to use Inheritance and Polymorphism in a C++ program.
 * Date Created: 11/22/2018
 */
#include <iostream>
using namespace std;

class Person {

protected:
    string name;
    string campus;

public:

    void setName(const string &name) {
        Person::name = name;
    }

    void setCampus(const string &campus) {
        Person::campus = campus;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Campus: " << campus << endl;
        cout << endl;
    }

};

class Student : public Person {
private:
    int id;
    string major;

public:


    void setId(int id) {
        Student::id = id;
    }

    void setMajor(const string &major) {
        Student::major = major;
    }

    void displayStudent() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Campus: " << campus << endl;
        cout << "Major: " << major << endl;
        cout << endl;
    }

};


class Staff : public Person {
private:
    string id;
    string department;

public:

    void setId(const string &Id) {
        Staff::id = Id;
    }

    void setDepartment(const string &department) {
        Staff::department = department;
    }

    void displayStaff() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Campus: " << campus << endl;
        cout << "Major: " << department << endl;
        cout << endl;
    }

};


int main() {

    Student student;
    Staff staff;

    string userString;

    cout << "Enter student name: ";
    getline(cin, userString);
    student.setName(userString);

    cout << "Enter student ID: ";
    getline(cin, userString);

    student.setId(stoi(userString));

    cout << "Enter campus: ";
    getline(cin, userString);
    student.setCampus(userString);

    cout << "Enter major: ";
    getline(cin, userString);
    student.setMajor(userString);

    student.displayStudent();

    cout << "Enter staff name: ";
    getline(cin, userString);
    staff.setName(userString);

    cout << "Enter staff ID: ";
    getline(cin, userString);
    staff.setId(userString);

    cout << "Enter campus: ";
    getline(cin, userString);
    staff.setCampus(userString);

    cout << "Enter department: ";
    getline(cin, userString);
    staff.setDepartment(userString);

    staff.displayStaff();

    return 0;
};



