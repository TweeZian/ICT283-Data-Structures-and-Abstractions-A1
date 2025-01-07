#include "Date.h"

void Test01(Date date);
void Test02();
void Test03(Date date);
void Test04(Date date);
void Test05(Date date);
void Test06(Date date);


int main()
{
    Date test;

    Test01(test);
    Test02();
    Test03(test);
    Test04(test);
    Test05(test);
    Test06(test);

    return 0;
}

void Test01(Date date)
{
    cout << "=== Testing Default Constructor ===" << endl;
    cout << date << endl;
}

void Test02()
{
    cout << "=== Testing Initializing Constructor with attributes ===" << endl;
    Date date("18 April 2019");
    cout << date << endl;
}

void Test03(Date date)
{
    cout << "=== Testing Set & GetDate() ===" << endl;
    date.SetDate("30 June 2016");
    cout << date.GetDate() << endl << endl;
}

void Test04(Date date)
{
    cout << "=== Testing Set & GetDay() ===" << endl;
    date.SetDay(13);
    cout << date.GetDay() << endl << endl;
}

void Test05(Date date)
{
    cout << "=== Testing Set & GetMonth() ===" << endl;
    date.SetMonth(6);
    cout << date.GetMonth() << endl << endl;
}

void Test06(Date date)
{
    cout << "=== Testing Set & GetYear() ===" << endl;
    date.SetYear(1993);
    cout << date.GetYear() << endl << endl;
}

