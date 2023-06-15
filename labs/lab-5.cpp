#include <iostream>
#include <list>

class YoutubeChannel
{

private:
    int SubscriberCount;
    std::string Name;
    std::string OwnerName;
    std::list<std::string> PublishedVideoTitles;

public:
    YoutubeChannel(std::string name, std::string ownerName)
    {
        Name = name;
        OwnerName = ownerName;
        SubscriberCount = 0;
    }

    void GetInfo()
    {
        std::cout << "Name: " << Name << std::endl;
        std::cout << "Owner Name: " << OwnerName << std::endl;
        std::cout << "Number of Subscribers: " << SubscriberCount << std::endl;
        std::cout << "Videos: " << std::endl;
        for (std::string videoTitle : PublishedVideoTitles)
        {
            std::cout << videoTitle << std::endl;
        }
    }

    void GetName()
    {
        std::cout << Name << std::endl;
    }

    void SetName(std::string name)
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

    void PublishVideo(std::string title)
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
