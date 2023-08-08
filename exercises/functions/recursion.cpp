// Calculates factorials using recursion
#include <iostream>

using namespace std;

unsigned long factfunc(unsigned long); // declaration

int main()
{
    int n;                   // number entered by user
    unsigned long factorial; // factorial
    cout << "Enter an integer: ";
    cin >> n;
    factorial = factfunc(n);
    cout << "Factorial of " << n << " is " << factorial << endl;
    return 0;
}

unsigned long factfunc(unsigned long n)
{
    if ((n == 0) || (n == 1))
    {
        return 1;
    }
    else
    {
        return n * factfunc(n - 1);
    }
}