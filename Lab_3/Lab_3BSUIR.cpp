#include <iostream>

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
		cout << "Base" << endl;
	}


	~Product() {}

	virtual void PrintData()
	{
		std::cout << type << endl;
	}
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
		cout << "Laptop" << endl;
	}

	void PrintData() override
	{
		cout<< type  << endl;
		cout << year << endl;
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
		cout << "TV" << endl;
	}

	void PrintData() override
	{
		cout << type << endl;
		cout << width << endl;
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
		cout << "IFlip" << endl;
	}

	void PrintData() override
	{
		std::cout << type << std::endl;
		std::cout << year << std::endl;
		std::cout << autonomy << std::endl;
	}

	~IFlip()
	{

	}
};

class Oled : public TV
{
protected:
	int resolution;

public:
	Oled(int _resolution, int _width, string _type) : TV(_width, _type)
	{
		resolution = _resolution;
		cout << "Oled" << endl;
	}

	void PrintData() override
	{
		std::cout << type << std::endl;
		std::cout << width << std::endl;
		std::cout << resolution << std::endl;
	}

	~Oled()
	{

	}
};


class SuperTablet : public IFlip, public Oled
{
private:
	double weight;

public:
	SuperTablet(int _autonomy, int _year, string _type, int _resolution, int _width, double _weight = 0.35) : IFlip(_autonomy, _year, _type),
		                                                                                                      Oled(_resolution,_width, _type)
	{
		weight = _weight;
		cout << "Super" << endl;
	}

	void PrintData() override
	{
		cout << type << endl;
		cout << year<< endl;
		cout << autonomy << endl;
		cout << width << endl;
		cout << resolution << endl;
		cout << weight << endl;
	}

	~SuperTablet()
	{

	}
};


int main()
{
	SuperTablet st(10, 2024, "portable", 4000, 10);
	st.PrintData();

	return 0;
}