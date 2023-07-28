#include <iostream>
#include <string>

using namespace std;

class YouTubeChannel
{
public:
	string name;
	int subCount;

	YouTubeChannel(string name, int subCount)
	{
		this->name = name;
		this->subCount = subCount;
	}

	friend ostream &operator<<(ostream &os, const YouTubeChannel &yt)
	{
		os << "Name: " << yt.name << endl;
		os << "Subscribers: " << yt.subCount << endl;
		return os;
	}
};

int main()
{
	YouTubeChannel yt1 = YouTubeChannel("Grade A Under A", 3680000);
	cout << yt1;
	return 0;
}
