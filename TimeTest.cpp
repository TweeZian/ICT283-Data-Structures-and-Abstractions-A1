#include "Time.h"

void Test01(Time time);
void Test02();
void Test03(Time time);

int main()
{
    Time test;

    Test01(test);
    Test02();
    Test03(test);

    return 0;
}

void Test01(Time time)
{
    cout << "=== Testing Default Constructor ===" << endl;
    cout << time << endl << endl;
}

void Test02()
{
    cout << "=== Testing Initializing Constructor with attributes ===" << endl;
    Time time("15:00");
    cout << time << endl;
}

void Test03(Time time)
{
    cout << "=== Testing Set & GetDate() ===" << endl;
    time.SetTime("9:00");
    cout << time.GetTime() << endl << endl;
}
