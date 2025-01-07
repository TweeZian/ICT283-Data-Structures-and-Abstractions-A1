#include "WindData.h"
#include <iostream>

void Test01(WindData test);
void Test02();
void Test03(WindData test);
void Test04(WindData test);
void Test05(WindData test);
void Test06(WindData test);
void Test07(WindData test);
void Test08(WindData test);

int main()
{
    WindData test;

    Test01(test);
    Test02();
    Test03(test);
    Test04(test);
    Test05(test);
    Test06(test);
    Test07(test);
    Test08(test);

    return 0;
}

void Test01(WindData test)
{
    cout << "=== Testing Default Constructor ===" << endl;
    cout << test << endl;
}

void Test02()
{
    cout << "=== Testing Initialized Constructor ===" << endl;
    Date d("24 June 1993");
    Time t("8:34");
    WindData temp(d,t,12.34,45.67,65);
    cout << temp << endl;
}

void Test03(WindData test)
{
    cout << "=== Testing Set & Get Date ===" << endl;
    Date d("13 April 2003");
    test.SetDate(d);
    Date anotherD;
    test.GetDate(anotherD);
    cout << anotherD << endl;
}

void Test04(WindData test)
{
    cout << "=== Testing Set & Get Time ===" << endl;
    Time t("12:45");
    test.SetTime(t);
    Time anotherT;
    test.GetTime(anotherT);
    cout << anotherT << endl;
}

void Test05(WindData test)
{
    cout << "=== Testing Set & Get Speed ===" << endl;
    test.SetSpeed(45.45);
    cout << test.GetSpeed() << endl << endl;
}

void Test06(WindData test)
{
    cout << "=== Testing Set & Get AirTemp ===" << endl;
    test.SetAirTemp(95.51);
    cout << test.GetAirTemp() << endl << endl;
}

void Test07(WindData test)
{
    cout << "=== Testing Set & Get SolarRad ===" << endl;
    test.SetSolarRad(510);
    cout << test.GetSolarRad() << endl << endl;
}

void Test08(WindData test)
{
    cout << "=== Testing SolarRad Minimum Condition (<=100) ===" << endl;
    test.SetSolarRad(50);
    cout << test.GetSolarRad() << endl << endl;
}
