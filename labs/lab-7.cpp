#include <iostream>

class CPolygon
{
protected:
	int width, height;

public:
	void setValues(int a, int b)
	{
		this->width = a;
		this->height = b;
	}
};

class CRectangle : public CPolygon
{
public:
	int area()
	{
		return (this->width * this->height);
	}
};

class CTriangle : public CPolygon
{
public:
	int area()
	{
		return (this->width * this->height / 2);
	}
};

int main()
{
	CRectangle rect;
	CTriangle trgl;
	rect.setValues(10, 5);
	trgl.setValues(10, 5);
	std::cout << rect.area() << std::endl;
	std::cout << trgl.area() << std::endl;
}
