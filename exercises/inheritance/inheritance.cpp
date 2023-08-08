// Models employee database using inheritance
#include <iostream>

using namespace std;

const int LEN = 80; // Max Length of names

class Employee
{
private:
    char name[LEN]; // Employee name
    unsigned long number; // Employee number

public:
    void getdata()
    {
        cout << "\nEnter last name: "; cin >> name;
        cout << "Enter number: "; cin >> number;
    }

    void putdata() const
    {
        cout << "\nName: " << name;
        cout << "\nNumber: " << number;
    }
};

class Manager : public Employee // Management class
{
private:
    char title[LEN]; // "vice-president" etc.
    double dues; // golf club dues

public:
    void getdata()
    {
        Employee::getdata();
        cout << "Enter title: "; cin >> title;
        cout << "Enter golf club dues: "; cin >> dues;
    }

    void putdata() const
    {
        Employee::putdata();
        cout << "\nTitle: " << title;
        cout << "\nGolf club dues: " << dues;
    }
};

class Scientist : public Employee
{
private:
    int pubs; // number of publications

public:
    void getdata()
    {
        Employee::getdata();
        cout << "Enter number of pubs: "; cin >> pubs;
    }

    void putdata() const
    {
        Employee::putdata();
        cout << "\nNumber of publications: " << pubs;
    }
};

class Laborer : public Employee {};

int main()
{
    Manager m1, m2;
    Scientist s1;
    Laborer l1;

    cout << endl; // Get data for several employees
    cout << "\nEnter data for manager 1";
    m1.getdata();
    cout << "\nEnter data for manager 2";
    m2.getdata();
    cout << "\nEnter data for scientist";
    s1.getdata();
    cout << "\nEnter data for laborer";
    l1.getdata();

    // Display data for several employees
    cout << "\nData on manager 1";
    m1.putdata();
    cout << "\nData on manager 2";
    m2.putdata();
    cout << "\nData on scientist";
    s1.putdata();
    cout << "\nData on laborer";
    l1.putdata();
    cout << endl;

    return 0;
}
