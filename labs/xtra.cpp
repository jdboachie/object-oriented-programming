#include <iostream>

class TV
{
public:
    int channel = 0;
    int volumeLevel = 50;
    bool on = false;

    void turnOn()
    {
        this->on = true;
    }

    void turnOff()
    {
        this->on = false;
    }

    void setChannel(int newChannel)
    {
        this->channel = newChannel;
    }

    void setVolume(int newVolumeLevel)
    {
        this->volumeLevel = newVolumeLevel;
    }

    void channelUp()
    {
        this->channel++;
    }

    void channelDown()
    {
        this->channel--;
    }

    void volumeUp()
    {
        this->volumeLevel++;
    }

    void volumeDown()
    {
        this->volumeLevel--;
    }
};
