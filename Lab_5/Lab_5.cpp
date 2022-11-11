#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<class T>
class MAP
{
public:
     string Key;
     T Value;

    MAP()
    {

    }

    MAP(string key, T value)
    {
        Value = value;
        Key = key;
    }
};

template<class T>
T BinarySearch(string key, vector<class MAP<T>> arr, int count)
{
    int Min = 0;
    int Max = count - 1;
    int mid = (Min + Max) / 2;
    MAP<T> element = arr[mid];
    T value;
    for (MAP<T> el : arr)
    {
        if (!el.Key.compare(key))
        {
            value = el.Value;
        }
    }
    while (Min <= Max)
    {
        if (element.Value == value)
        {
            return mid + 1;
        }
        else if (element.Value < value)
        {
            Min = mid + 1;
            mid = Min;
            element = arr[mid];
        }
        else
        {
            Max = mid - 1;
            mid = Max;
            element = arr[mid];
        }
    }

}

int main()
{
    vector<MAP<int>> arr;

    int count;
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        string tempKey;
        cin >> tempKey;

        int value;
        cin >> value;

        MAP<int> temp(tempKey, value);
        arr.push_back(temp);
    }

    string key;
    cin >> key;

    cout << BinarySearch(key, arr, count);
    return 0;
}