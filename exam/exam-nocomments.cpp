#include <iostream>

using namespace std;

class Util
{
public:
	static int gcd(int a, int b)
	{
		if (a == 0)
			return b;
		return gcd(b % a, a);
	}
};

class Fraction
{
private:
	int numerator;
	int denominator;
	int whole_number;

public:
	Fraction(int n, int d, int w = 0)
	{
		numerator = n;
		denominator = d;
		whole_number = w;
	};

	float toDecimal() const
	{
		float w = static_cast<float>(this->whole_number);
		float n = static_cast<float>(this->numerator);
		float d = static_cast<float>(this->denominator);

		if (w == 0)
		{
			return n / d;
		}
		else if (n == 0)
		{
			return w;
		}
		else
		{
			return w + (n / d);
		}
	};

	virtual void showFraction()
	{
		if (numerator == denominator)
		{
			cout << 1;
		}
		else if (numerator == 0)
		{
			cout << 0;
		}
		else
		{
			cout << numerator << "/" << denominator;
		}
	};

	virtual Fraction operator+(Fraction op2)
	{
		return Fraction(0, 0, 0);
	};

	virtual Fraction operator*(Fraction op2)
	{
		return Fraction(0, 0, 0);
	};
};

class ProperFraction : public Fraction
{
private:
	int numerator;
	int denominator;

public:
	ProperFraction(int n, int d) : Fraction(n, d, 0)
	{
		this->numerator = n;
		this->denominator = d;
	};

	ProperFraction operator+(ProperFraction op2)
	{
		int n1 = this->numerator;
		int d1 = this->denominator;
		int n2 = op2.numerator;
		int d2 = op2.denominator;

		int newNumerator = (n1 * d2) + (d1 * n2);
		int newDenominator = d1 * d2;

		int GCD = Util::gcd(newNumerator, newDenominator);

		return ProperFraction(newNumerator / GCD, newDenominator / GCD);
	};

	ProperFraction operator*(ProperFraction op2)
	{
		int n1 = this->numerator;
		int d1 = this->denominator;
		int n2 = op2.numerator;
		int d2 = op2.denominator;

		int newNumerator = n1 * n2;
		int newDenominator = d1 * d2;

		int GCD = Util::gcd(newNumerator, newDenominator);

		return ProperFraction(newNumerator / GCD, newDenominator / GCD);
	};
};

class ImproperFraction : public Fraction
{
private:
	int numerator;
	int denominator;
	int whole_number;
	bool mixed;

public:
	ImproperFraction(int n, int d, int w = 0) : Fraction(n, d, w)
	{
		this->numerator = n;
		this->denominator = d;
		this->whole_number = w;

		if (w == 0)
			this->mixed = false;
		else
			this->mixed = true;
	};

	void toMixedFraction()
	{
		if (!this->mixed)
		{
			this->whole_number = this->numerator / this->denominator;
			this->numerator = this->numerator % this->denominator;
			this->mixed = true;
		}
	};

	void toImproperFraction()
	{
		if (this->mixed)
		{
			this->numerator = (this->whole_number * this->denominator) + this->numerator;
			this->whole_number = 0;
			this->mixed = false;
		}
	};

	void showFraction() override
	{
		if (numerator == 0)
			cout << this->whole_number;
		else if (this->mixed)
			cout << this->whole_number << "'" << this->numerator << "/" << this->denominator;
		else
			cout << this->numerator << "/" << this->denominator;
	};

	ImproperFraction operator+(ImproperFraction op2)
	{
		this->toImproperFraction();
		op2.toImproperFraction();

		int n1 = this->numerator;
		int d1 = this->denominator;
		int n2 = op2.numerator;
		int d2 = op2.denominator;

		int newNumerator = (n1 * d2) + (d1 * n2);
		int newDenominator = d1 * d2;

		ImproperFraction result(newNumerator, newDenominator);
		result.toMixedFraction();

		return result;
	};

	ImproperFraction operator*(ImproperFraction op2)
	{
		this->toImproperFraction();
		op2.toImproperFraction();

		int n1 = this->numerator;
		int d1 = this->denominator;
		int n2 = op2.numerator;
		int d2 = op2.denominator;

		int newNumerator = n1 * n2;
		int newDenominator = d1 * d2;

		ImproperFraction result(newNumerator, newDenominator);
		result.toMixedFraction();
		return result;
	};
};

int main()
{
	ProperFraction f1(1, 2);
	ProperFraction f2(5, 3);
	ImproperFraction f3(3, 4, 2);
	ImproperFraction f4(5, 3);

	ProperFraction ansA = f1 + f1;
	ImproperFraction ansB = f3 + f4;
	ProperFraction ansC = f2 * f1;
	ImproperFraction ansD = f3 * f4;

	cout << "a. ";
	ansA.showFraction();
	cout << endl
		 << "b. ";
	ansB.showFraction();
	cout << endl
		 << "c. ";
	ansC.showFraction();
	cout << endl
		 << "d. ";
	ansD.showFraction();
	cout << endl
		 << "e. Abi your eye get XD?" << endl
		 << "f. "
		 << f1.toDecimal() << endl
		 << "g. "
		 << f2.toDecimal() << endl
		 << "h. "
		 << f3.toDecimal() << endl
		 << "i. On (decimal) point!" << endl;

	return 0;
}
