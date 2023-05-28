#include <iostream>

double exponent(double base, int power);

int main()
{
	double base, result;
	int power;

	std::cout << "Enter base: ";
	std::cin >> base;

	std::cout << std::endl
			  << "Enter power: ";
	std::cin >> power;

	exponent(base, power);

	return 0;
}

double exponent(double base, int power)
{
	int result = 1;
	for (int i = 0; i < power; i++)
	{
		result *= base;
		std::cout << result << "->";
	}
	std::cout << "Result: " << result << std::endl;
	return result;
}
