#include <iostream>
using namespace std;

int main()
{
    // demonstrates passing by reference
    void intfrac(float, float &, float &); // declaration
    float number, intpart, fracpart;       // float variables

    do
    {
        cout << "\nEnter a real number: "; // number from user
        cin >> number;
        intfrac(number, intpart, fracpart);   // find int and frac
        cout << "Integer part is " << intpart // print them
             << ", fraction part is " << fracpart << endl;
    } while (number != 0.0); // exit loop on 0.0
    return 0;
}

/**
 * infrac - function
 * @n: number from user
 * @intp: integer part of n
 * @fracp: fraction part of n
 *
 * desc - finds integer and fractional parts of a real number
 */
void intfrac(float n, float &intp, float &fracp)
{
    long temp = static_cast<long>(n); // convert to long
    intp = static_cast<float>(temp);  // back to float
    fracp = n - intp;                 // subtract integer part
}