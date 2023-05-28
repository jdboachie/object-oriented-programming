#include <iostream>

int zeroSmaller(int &a, int &b);

int main()
{
    int a, b;

    std::cout << "Num 1: ";
    std::cin >> a;
    std::cout << "Num 2: ";
    std::cin >> b;

    zeroSmaller(a, b);

    std::cout << "(" <<  a << ", " << b << ")" << std::endl;
}

int zeroSmaller(int &a, int &b)
{
    if (a < b)
    {
        a = 0;
        return a;
    }
    else
    {
        if (a == b)
        {
            a = 0;
            return a;
        }
        else
        {
            b = 0;
            return b;
        }
    }
    return 0;
}
