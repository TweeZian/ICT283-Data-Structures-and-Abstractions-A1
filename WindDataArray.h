/***
@author Thien Twee Zian
@since 26/06/2023
@version 1.01
Holds wind data objects in a vector array, as well as the computational
methods requiring the use of stored data
*/

#ifndef WINDDATAARRAY_H_INCLUDED
#define WINDDATAARRAY_H_INCLUDED

#include <fstream>
#include <cmath>
#include <string>
#include <sstream>
#include "WindData.h"
#include "Vector.h"

using namespace std;

/**
This class is used to store the wind data objects in a vector array,
as well as the computational methods requiring the use of stored data
*/
class WindDataArray
{
private:
    /**
    Used to store the wind data objects in a vector array
    */
    Vector<WindData> m_array;

    /**
    For indicating the csv data retrieved by its columns.
    To be used for storage of data into appropriate WindData attributes
    */
    Vector<string> m_headerNames;

public:
    /**
    Default constructor
    */
    WindDataArray();

    /**
    This method is used to retrieve a WindData object from the vector array,
    from a specified index position
    @param element - WindData object to be retrieved, passed via reference
    @param index - Position of element in the array to be retrieved
    */
    void Get(WindData &element, int index);

    /**
    This method is used to find the number of elements in the array.
    @return size - Number of elements in the array
    */
    int Size();

    /**
    This method is used to find the header names from the input csv files,
    to be used for identifying the columns in the csv file for processing data
    storage.
    @param line - Header row from csv file as a string
    */
    void SetHeaderNames(string &line);

    // Methods for storage is stored in this class instead of WindData as:
    // 1. It requires the use of headerNames to find the right attributes to be stored.
    // 2. This class is used to adjust the attributes to be stored, only taking the ones required,
    //    therefore keeping the WindData encapsulated and purely for the storage of data.

    /**
    This method is used to read a csv file and extract the required information within.
    This method is to be used with the appropriate data type storage methods.
    @param fileName - Name of data file
    @return boolean - Return true if operation is successful, otherwise false.
    */
    bool ReadInputFileToStorage(const string &fileName);

    /**
    This method is used to store the date and time into the WindData object
    @param wd - WindData object to store at
    @param line - String of data to store
    @param currentColumn - Used to indicate the current data in line
    */
    void StoreDateAndTime(WindData &wd, string &line, int currentColumn);

    /**
    This method is used to store the air temperature into the WindData object
    @param wd - WindData object to store at
    @param line - String of data to store
    @param currentColumn - Used to indicate the current data in line
    */
    void StoreAirTemp(WindData &wd, string &line, int currentColumn);

    /**
    This method is used to store the wind speed into the WindData object
    @param wd - WindData object to store at
    @param line - String of data to store
    @param currentColumn - Used to indicate the current data in line
    */
    void StoreSpeed(WindData &wd, string &line, int currentColumn);

    /**
    This method is used to store the solar radiation into the WindData object
    @param wd - WindData object to store at
    @param line - String of data to store
    @param currentColumn - Used to indicate the current data in line
    */
    void StoreSolarRad(WindData &wd, string &line, int currentColumn);

    /**
    This method is used to calculate the average wind speed of given month and year
    @param month - Month to be calculated
    @param year - Year to be calculated
    @return mean - Average wind speed
    */
    float CalculateWindSpeedMean(int month, int year);

    /**
    This method is used to calculate the standard deviation of wind speed of given month and year
    @param month - Month to be calculated
    @param year - Year to be calculated
    @return sd - Wind speed standard deviation
    */
    float CalculateWindSpeedSD(int month, int year);

    /**
    This method is used to calculate the average air temperature of given month and year
    @param month - Month to be calculated
    @param year - Year to be calculated
    @return mean - Average air temperature
    */
    float CalculateAirTempMean(int month, int year);

    /**
    This method is used to calculate the standard deviation of air temperature of given month and year
    @param month - Month to be calculated
    @param year - Year to be calculated
    @return sd - Air temperature standard deviation
    */
    float CalculateAirTempSD(int month, int year);

    /**
    This method is used to calculate the total solar radiation of given month and year
    @param month - Month to be calculated
    @param year - Year to be calculated
    @return sum - Total solar radiation
    */
    int CalculateSolarRadTotal(int month, int year);


};
#endif // WINDDATAARRAY_H_INCLUDED
