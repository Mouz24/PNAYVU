#include "Car.h"
#include "Oil.h"
#include "Engine.h"
#include <iostream>

using namespace std;
using namespace transporting;

Engine::Engine(Oil* _oil, int _power)
{
	oil = _oil;
	power = _power;
}

int Engine::GetPower()
{
	return power;
}

Oil* Engine::GetOil()
{
	return oil;
}
