#include <iostream>

class Quadrilateral
{
private:
    int x;
    int y;

public:
    void setValues(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    int getArea()
    {
        return x * y;
    }
};

int main()
{
    Quadrilateral square;
    Quadrilateral rectangle;

    square.setValues(10, 10);
    rectangle.setValues(5, 10);

    std::cout << "Square area: " << square.getArea() << std::endl;
    std::cout << "Rectangle area: " << rectangle.getArea() << std::endl;
}