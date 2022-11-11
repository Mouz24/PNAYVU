#include "Wheel.h"
#include <iostream>

using namespace std;
using namespace transporting;

Wheel::Wheel(int _rad)
{
	Rad = _rad;
}

int Wheel::GetSizeOfWheel()
{
	return Rad;
}