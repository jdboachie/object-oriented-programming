// conversions: Distance to metres, metres to Distance
#include <iostream>
using namespace std;


class Distance
{
private:
	const float MTF; // metres to feet
	int feet;
	float inches;

public:
	// constructor (no args)
	Distance() : feet(0), inches(0.0), MTF(3.280833) {}

	// constructor (one arg)
	Distance(float meters) : MTF(3.280833)
	{
		// convert metres to Distance
		float fltfeet = MTF * meters;
		feet = int(fltfeet);
		inches = 12 * (fltfeet - feet);
	}

	// constructor (two args)
	Distance(int ft, float in) : feet(ft), inches(in), MTF(3.280833) {}

	void showDist() const
	{
		// display Distance
		cout << feet << "\'-" << inches << '\"' << endl;
	}

	operator float()
	{
		// converts Distance to meters
		float fracfeet = inches/12;
		fracfeet += static_cast<float>(feet);
		return fracfeet/MTF; // convert to metres
	}
};

int main()
{
	float mtrs;
	Distance dist1 = 2.35;

	cout << "\ndist1 = "; dist1.showDist();

	mtrs = static_cast<float>(dist1); // uses conversion
	cout << "\ndist1 = " << mtrs << " metres\n";

	Distance dist2(5, 10.25); // uses 2-arg constructor
	mtrs = dist2; // also uses conversion op
	cout << "\ndist2 = " << mtrs << " metres\n";

	return 0;
}