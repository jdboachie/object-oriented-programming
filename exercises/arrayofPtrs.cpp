#include <iostream>

using namespace std;

class Person // class of persons
{
protected:
    char name[40]; // person's name

public:
    void setName() // set the name
    {
        cout << "Enter name: ";
        cin >> name;
    }

    void printName() // get the name
    {
        cout << "\nName is: " << name;
    }
};

int main()
{
    Person* persPtrs[100]; // array of pointers to persons
    int n = 0; // number of person in array
    char choice;

    do // put persons in array
    {
        persPtrs[n] = new Person; // make new object
        persPtrs[n]->setName(); // set person's name
        n++; // count new person
        cout << "Enter another (y/n)? ";
        cin >> choice; // get y or n
    } while (choice == 'y'); // quit on 'n'

    for (int i = 0; i < n; i++) // print names of all pesons
    {
        cout << "\nPerson number: " << i + 1;
        persPtrs[i]->printName();
    }
    
    cout << endl;
    return 0;
} // end main()