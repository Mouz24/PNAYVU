#pragma once
#include <iostream>
#include "Lamp.h"

using namespace std;

namespace transporting
{
	class Light
	{
	private:
		string LightType;
		Lamp* lamp;

	public:
		Light() {}

		Light(Lamp* _lamp, string _LightType);

		string GetLightType();

		~Light() {}
	};
}