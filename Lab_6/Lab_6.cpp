#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
bool Contains(vector<int> data, int a)
{
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] == a)
        {
            return true;
        }
    }

    return false;
}

class ExceptionHandler : public std::logic_error
{
public:
    explicit ExceptionHandler(string message) : std::logic_error(message) {}
};

class EmptySetException : public ExceptionHandler
{
public:
    explicit EmptySetException() : ExceptionHandler("Set is empty") {}
};

class NoElement : public ExceptionHandler
{
public:
    explicit NoElement() : ExceptionHandler("No Such Element") {}
};

class Set
{
protected:
    vector<int> data;
public:
    void Insert(int i)
    {
        if (!Contains(data, i))
        {
            data.push_back(i);
        }
    }

    void Clear()
    {
        if (data.empty())
        {
            throw EmptySetException();
        }

        data.clear();
    }

    void Erase(int a)
    {
        if (!Contains(data, a))
        {
            throw NoElement();
        }

        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] == a)
            {
                int pos = i;
                data.erase(data.begin() + pos);
            }
        }
    }
};

void my_terminate()
{
    cout << "There is no handler for this exception" << endl;
}

int main()
{
    set_terminate(my_terminate);
    Set set;
    try
    {
        set.Insert(2);
        set.Insert(4);
        set.Insert(3);
       // set.Erase(6);
        set.Clear();
        set.Clear();
    }
    catch (ExceptionHandler ex)
    {
        cout << ex.what();
       if (strcmp(ex.what(), "Set is empty") && strcmp(ex.what(), "No Such Element"))
        {
            my_terminate();
        }
    }
        
}
