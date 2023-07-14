#include <iostream>

class CPolygon {
protected:
	int width, height;

public:
	void set_values(int a, int b) {
		width = a;
		height = b;
	}

	virtual int area() = 0;
};

class CRectangle : public CPolygon {
public:
	int area() {
		return (width * height);
	}
};

class CTriangle : public CPolygon {
public:
	int area() {
		return (width * height / 2);
	}
};


int main()
{
	CRectangle rect;
	CTriangle trgl;
	CPolygon* ppoly1 = &rect;
	CPolygon* ppoly2 = &trgl;
	CPolygon* ppoly3 = &trgl;
	ppoly1->set_values(4, 5);
	ppoly2->set_values(4, 4);
	ppoly3->set_values(6, 7);
	std::cout << ppoly1->area() << '\n';
	std::cout << ppoly2->area() << '\n';
	std::cout << ppoly3->area() << '\n';
	return 0;
}