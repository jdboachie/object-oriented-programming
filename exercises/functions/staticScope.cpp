// Demonstrates static variables
#include <iostream>

using namespace std;

float getavg(float); // Declaration

int main()
{
    float data = 1.0, avg;

    while (data != 0.0)
    {
        cout << "Enter a number (0 to quit): ";
        cin >> data;
        avg = getavg(data);
        cout << "Average so far is " << avg << endl;
    }
    return 0;
}

float getavg(float newdata)
{
    static float total = 0;
    static int count = 0;
    count ++;
    total += newdata;
    return total / count;
}