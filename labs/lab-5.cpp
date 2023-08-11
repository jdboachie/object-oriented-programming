#include <iostream>
#include <list>

using namespace std;

class YoutubeChannel
{

private:
    int SubscriberCount;
    string Name;
    string OwnerName;
    list<string> PublishedVideoTitles;

public:
    YoutubeChannel(string name, string ownerName)
    {
        Name = name;
        OwnerName = ownerName;
        SubscriberCount = 0;
    }

    void GetInfo()
    {
        cout << "Name: " << Name << endl;
        cout << "Owner Name: " << OwnerName << endl;
        cout << "Number of Subscribers: " << SubscriberCount << endl;
        cout << "Videos: " << endl;
        for (string videoTitle : PublishedVideoTitles)
        {
            cout << videoTitle << endl;
        }
    }

    void GetName()
    {
        cout << Name << endl;
    }

    void SetName(string name)
    {
        Name = name;
    }

    void Subscribe()
    {
        SubscriberCount++;
    }

    void Unsubscribe()
    {
        SubscriberCount ? SubscriberCount-- : SubscriberCount = 0;
    }

    void PublishVideo(string title)
    {
        PublishedVideoTitles.push_back(title);
    }
};

int main()
{
    YoutubeChannel channel1("CodeBeauty", "Saldina");

    channel1.PublishVideo("C++ for beginners");
    channel1.Unsubscribe();
    channel1.GetInfo();

    for (int i = 0; i < 20; i++)
    {
        channel1.Subscribe();
    }

    channel1.GetInfo();
}
