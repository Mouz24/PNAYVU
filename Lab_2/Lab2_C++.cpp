#include <iostream>
using namespace std;

class Array
{
public:
    int sizeforint;
    int* converted;
    Array() {
       sizeofarray = 4;
       data = new int[sizeofarray];
       for (int i = 0; i < sizeofarray; i++)
       {
           data[i] = 0;
       }
    }

    Array(int size)
    {
        sizeofarray = size;
        data = new int[sizeofarray];
        for (int i = 0; i < sizeofarray; i++)
        {
            data[i] = 0;
        }
    }

    Array(Array& ArrayToCopy)
    {
        sizeofarray = ArrayToCopy.sizeofarray;
        data = new int[sizeofarray];
        for (int i = 0; i < sizeofarray; i++)
        {
            data[i] = ArrayToCopy.data[i];
        }
    }
    
    /*~Array()
    {
        delete[] data;
    }*/


    void showData()         //вывод данных массива на экран
    {
        for (int i = 0; i < sizeofarray; i++)
        {
            cout << data[i] << " | ";
        }
    }

    static void ToInt2(Array& arr1)
    {
        arr1.sizeforint = arr1.sizeofarray;
        arr1.converted = arr1.ToInt(arr1);
    }

    static int* ToInt(Array& arr1)
    {
         arr1.sizeforint = arr1.sizeofarray;
        int* result = new int[arr1.sizeforint];
        for (int i = 0; i < arr1.sizeforint; i++)
        {
            result[i] = arr1.data[i];
        }

        return  result;
    }

    operator int* ()
    {
        return converted;
    }

    int& operator[] (int j)
    {
        return data[j];
    }

    Array& operator= (Array& other)
    {
        for (int i = 0; i < other.sizeofarray; i++)
        {
            data[i] = other.data[i];
        }

        return *this;
    }

    Array& operator+ (Array& arr)
    {
        if (sizeofarray != arr.sizeofarray)
        {
            cout << "Different sizes";
            exit(-1);
        }
        Array res(arr.sizeofarray);
        for (int i = 0; i < arr.sizeofarray; i++)
        {
            res.data[i] = data[i] + arr.data[i];
        }

        return res;
    }

    friend ostream& operator<< (ostream& out, Array& p);
    friend Array& operator- (Array& arr1, int* arr2);
    //friend Array& operator+ (Array& arr1, Array& arr2);
    friend Array operator++ (Array& i, int);
    friend Array& operator++ (Array& i);
    friend Array operator-- (Array& i, int);
    friend Array& operator-- (Array& i);
    friend bool operator== (Array& arr1, Array& arr2);
    friend bool operator> (Array& arr1, int*);
private:
    
    int* data;
    int sizeofarray;
};

ostream& operator<< (ostream& out, Array& p)
{
    for (int i = 0; i < p.sizeofarray; i++)
    {
         out << p.data[i] << " | ";
    }

    return out;
}

bool operator> (Array& arr1, int* arr2)
{
    for (int i = 0; i < arr1.sizeofarray; i++)
    {
        if (arr1.data[i] < arr2[i])
        {
            return false;
        }
    }
    
    return true;
}

bool operator== (Array& arr1, Array& arr2)
{
    for (int i = 0; i < arr1.sizeofarray; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return false;
        }
    }

    return true;
}
//Array& operator+ (Array& arr1, Array& arr2)
//{
//    if (arr1.sizeofarray != arr2.sizeofarray)
//    {
//        cout << "Different sizes";
//        exit(-1);
//    }
//    for (int i = 0; i < arr1.sizeofarray && i < arr2.sizeofarray; i++)
//    {
//        arr1.data[i] = arr1.data[i] + arr2.data[i];
//    }
//
//    return arr1;
//}


Array& operator- (Array& arr1, int* arr2)
{
    Array& res = arr1;
    for (int i = 0; i < arr1.sizeofarray; i++)
    {
        arr1.data[i] = arr1.data[i] - arr2[i];
    }

    return res;

}

Array operator-- (Array& h, int)
{
    Array oldValue = h;
    for (int i = 0; i < h.sizeofarray; i++)
    {
        h[i] = h[i] - 1;
    }

    return oldValue;
}

Array& operator-- (Array& h)
{
    for (int i = 0; i < h.sizeofarray; i++)
    {
        h[i] = h[i] - 1;
    }

    return h;
}

Array operator++ (Array& h, int)
{
    Array oldValue = h;
    for (int i = 0; i < h.sizeofarray; i++)
    {
        h[i] = h[i] + 1;
    }

    return oldValue;
}

Array& operator++ (Array& h)
{
    for (int i = 0; i < h.sizeofarray; i++)
    {
        h.data[i] = h.data[i] + 1;
    }

    return h;
}

int Max(int* arr, int size)
{
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
       }
    } 

    return max;
}

int Min(int* arr, int size)
{
    int min = 1000;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    return min;
}

int Avg(int* arr, int size)
{
    int avg = 0;
    int temp = 0;
    for (int i = 0; i < size; i++)
    {
        temp += arr[i];
    }

    avg = temp / size;
    return avg;
}

int Count(int* arr, int size)
{
    return size;
}

int main()
{
    Array arr1(4);
    Array arr2(4);
    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;
    arr1[3] = 6;
    cout << "Arr1: ", arr1.showData();
    cout << endl;
    cout << endl;
    arr2[0] = 3;
    arr2[1] = 5;
    arr2[2] = 6;
    arr2[3] = 2;
   cout << "Arr2: " << arr2;
    cout << endl << endl;
    //Array temp2(arr1);
    Array plus = arr1 + arr2;
    cout << "(arr1 + arr2): " << plus << endl;
    cout << endl;
   // arr1 = temp2;
    ++arr1;
   cout << "++Arr1: " << arr1 << endl;
   --arr2;
   cout << endl;
   cout << "--Arr2: " << arr2;
    cout << endl;
    cout << endl;
    Array arr3 = arr2;
    int* arraytodeduct = new int[4] {2, 5, 4, 3};
    Array temp3(arr2);
    Array minus = arr2 - arraytodeduct;
    cout << "(Array arr2 - arraytodeduct): " << minus;
    arr2 = temp3;
    cout << endl;
    cout << endl;
    if (arr3 == arr2)
    {
        cout << "arr3 == arr2 - True";
    }
    else
    {
        cout << "arr3 == arr2 - False";
    }
    cout << endl;
    cout << endl;
    int* arraytocompare = new int[4] {0, 1, 0, 0};
    if (arr1 > arraytocompare)
    {
        cout << "arr1 > arr2 - True";
    }
    else
    {
        cout << "arr1 > arr2 - False";
    }
    cout << endl;
    Array::ToInt2(arr1);
    int* temp = arr1;
    int tempsize = arr1.sizeforint;
    cout << endl;
    cout << "Max of Converted To Int array: " << Max(temp, tempsize) << endl;
    cout << "Min of Converted To Int array: " << Min(temp, tempsize) << endl;
    cout << "Average of Converted To Int array: " << Avg(temp, tempsize) << endl;
    cout << "Count Converted To Int elements: " << Count(temp, tempsize) << endl;
    cout << endl;

    return 0;
}