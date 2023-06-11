#include <iostream>
using namespace std;

class Shape
{
public:
	virtual double get_are()const = 0;
	virtual double get_perimetr()const = 0;
	virtual void draw()const = 0;
};
class Sguare : public Shape
{
	double side;
public:
	Sguare(double side)
	{
		this->side = side;
	}
	~Sguare() {}
};

void main()
{
	setlocale(LC_ALL, "");


}

