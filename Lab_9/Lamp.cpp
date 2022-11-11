#include "Lamp.h"
#include <iostream>

using namespace std;
using namespace transporting;

Lamp::Lamp(int _amount)
{
	amount = _amount;
}

int Lamp::GetAmount()
{
	return amount;
}
