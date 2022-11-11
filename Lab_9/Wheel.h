#pragma once
#include <iostream>

using namespace std;

namespace transporting
{
	class Wheel
	{
	private:
		int Rad;

	public:
		Wheel() {}

		Wheel(int _rad);

		int GetSizeOfWheel();

		~Wheel() {}
	};
}