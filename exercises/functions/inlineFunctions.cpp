// Demonstrates inline functions
#include <iostream>

using namespace std;

inline float lbstokg(float lbs)
{
    return 0.453592 * lbs;
}

int main()
{
    float lbs;
    cout << "\nEnter your weight in pounds: ";
    cin >> lbs;
    cout << "Your weight in kilograms is " << lbstokg(lbs) << endl;
    return 0;
}