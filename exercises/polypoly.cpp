#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Polygon
{
public:
    virtual double calculateArea() const = 0;
    virtual string getName() const = 0;

    friend bool operator<(const Polygon &poly1, const Polygon &poly2)
    {
        return poly1.calculateArea() < poly2.calculateArea();
    }

    friend bool operator>(const Polygon &poly1, const Polygon &poly2)
    {
        return poly1.calculateArea() > poly2.calculateArea();
    }
};

class Rectangle : public Polygon
{

public:
    double width;
    double height;

    Rectangle(double w, double h) : width(w), height(h) {}
    double calculateArea() const override { return width * height; }
    string getName() const override { return "Rectangle"; };
};

class Triangle : public Polygon
{
public:
    double base;
    double height;

    Triangle(double b, double h) : base(b), height(h) {}
    double calculateArea() const override { return 0.5 * base * height; }
    string getName() const override { return "Triangle"; };
};

int main()
{
    char choice;
    char op;
    double dim1, dim2;
    Polygon *polygons[2];

start:
    for (int i = 0; i < 2; i++)
    {
        cout << "Choose a polygon: (r: Rectangle / t: Triangle) ";
        cin >> choice;

        switch (tolower(choice))
        {
        case 'r':
            cout << "Enter the width and height of rectangle: ";
            cin >> dim1 >> dim2;

            polygons[i] = new Rectangle(dim1, dim2);
            break;

        case 't':
            cout << "Enter the base and height of triangle: ";
            cin >> dim1 >> dim2;

            polygons[i] = new Triangle(dim1, dim2);
            break;

        default:
            cout << "Invalid option." << endl;
            goto start;
        }
    }

opchoice:
    cout << "Select an operator: ( >: less than / <: greater than ) (No support for = yet) ";
    cin >> op;

    switch (op)
    {
    case '<':
        if (polygons[0] < polygons[1])
        {
            cout << "True. " << polygons[0]->getName() << " has less area than " << polygons[1]->getName() << endl;
        }
        else
        {
            cout << "False. " << polygons[0]->getName() << " has greater area than " << polygons[1]->getName() << endl;
        }
        break;

    case '>':
        if (polygons[0] > polygons[1])
        {
            cout << "True. " << polygons[0]->getName() << " has greater area than " << polygons[1]->getName() << endl;
        }
        else
        {
            cout << "False. " << polygons[0]->getName() << " has lesser area than " << polygons[1]->getName() << endl;
        }
        break;

    default:
        cout << "Invalid operator. ";
        goto opchoice;
    }

restart:
    cout << "Would you like to try again?: ( y/n ) ";
    cin >> choice;

    switch (tolower(choice))
    {
    case 'y':
        cout << "Restarting...";
        system("cls");
        goto start;
        break;

    case 'n':
        system("cls");
        cout << "Thanks for running my code!";
        break;

    default:
        cout << "Invalid choice.";
        goto restart;
    }

    return 0;
}