#include <iostream>

#pragma warning disable

using namespace std;

class Task
{
public:
	Task() { per = 0.0; }
	Task(int x, string n)
	{
		id = x;
		name = n;
		per = 0.0;
	}
	~Task() {}
	friend class Checker;
	friend void Vyvod(Task&);
private:
	int id;
	string name;
	double per;
};

class Checker
{
public:
	static void Set(Task &perc, double p)
	{
		perc.per = p;
	}
	static void Get(Task& perc)
	{
		cout << "Enter ID: ";
		cin >> perc.id;
		cout << endl;
		cout << "Enter Name: ";
		cin >> perc.name;
		cout << endl;
	}
};
void Vyvod(Task& a)
{
	cout << "ID: " << a.id<<" ";
	cout << "Name: " << a.name<<" ";
	cout << "Percentage: " << a.per;
	cout << endl;
}

int main()
{
	Task obj1(1, "Paul");
	Vyvod(obj1);
	Checker::Set(obj1, 20.0);
	Vyvod(obj1);
	Task obj2(2, "Rick");
	Vyvod(obj2);
	Checker::Set(obj2, 30.0);
	Vyvod(obj2);
	Task obj3(3, "Jake");
	Vyvod(obj3);
	Checker::Set(obj3, 25.0);
	Vyvod(obj3);
	cout << endl;
	Task* arr = new Task[4];
	cout << "Enter elements" << endl;
	for (int i = 0; i < 4; i++)
	{
		Checker::Get(arr[i]);
	}
	cout << "Elements before:" << endl;
	for (int i = 0; i < 4; i++)
	{
		Vyvod(arr[i]);
	}
	double k = 0;
	for (int i = 0; i < 4; i++)
	{
		cout << "Set the percentage for "<< i + 1<<": ";
		cin >> k;
		Checker::Set(arr[i], k);
	}
	cout << "Elements after:" << endl;
	for (int i = 0; i < 4; i++)
	{
		Vyvod(arr[i]);
	}

	delete[] arr;
}