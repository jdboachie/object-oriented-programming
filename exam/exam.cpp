#include <iostream>
#include <string>

using namespace std;

class Fraction
{
private:
	int numerator;
	int denominator;
	int whole_number;

public:
	Fraction(int n, int d, int w=0)
	{
		numerator = n;
		denominator = d;
		whole_number = w;
	};

	float toDecimal()
	{
		// Converting to float type
		float w = this->whole_number;
		float n = this->numerator;
		float d = this->denominator;

		if (w == 0)
		{
			return n / d;
		}
		else if (n == 0)
			return w;
		else
			return w + (n / d);
	};

	virtual void showFraction()
	{
		cout << numerator << "/" << denominator;
	};

	virtual Fraction operator+(Fraction op2){
		return Fraction(0, 0, 0);
	};

	virtual Fraction operator*(Fraction op2){
		return Fraction(0, 0, 0);
	};
};

class ProperFraction : public Fraction
{
private:
	int numerator;
	int denominator;
public:
	ProperFraction (int n, int d) : Fraction (n, d, 0)
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
		return ProperFraction(newNumerator, newDenominator);
	};
	ProperFraction operator*(ProperFraction op2)
	{
		return ProperFraction(0, 0);
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
	ImproperFraction(int n, int d, int w=0, bool m=false) : Fraction(n, d, w)
	{
		this->numerator = n;
		this->denominator = d;
		this->whole_number = w;
		this->mixed = m;
	};

	void toMixedFraction(){};
	void toImproperFraction(){};

	void showFraction() override
	{
		cout << this->whole_number << "(" << this->numerator << "/" << this->denominator << ")";
	};
};

int main()
{
	ProperFraction f1(1, 2);
	ProperFraction f2(1, 3);
	ImproperFraction f3(1, 2, 3);

	ProperFraction f4 = f1 + f1;


	f1.showFraction();
	cout << " + ";
	f1.showFraction();
	cout << " = ";
	f4.showFraction();
	cout << " (" << f4.toDecimal() << ")" << endl;

	return 0;
}

/* God bless you for doing your best for us 💖 */