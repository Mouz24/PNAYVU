#include <iostream>

using namespace std;

class Product
{
protected:
    string type;
    const type_info& ti = typeid(Product);

public:
    Product(string _type)
    {
        type = _type;
    }

    virtual void GetObject()
    {
        cout << "Object: " << ti.name() << endl;
        cout << "Type: " << type << endl;
    }

    virtual string GetType()
    {
        return ti.name();
    }

    virtual ~Product() {}
};

class Product1 : public Product
{
protected:
    string name;
    int quantity;
    const type_info& ti = typeid(Product1);

public:
    Product1(string _type, string _name, int _quantity) : Product(_type)
    {
        name = _name;
        quantity = _quantity;
    }

    void GetObject() override
    {
        cout << "Object: " << ti.name() << endl;
        cout << "Type: " << Product::type << endl;
        cout << "Name: " << name << endl;
        cout << "Quantity: " << quantity << endl;
    }

    void Product1Unique()
    {
        cout << "You are in Product1" << endl;
    }

    string GetType() override
    {
        return ti.name();
    }

    ~Product1() {}
};

class Product2 : public Product
{
protected:
    string type;
    string name;
    string demand;
    const type_info& ti = typeid(Product2);

public:
    Product2(string _type, string _name, string _demand) : Product(_type)
    {
        name = _name;
        demand = _demand;
    }

    void GetObject() override
    {
        cout << "Object: " << ti.name() << endl;
        cout << "Type: " << Product::type << endl;
        cout << "Name: " << name << endl;
        cout << "Demand: " << demand << endl;
    }

    void Product2Unique()
    {
        cout << "You are in Product2" << endl;
    }

    string GetType() override
    {
        return ti.name();
    }

    ~Product2() {}
};

class Product3 : public Product
{
protected:
    string type;
    string name;
    double price;
    const type_info& ti = typeid(Product3);

public:
    Product3(string _type, string _name, double _price) : Product(_type)
    {
        name = _name;
        price = _price;
    }

    void GetObject() override
    {
        cout << "Object: " << ti.name() << endl;
        cout << "Type: " << Product::type << endl;
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
    }

    void Product3Unique()
    {
        cout << "You are in Product3" << endl;
    }

    string GetType() override
    {
        return ti.name();
    }

    ~Product3() {}
};

int main()
{
    Product** arr = new Product * [4];
    arr[0] = new Product("Food");
    arr[1] = new Product1("Food", "Sausage", 4);
    arr[2] = new Product2("Laptop", "HP", "High");
    arr[3] = new Product3("Car", "Tesla", 70.500);

    for (int i = 0; i < 4; i++)
    {
        if (arr[i]->GetType() == typeid(Product1).name())
        {
            Product1* pr1 = dynamic_cast <Product1*> (arr[i]);
            
            pr1->Product1Unique();
            pr1->GetObject();
        }
        else if (arr[i]->GetType() == typeid(Product2).name())
        {
            Product2* pr2 = dynamic_cast <Product2*> (arr[i]);

            pr2->Product2Unique();
            pr2->GetObject();
        }
        else if (arr[i]->GetType() == typeid(Product3).name())
        {
            Product3* pr3 = dynamic_cast <Product3*> (arr[i]);

            pr3->Product3Unique();
            pr3->GetObject();
        }
        else
        {
            arr[i]->GetObject();
        }

        cout << endl;
    }
}
