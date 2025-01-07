#include "WindDataArray.h"

void Test01(WindDataArray &test);
void Test02(WindDataArray &test);
void Test03(WindDataArray &test);
void Test04(WindDataArray &test);
void Test05(WindDataArray &test);
void Test06(WindDataArray &test);

int main()
{
    WindDataArray test;


    Test01(test);
    Test02(test);
    Test03(test);
    Test04(test);
    Test05(test);
    Test06(test);

    return 0;
}

void Test01(WindDataArray &test)
{
    cout << "=== Testing ReadInputFileToStorage() ===" << endl;
    test.ReadInputFileToStorage("data/testsample_data.csv");
    for(int i = 0; i < test.Size(); i++)
    {
        WindData wd;
        test.Get(wd,i);
        cout << wd << endl;
    }
    cout << endl;
}

void Test02(WindDataArray &test)
{
    cout << "=== Testing CalculateWindSpeedMean() ===" << endl;
    float mean = test.CalculateWindSpeedMean(3,2014);
    cout << "Speed Mean: " << mean << endl << endl;

}

void Test03(WindDataArray &test)
{
    cout << "=== Testing CalculateWindSpeedSD() ===" << endl;
    float sd = test.CalculateWindSpeedSD(3,2014);
    cout << "Speed SD: " << sd << endl << endl;
}

void Test04(WindDataArray &test)
{
    cout << "=== Testing CalculateAirTempMean() ===" << endl;
    float mean = test.CalculateAirTempMean(3,2014);
    cout << "Air Temp Mean: " << mean << endl << endl;

}

void Test05(WindDataArray &test)
{
    cout << "=== Testing CalculateAirTempSD() ===" << endl;
    float sd = test.CalculateAirTempSD(3,2014);
    cout << "Air Temp SD: " << sd << endl << endl;
}

void Test06(WindDataArray &test)
{
    cout << "=== Testing CalculateSolarRadTotal() ===" << endl;
    int sum = test.CalculateSolarRadTotal(3,2014);
    cout << "Solar Rad Total: " << sum << endl << endl;
}
