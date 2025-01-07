#include <iostream>
#include <string>
#include "Vector.h"

using namespace std;
typedef Vector<int> IntVec;

void Display(IntVec &Varray);
void Test01(IntVec &Varray);
void Test02(IntVec &Varray);
void Test03(IntVec &Varray);
void Test04(IntVec &Varray);
void Test05(IntVec &Varray);
void Test06(IntVec &Varray, int index);
void Test07(IntVec &Varray,int element, int index);
void Test08(IntVec &Varray);
void Test09(IntVec &Varray,int element, int index);

int main()
{
    IntVec n1;

    Test01(n1);
    Test02(n1);
    Test03(n1);
    Test04(n1);
    Test05(n1);
    Test06(n1,2);
    Test07(n1,99,2);
    Test08(n1);
    Test09(n1,99,0);

    return 0;
}

void Display(IntVec &Varray)
{
    cout << "No of Elements: " << Varray.Size() << endl;
    cout << "Capacity: " << Varray.GetCapacity() << endl;
    for(int i = 0; i < Varray.Size(); i++)
    {
        cout << "Element at [" << i << "] : " << Varray.At(i) << endl;
    }
    cout << endl;
}

void Test01(IntVec &Varray)
{
    cout << "=== Testing Default Constructor ===" << endl;
    cout << "Address: " << Varray.GetArray() << endl;
    Display(Varray);

}

void Test02(IntVec &Varray)
{
    cout << "=== Testing Add() ===" << endl;
    Varray.Add(10);
    Varray.Add(20);
    Varray.Add(30);
    Varray.Add(40);
    Varray.Add(50);
    Varray.Add(60);
    Display(Varray);

}

void Test03(IntVec &Varray)
{
    IntVec test(Varray);

    cout << "=== Testing Deep Copy Constructor ===" << endl;
    cout << "Address of array to be copied: " << Varray.GetArray() << endl;
    cout << "Address of array copied:       " << test.GetArray() << endl;
    Display(test);
}

void Test04(IntVec &Varray)
{
    cout << "=== Testing = Operator Deep Copy ===" << endl;

    IntVec test;
    test = Varray;

    cout << "Address of array to be copied: " << Varray.GetArray() << endl;
    cout << "Address of array copied:       " << test.GetArray() << endl;
    Display(test);

}

void Test05(IntVec &Varray)
{
    cout << "=== Testing Remove() ===" << endl;
    if(Varray.Remove())
    {
        cout << "Remove() is Successful" << endl;
        Display(Varray);
    }
    else
    {
        cout << "Remove() is NOT Successful" << endl << endl;
    }

}

void Test06(IntVec &Varray, int index)
{
    cout << "=== Testing DeleteFrom() ===" << endl;
    if(Varray.DeleteFrom(index))
    {
        cout << "DeleteFrom() is Successful" << endl;
        Display(Varray);
    }
    else
    {
        cout << "DeleteFrom() is NOT Successful" << endl << endl;
    }

}

void Test07(IntVec &Varray,int element, int index)
{
    cout << "=== Testing InsertAt() ===" << endl;
    if(Varray.InsertAt(element,index))
    {
        cout << "InsertAt() is Successful" << endl;
        Display(Varray);
    }
    else
    {
        cout << "InsertAt() is NOT Successful" << endl << endl;
    }

}

void Test08(IntVec &Varray)
{
    cout << "=== Testing Empty() ===" << endl;
    Display(Varray);
    if(Varray.Empty())
    {
        cout << "Array is Empty" << endl << endl;
    }
    else
    {
        cout << "Array is NOT Empty" << endl << endl;
    }
}

void Test09(IntVec &Varray,int element, int index)
{
    cout << "=== Testing ModifyAt() ===" << endl;
    if(Varray.ModifyAt(element,index))
    {
        cout << "ModifyAt() is Successful" << endl;
        Display(Varray);
    }
    else
    {
        cout << "ModifyAt() is NOT Successful" << endl << endl;
    }

}
