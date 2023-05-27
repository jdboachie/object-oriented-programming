// Converts temperature from Fahrenheit to Celcius and vice versa

#include <iostream>

using namespace std;

int main()
{
	char choice;

	cout << "Enter 'F' to convert from Celcius to Fahrenheit or 'C' to convert from Fahrenheit to Celcius: " <<endl;
	cin >> choice;

	if (choice == 'F' || choice == 'f')
	{
		double celcius;
		cout << "Enter temperature in Celcius: ";
		cin >> celcius;
		cout << "Temperature in Fahrenheit: " << (celcius * 9/5) + 32 << endl;
	}
	else if (choice == 'C' || choice == 'c')
	{
		double fahrenheit;
		cout << "Enter temperature in Fahrenheit: ";
		cin >> fahrenheit;
		cout << "Temperature in Celcius: " << (fahrenheit - 32) * 5/9 << endl;
	}
	else
	{
		cout << "Invalid choice" << endl;
	}

	return 0;
}
