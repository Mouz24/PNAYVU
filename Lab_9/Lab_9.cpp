#include <iostream>
#include "Car.h"
#include "Engine.h"
#include "Lamp.h"
#include "Light.h"
#include "Oil.h"
#include "TransportMean.h"
#include "Wheel.h"
#include <vector>

using namespace std;
using namespace transporting;

int main()
{
    vector<Car> cars;

    Car car;
    Engine engine;
    Oil oil;
    Lamp lamp;
    Light light;
    Wheel wheel;
    MeanofTransport mt;
    
    int sizeofwheel;
    int power;
    int volume;
    int amountoflamps;
    
    string lighttype;
    string type;
    string model;

    int CarAmount;
    
    cout << "Enter the number of cars: ";

    cin >> CarAmount;

    cout << endl;

    for (int i = 0; i < CarAmount; i++)
    {
        cout << "Enter car " << i + 1 << " type : ";
        cin >> type;
        cout << endl;

        cout << "Enter car " << i + 1 << " model: ";
        cin >> model;
        cout << endl;

        cout << "Enter engine horse power: ";
        cin >> power;
        cout << endl;

        cout << "Enter volume of oil in engine: ";
        cin >> volume;
        cout << endl;

        cout << "Enter size of wheels: ";
        cin >> sizeofwheel;
        cout << endl;

        cout << "Enter type of lights: ";
        cin >> lighttype;
        cout << endl;

        cout << "Enter amount of lamps in lights: ";
        cin >> amountoflamps;
        cout << endl;

        oil = Oil(volume);
        engine = Engine(&oil, power);
        lamp = Lamp(amountoflamps);
        light = Light(&lamp, lighttype);
        car = Car(model, type, &engine, &light, sizeofwheel);

        cars.push_back(car);
    }

    cout << endl;

    for (auto car : cars)
    {
        cout << "Type of car: " << car.GetName() << ' ';
        cout << "Model of car: " << car.GetModel() << ' ';
        cout << "Engine Horse Power: " << car.GetEngine()->GetPower() << ' ';
        cout << "Volume of oil: " << car.GetEngine()->GetOil()->GetVolume() << ' ';
        cout << "Type of lights: " << car.GetLight()->GetLightType() << ' ';
        cout << "Size of wheels: " << car.GetWheel()->GetSizeOfWheel() << endl;;
        
        cout << endl;
    }
}
