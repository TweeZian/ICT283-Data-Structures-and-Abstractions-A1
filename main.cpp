#include <iostream>
#include <fstream>
#include "WindDataArray.h"

using namespace std;

const string DATA_SOURCE = "data/data_source.txt"; //data source file stored in data folder
const string OUTPUT_FILE = "data/WindTempSolar.csv"; //stored in data folder

void StoreDataToArray(WindDataArray &wd);
int GetChoice();
int GetMonthChoice();
int GetYearChoice();
string FindMonthAsString(int monthNum);
double ConvertSolarRad(int solarRad); //converts solarRad from W/m2 to kWh/m2
void Menu1(WindDataArray &wda);
void Menu2(WindDataArray &wda);
void Menu3(WindDataArray &wda);
void Menu4(WindDataArray &wda);
bool CheckDataExistInMonth(int month, int year, WindDataArray &wda);
bool CheckDataExistInYear(int year, WindDataArray &wda);
void PrintDataToFile(ofstream &outFile, int month, int year, WindDataArray &wda);

const string MONTH_STRING[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};

int main()
{

    WindDataArray wda;
    StoreDataToArray(wda);
    int choice;
    do
    {
        choice = GetChoice();
        switch(choice)
        {
        case 1:
            Menu1(wda);
            break;
        case 2:
            Menu2(wda);
            break;
        case 3:
            Menu3(wda);
            break;
        case 4:
            Menu4(wda);
            break;
        case 5:
            cout << "Program will now exit." << endl;
            break;
        default:
            cout << "Invalid choice, please reenter." << endl << endl;
        }
    }
    while(choice != 5);

    return 0;
}

void StoreDataToArray(WindDataArray &wda)
{
    ifstream sourceFile(DATA_SOURCE);
    string line;
    while(getline(sourceFile,line)) //read source file to find csv file
    {
        line = "data/" + line; //set data folder into line
        wda.ReadInputFileToStorage(line); //input data into array for every data file in source txt
    }
}

int GetChoice()
{
    cout << "Menu: " << endl;
    cout << "1. Display the average wind speed and sample standard deviation for this wind speed given a specified month and year." << endl;
    cout << "2. Display the average ambient air temperature and sample standard deviation for each month of a specified year." << endl;
    cout << "3. Display the total solar radiation in kWh/m2 for each month of a specified year." << endl;
    cout << "4. Print average wind speed(km/h), average ambient air temperature and total solar radiation in kWh/m2 for each month of a specified year to a csv file" << endl;
    cout << "5. Exit the program." << endl << endl;

    int choice;
    cout << "Please enter choice: " << endl;
    cin >> choice;
    cout << endl;
    return choice;

}

int GetMonthChoice()
{
    int month;
    do
    {
        cout << "Please enter a month as integer (e.g January = 1): " << endl;
        cin >> month;
        if(month < 0 || month > 12)
        {
            cout << "Invalid choice, please reenter." << endl << endl;
        }
    }
    while(month < 0 || month > 12); // run loop till month is valid (1-12)
    cout << endl;

    return month;
}

int GetYearChoice()
{
    int year;
    cout << "Please enter a year: " << endl;
    cin >> year;
    cout << endl;
    return year;
}

string FindMonthAsString(int monthNum)
{
    string monthString;
    switch(monthNum)
    {
    case 1:
        monthString = "January";
        break;
    case 2:
        monthString = "February";
        break;
    case 3:
        monthString = "March";
        break;
    case 4:
        monthString = "April";
        break;
    case 5:
        monthString = "May";
        break;
    case 6:
        monthString = "June";
        break;
    case 7:
        monthString = "July";
        break;
    case 8:
        monthString = "August";
        break;
    case 9:
        monthString = "September";
        break;
    case 10:
        monthString = "October";
        break;
    case 11:
        monthString = "November";
        break;
    case 12:
        monthString = "December";
        break;
    default:
        monthString = "Null Month";
        break;
    }
    return monthString;
}

double ConvertSolarRad(int solarRad)
{
    double temp;
    temp = solarRad * 1/6;
    temp = temp/1000;
    return temp;
}

void Menu1(WindDataArray &wda)
{
    int year = GetYearChoice();
    int month = GetMonthChoice();
    //cout << FindMonthAsString(month) << " " << year << ": ";
    cout << MONTH_STRING[month-1] << " " << year << ": ";

    float mean = wda.CalculateWindSpeedMean(month,year);
    float sd = wda.CalculateWindSpeedSD(month,year);

    if(mean != 0) // print info only if there is data, if mean == 0, sd assumed to be 0 too.
    {
        cout << endl;
        cout << "Average speed: " << mean * 3.6 << " km/h" << endl; // converts from m/s to km/h
        cout << "Sample stdev: " << sd << endl;
    }
    else
    {
        cout << "No Data" << endl;
    }
    cout << endl;

}

void Menu2(WindDataArray &wda)
{
    int year = GetYearChoice();
    cout << year << endl;

    for(int i = 1; i <= 12; i++) // run all 12 months
    {
        float mean = wda.CalculateAirTempMean(i,year);
        float sd = wda.CalculateAirTempSD(i,year);
        if(mean != 0)
        {
            cout << FindMonthAsString(i)
                 << ": average: " << mean << " degrees C"
                 << ", stdev: " << sd << endl;
        }
        else
        {
            cout << FindMonthAsString(i) << ": No Data" << endl;
        }
    }
    cout << endl;
}

void Menu3(WindDataArray &wda)
{
    int year = GetYearChoice();
    cout << year << endl;

    for(int i = 1; i <= 12; i++)
    {
        int solarRad = wda.CalculateSolarRadTotal(i,year);
        if(solarRad != 0) // print info only if there is data
        {
            cout << FindMonthAsString(i) << ": "
                 << ConvertSolarRad(solarRad) << " kWh/m2" << endl;
        }
        else
        {
            cout << FindMonthAsString(i) << ": No Data" << endl;
        }
    }
    cout << endl;
}

void Menu4(WindDataArray &wda)
{
    ofstream outFile(OUTPUT_FILE);
    if(!outFile)// check if file is available for writing
    {
        cout << "Error in opening output file, please check before retrying." << endl << endl;
    }
    else
    {
        int year = GetYearChoice();
        outFile << year << endl;

        if(CheckDataExistInYear(year,wda)) // check if there is data in given year
        {
            for(int i = 1; i <= 12; i++) // set i to run as every instance of month
            {
                if(CheckDataExistInMonth(i,year,wda)) // check if there is data in given month of year
                {
                    PrintDataToFile(outFile,i,year,wda);
                }
            }
        }
        else // run if no data found in given year
        {
            outFile << "No Data";
        }
        outFile.close();

    }

}

void PrintDataToFile(ofstream &outFile, int month, int year, WindDataArray &wda)
{
    outFile << FindMonthAsString(month) << ",";
    if(wda.CalculateWindSpeedMean(month,year) != 0) // check if there is wind speed data, else skip
    {
        outFile << wda.CalculateWindSpeedMean(month,year) * 3.6 // converts from m/s to km/h
                << "(" << wda.CalculateWindSpeedSD(month,year) << "),";
    }
    else
    {
        outFile << ",";
    }

    if(wda.CalculateAirTempMean(month,year) != 0) // check if there is air temp data, else skip
    {
        outFile << wda.CalculateAirTempMean(month,year) << "("
                << wda.CalculateAirTempSD(month,year) << "),";
    }
    else
    {
        outFile << ",";
    }

    if(wda.CalculateSolarRadTotal(month,year) != 0) // check if there is solar rad data, else skip
    {
        outFile << ConvertSolarRad(wda.CalculateSolarRadTotal(month,year)) << endl;
    }
    else
    {
        outFile << endl;
    }
}

bool CheckDataExistInMonth(int month, int year, WindDataArray &wda)
{
    if(wda.CalculateWindSpeedMean(month,year) != 0)
    {
        if(wda.CalculateAirTempMean(month,year) != 0)
        {
            if(wda.CalculateSolarRadTotal(month,year) != 0)
            {
                return true;
            }
        }
    }
    else
    {
        return false;
    }
}

bool CheckDataExistInYear(int year, WindDataArray &wda)
{
    for(int i = 1; i <= 12; i++) // check data every month for given year
    {
        if(wda.CalculateWindSpeedMean(i,year) != 0) // check if there is wind speed data
        {
            return true;
        }
        if(wda.CalculateAirTempMean(i,year) != 0) // check if there is air temp data
        {
            return true;
        }
        if(wda.CalculateSolarRadTotal(i,year) != 0) // check if there is solar rad data
        {
            return true;
        }
    }
    return false; // only when checking every month of given year, and no data can be found
}

