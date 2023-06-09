#include <iostream>

int sum_to_n(int n);
int fibonacci(int n);
void generateFibonacciSequence(int n);

int main()
{
    std::cout << "Lab 3" << std::endl << "1. Sum of all numbers from 1 to n" << std::endl;
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    std::cout << "The sum of all natural numbers from 1 to " << n << " is " << sum_to_n(n) << std::endl;

    std::cout << "2. Centimeters to Feet" << std::endl;
    double cm;
    std::cout << "Enter your height in centimeters: ";
    std::cin >> cm;
    std::cout << "Your height in feet is " << cm / 30.48 << std::endl;

    std::cout << "3. Fibonacci Sequence" << std::endl;
    int fib;
    std::cout << "Enter a number: ";
    std::cin >> fib;
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
        std::cout << fibonacci(i) << " -> ";
    }
    std::cout << fibonacci(n) << std::endl;
}
