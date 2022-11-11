#include "Car.h"
#include <iostream>

using namespace std;
using namespace transporting;

Car::Car(string _model, string _type, Engine* _engine, Light* _light, int _SizeOfWheel) : MeanofTransport(_type)
{
	model = _model;
	engine = _engine;
	light = _light;
	wheel = new Wheel(_SizeOfWheel);
}

string Car::GetModel()
{
	return model;
}

Engine* Car::GetEngine()
{
	return engine;
}

Light* Car::GetLight()
{
	return light;
}

Wheel* Car::GetWheel()
{
	return wheel;
}
