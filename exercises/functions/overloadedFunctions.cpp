// Demonstrates function overloading
#include <iostream>

using namespace std;

// Declarations
void repchar();
void repchar(char);
void repchar(char, int);

int main()
{
    repchar();
    repchar('=');
    repchar('+', 30);

    return 0;
}

void repchar()
{
    for (int j = 0; j < 45; j++) // Always prints 45 times
    {
        cout << "*"; // Always prints *
    }
    cout << endl;
}

void repchar(char ch)
{
    for (int j = 0; j < 45; j++) // Always loops 45 times
    {
        cout << ch; // Prints specified character
    }
    cout << endl;
}

void repchar(char ch, int n)
{
    for (int j = 0; j < n; j++) // Loops n times
    {
        cout << ch; // Prints specified character
    }
    cout << endl;
}