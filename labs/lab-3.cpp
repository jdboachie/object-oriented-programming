#include <iostream>

using namespace std;

int sum_to_n(int n);
int fibonacci(int n);
void generateFibonacciSequence(int n);

int main()
{
    cout << "Lab 3" << endl << "1. Sum of all numbers from 1 to n" << endl;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "The sum of all natural numbers from 1 to " << n << " is " << sum_to_n(n) << endl;

    cout << "2. Centimeters to Feet" << endl;
    double cm;
    cout << "Enter your height in centimeters: ";
    cin >> cm;
    cout << "Your height in feet is " << cm / 30.48 << endl;

    cout << "3. Fibonacci Sequence" << endl;
    int fib;
    cout << "Enter a number: ";
    cin >> fib;
    generateFibonacciSequence(fib);

    return 0;
}

int sum_to_n(int n)
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += i;
    }
    return res;
}

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void generateFibonacciSequence(int n)
{
    for (int i = 1; i < n; i ++)
    {
        cout << fibonacci(i) << " -> ";
    }
    cout << fibonacci(n) << endl;
}
