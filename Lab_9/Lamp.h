#pragma once
#include <iostream>

using namespace std;

namespace transporting
{
	class Lamp
	{
	private:
		int amount;

	public:
		Lamp() {}

		Lamp(int _amount);

		int GetAmount();

		~Lamp() {}
	};
}