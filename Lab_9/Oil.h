#pragma once
#include <iostream>

using namespace std;

namespace transporting
{
	class Oil
	{
	private:
		int volume;

	public:
		Oil() {}

		Oil(int _volume);

		int GetVolume();

		~Oil() {}
	};
}