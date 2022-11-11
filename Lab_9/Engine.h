#pragma once
#include <iostream>
#include "Oil.h"

using namespace std;

namespace transporting
{
	class Engine
	{
	private:
		int power;
		Oil* oil;

	public:
		Engine() {}

		Engine(Oil* _oil, int _power);

		int GetPower();

		Oil* GetOil();

		~Engine() {}
	};
}