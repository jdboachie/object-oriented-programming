/**
 * @name: Jude Boachie
 * @index: 7095021
 * @class: Computer Engineering 2
 */

#include <iostream>

using namespace std;

/**
 * @class Util
 * @brief A utility class containing mathematical functions.
 */
class Util
{
public:
	/**
	 * @brief Calculate the greatest common divisor (GCD) of two numbers.
	 *
	 * This function calculates the GCD using the Euclidean algorithm.
	 * It recursively calculates the GCD until one of the numbers becomes zero.
	 *
	 * @param a The first integer.
	 * @param b The second integer.
	 * @return The greatest common divisor of 'a' and 'b'.
	 */
	static int gcd(int a, int b)
	{
		if (a == 0)
			return b;
		return gcd(b % a, a);
	}
};

/**
 * @class Fraction
 * @brief Represents a fraction with an optional whole number part.
 */
class Fraction
{
private:
	int numerator;	  /**< The numerator of the fraction. */
	int denominator;  /**< The denominator of the fraction. */
	int whole_number; /**< The whole number part of the fraction. */

public:
	/**
	 * @brief Constructor for Fraction class.
	 *
	 * @param n The numerator of the fraction.
	 * @param d The denominator of the fraction.
	 * @param w The optional whole number part of the fraction (default is 0).
	 */
	Fraction(int n, int d, int w = 0)
	{
		numerator = n;
		denominator = d;
		whole_number = w;
	};

	/**
	 * @brief Convert the fraction to its decimal representation.
	 *
	 * This function converts the fraction, including any whole number part,
	 * to its decimal representation. If there is no whole number part, it
	 * returns the fractional part as a decimal. If there is no fractional part,
	 * only the whole number part is returned as a decimal.
	 *
	 * @return The decimal representation of the fraction.
	 */
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

	/**
	 * @brief Display the fraction in a human-readable format.
	 *
	 * This function displays the fraction as a human-readable string.
	 * If the numerator is equal to the denominator, it displays "1".
	 * If the numerator is zero, it displays "0". Otherwise, it displays
	 * the fraction in the format "numerator/denominator".
	 */
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

	/**
	 * @brief Addition operator for fractions.
	 *
	 * This operator performs addition of two fractions.
	 *
	 * @param op2 The second fraction to be added.
	 * @return The result of adding the two fractions.
	 */
	virtual Fraction operator+(Fraction op2)
	{
		return Fraction(0, 0, 0); // Placeholder implementation, needs to be defined
	};

	/**
	 * @brief Multiplication operator for fractions.
	 *
	 * This operator performs multiplication of two fractions.
	 *
	 * @param op2 The second fraction to be multiplied.
	 * @return The result of multiplying the two fractions.
	 */
	virtual Fraction operator*(Fraction op2)
	{
		return Fraction(0, 0, 0); // Placeholder implementation, needs to be defined
	};
};

/**
 * @class ProperFraction
 * @brief Represents a proper fraction (a fraction where the numerator is less than the denominator).
 *
 * This class inherits from the base class Fraction and provides additional
 * operations for proper fractions.
 */
class ProperFraction : public Fraction
{
private:
	int numerator;	 /**< The numerator of the proper fraction. */
	int denominator; /**< The denominator of the proper fraction. */

public:
	/**
	 * @brief Constructor for ProperFraction class.
	 *
	 * @param n The numerator of the proper fraction.
	 * @param d The denominator of the proper fraction.
	 */
	ProperFraction(int n, int d) : Fraction(n, d, 0)
	{
		this->numerator = n;
		this->denominator = d;
	};

	/**
	 * @brief Addition operator for proper fractions.
	 *
	 * This operator performs addition of two proper fractions.
	 *
	 * @param op2 The second proper fraction to be added.
	 * @return The result of adding the two proper fractions.
	 */
	ProperFraction operator+(ProperFraction op2)
	{
		int n1 = this->numerator;
		int d1 = this->denominator;
		int n2 = op2.numerator;
		int d2 = op2.denominator;

		int newNumerator = (n1 * d2) + (d1 * n2);
		int newDenominator = d1 * d2;

		// reduce the fraction
		int GCD = Util::gcd(newNumerator, newDenominator);

		return ProperFraction(newNumerator / GCD, newDenominator / GCD);
	};

	/**
	 * @brief Multiplication operator for proper fractions.
	 *
	 * This operator performs multiplication of two proper fractions.
	 *
	 * @param op2 The second proper fraction to be multiplied.
	 * @return The result of multiplying the two proper fractions.
	 */
	ProperFraction operator*(ProperFraction op2)
	{
		int n1 = this->numerator;
		int d1 = this->denominator;
		int n2 = op2.numerator;
		int d2 = op2.denominator;

		int newNumerator = n1 * n2;
		int newDenominator = d1 * d2;

		// reduce the fraction
		int GCD = Util::gcd(newNumerator, newDenominator);

		return ProperFraction(newNumerator / GCD, newDenominator / GCD);
	};
};

/**
 * @class ImproperFraction
 * @brief Represents an improper fraction (a fraction where the numerator is greater than or equal to the denominator).
 *
 * This class inherits from the base class Fraction and provides additional
 * operations for improper fractions, including conversion between mixed and improper forms.
 */
class ImproperFraction : public Fraction
{
private:
	int numerator;	  /**< The numerator of the improper fraction. */
	int denominator;  /**< The denominator of the improper fraction. */
	int whole_number; /**< The whole number part of the improper fraction. */
	bool mixed;		  /**< Flag indicating whether the fraction is in mixed form. */

public:
	/**
	 * @brief Constructor for ImproperFraction class.
	 *
	 * @param n The numerator of the improper fraction.
	 * @param d The denominator of the improper fraction.
	 * @param w The optional whole number part of the improper fraction (default is 0).
	 */
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

	/**
	 * @brief Convert the improper fraction to mixed form.
	 *
	 * This function converts the improper fraction to mixed form by breaking down the
	 * whole number part and adjusting the numerator.
	 */
	void toMixedFraction()
	{
		if (!this->mixed)
		{
			this->whole_number = this->numerator / this->denominator;
			this->numerator = this->numerator % this->denominator;
			this->mixed = true;
		}
	};

	/**
	 * @brief Convert the mixed fraction to improper form.
	 *
	 * This function converts the mixed fraction to improper form by combining the
	 * whole number part with the numerator.
	 */
	void toImproperFraction()
	{
		if (this->mixed)
		{
			this->numerator = (this->whole_number * this->denominator) + this->numerator;
			this->whole_number = 0;
			this->mixed = false;
		}
	};

	/**
	 * @brief Display the improper fraction in a human-readable format.
	 *
	 * This function displays the improper fraction as a human-readable string.
	 * If the numerator is zero, it displays only the whole number part.
	 * If the fraction is in mixed form, it displays the mixed form, otherwise
	 * it displays the improper fraction in the format "numerator/denominator".
	 */
	void showFraction() override
	{
		if (numerator == 0)
			cout << this->whole_number;
		else if (this->mixed)
			cout << this->whole_number << "'" << this->numerator << "/" << this->denominator;
		else
			cout << this->numerator << "/" << this->denominator;
	};

	/**
	 * @brief Addition operator for improper fractions.
	 *
	 * This operator performs addition of two improper fractions.
	 *
	 * @param op2 The second improper fraction to be added.
	 * @return The result of adding the two improper fractions.
	 */
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

	/**
	 * @brief Multiplication operator for improper fractions.
	 *
	 * This operator performs multiplication of two improper fractions.
	 *
	 * @param op2 The second improper fraction to be multiplied.
	 * @return The result of multiplying the two improper fractions.
	 */
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
	ProperFraction f2(5, 3); // Counterintuitive but just trust me :)
	ImproperFraction f3(3, 4, 2);
	ImproperFraction f4(5, 3);

	// Solution Fractions
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

	// No bugs yayy!
	return 0;
}

/* God bless you for doing your best for us 💖 */