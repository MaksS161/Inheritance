#include<iostream>
using namespace std;

class Vehicle
{
	int speed;
	const int MAX_SPEED;
public:
	Vehicle(int speed = 0, int max_speed = 250) :speed(speed), MAX_SPEED(max_speed) {}
	virtual void move() = 0; //Pure-virtual function - Чисто виртуальная функция
};

class GroundVehicle:public Vehicle{};//Pure-virtual function для классификации (иерархии)

class Car:public GroundVehicle
{
public:
	void move()
	{
		cout << "Машина eздит на колесах" << endl;
	}
};
class Buldozer :public GroundVehicle
{
public:
	void move()
	{
		cout << "Бульдозер ездит на гусеницах" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");

	//Vehicle transport;//Can not instantiate Abstract class
						// Не можем создать экземпляр абстрактного класса
	//GroundVehicle gv;
	Car car;
	car.move();

	Buldozer amd;
	amd.move();

}