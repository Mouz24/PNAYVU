#include "Light.h"
#include <iostream>

using namespace std;
using namespace transporting;

Light::Light(Lamp* _lamp, string _LightType)
{
	lamp = _lamp;
	LightType = _LightType;
}

string Light::GetLightType()
{
	return LightType;
}