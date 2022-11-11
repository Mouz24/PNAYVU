#pragma once
#include <iostream>
#include "TransportMean.h"
#include "Engine.h"
#include "Wheel.h"
#include "Light.h"

using namespace std;

namespace transporting
{
	class Car : public MeanofTransport
	{
	private:
		string model;
		Engine* engine; 
		Light* light;
		Wheel* wheel;
		int SizeOfWheel;

	public:
		Car() {}

		Car(string _model, string type, Engine* engine, Light* light, int _SizeOfWheel);

		string GetModel();

		Engine* GetEngine();

		Light* GetLight();

		Wheel* GetWheel();

		~Car() {}
	};
}