#include <iostream>
#include <conio.h> // For _getch() function

class TollBooth
{
private:
    unsigned int totalCars;
    double totalCash;

public:
    TollBooth() : totalCars(0), totalCash(0.0){};

    void payingCar()
    {
        totalCars++;
        totalCash += 0.5;
    }

    void nopayCar()
    {
        totalCars++;
    }

    void display() const
    {
        std::cout << "\nTotal cars: " << totalCars << std::endl;
        std::cout << "Total cash: " << totalCash << "pesewas" << std::endl;
    }
};

int main()
{
    TollBooth booth;

    char key;
    bool exit = false;

    std::cout << "Press 'p' for paying car, 'n' for non-paying car, 'Esc' to quit" << std::endl;

    while (!exit)
    {
        key = _getch();

        switch (key)
        {
        case 'p':
            std::cout << "/";
            booth.payingCar();
            break;

        case 'n':
            std::cout << "\\";
            booth.nopayCar();
            break;

        case 27: // ASCII code for Esc key
            exit = true;
            break;
        default:
            std::cout << "\nInvalid key. Press 'p' for paying car, 'n' for non-paying car, 'Esc' to quit" << std::endl;
        }

        if (exit)
        {
            booth.display();
        }
    }
    return 0;
}
