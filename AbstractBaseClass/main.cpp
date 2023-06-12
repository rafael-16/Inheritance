#include<iostream>

using namespace std;

class Vehicle
{
	int speed;
	const int MAX_SPEED;
public:
	Vehicle(int speed = 0, int max_speed = 250) : speed(speed), MAX_SPEED(max_speed) {}
	virtual void move() = 0;//			Pure-virtual function - чисто виртуальная функция
};

class GroundVehicle :public Vehicle {};

class Car :public GroundVehicle
{
public:
	void move()
	{
		cout << "Машина едет на четырех колесах." << endl;
	}
};

class Buldozer :public GroundVehicle
{
public:
	void move()
	{
		cout << "Бульдозер едет на двух гусеничных лентах." << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Car car;
	car.move();

	Buldozer amd;
	amd.move();
}