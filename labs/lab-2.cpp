// BMI Calculator
#include <iostream>

using namespace std;

int main()
{
    double weight, height, bmi;

    cout << "What is your height in meters? ";
    cin >> height;
    cout << "What is your weight in kilograms? ";
    cin >> weight;

    bmi = weight / (height * height);

    cout << "Your BMI is " << bmi << " (kg/m^2)" << endl;

    if (bmi < 18.5)
    {
        cout << "You are underweight" << endl;
    }
    else if ((bmi > 18.5) && (bmi < 24.9))
    {
        cout << "Your weight is normal" << endl;
    }
    else if ((bmi > 30) && (bmi < 29.9))
    {
        cout << "You are overweight" << endl;
    }
    else if ((bmi > 30) && (bmi < 39.9))
    {
        cout << "You are obese" << endl;
    }
    else
    {
        cout << "You are morbidly obese." << endl;
    }

    return 0;
}