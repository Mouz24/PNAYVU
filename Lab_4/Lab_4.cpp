#include <iostream>
#include <iomanip>

using namespace std;

class Product
{
protected:
	string type;

public:
	Product()
	{

	}

	Product(string _type)
	{
		type = _type;
	}


	virtual ~Product() {}

	virtual void PrintData() = 0;
	virtual void GetPrice() = 0;
};

class Laptop : public virtual Product
{
protected:
	int year;

public:

	Laptop()
	{

	}

	Laptop(int _year, string _type)
	{
		type = _type;
		year = _year;
	}

	void PrintData() override
	{
		cout << type << endl;
		cout << year << endl;
	}

	void GetPrice() override
	{
		cout << setprecision(6) << (year / 23. * 1.2) << endl;
	}

	~Laptop() {}
};

class TV : public virtual Product {
protected:
	int width;

public:
	TV(int _width, string _type)
	{
		type = _type;
		width = _width;
	}

	void PrintData() override
	{
		cout << type << endl;
		cout << width << endl;
	}

	void GetPrice() override
	{
		cout << setprecision(4) << (width / 23. * 1.2) << endl;
	}

	~TV() {}
};

class IFlip : public Laptop
{
protected:
	int autonomy;
public:
	IFlip(int _autonomy, int _year, string _type) : Laptop(_year, _type)
	{
		autonomy = _autonomy;
	}

	void PrintData() override
	{
		std::cout << type << std::endl;
		std::cout << year << std::endl;
		std::cout << autonomy << std::endl;
	}

	void GetPrice() override
	{
		cout << setprecision(6) << (double)(autonomy / 23. * 1.2) << endl;
	}

	~IFlip()
	{

	}
};

int main()
{
	Product** array = new Product * [3];
	array[0] = new Laptop(2021, "Portable");
		array[1] = new TV(123, "Mini");
		array[2] = new IFlip(4500, 2025, "Max");

	for (int i = 0; i < 3; i++)
	{
		cout << "Data : "; array[i]->PrintData();
		cout << endl;
		cout << "Price : "; array[i]->GetPrice();
		cout << endl;
	}
	return 0;
}