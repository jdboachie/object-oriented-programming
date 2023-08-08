#include <iostream>
#include <cstring> // for strlen

using namespace std;

int main()
{
    const char* str = "Idle hands are the devil's workshop.";
    int len = strlen(str); // get the length of str

    char* ptr; // make a pointer to char
    ptr = new char[len + 1]; // set aside memory: string + null('\0')

    strcpy(ptr, str); // copy str to new memory area ptr

    cout << "ptr = " << ptr << endl; // display contents of ptr
    delete[] ptr; // release ptr's memory
    return 0;
}