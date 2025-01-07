/***
@author Thien Twee Zian
@since 30/07/2023
@version 1.02
Hold required wind data information into a collective object
*/
#ifndef WINDDATA_H_INCLUDED
#define WINDDATA_H_INCLUDED

#include "Date.h"
#include "Time.h"

using namespace std;

/**
This class is used to hold all the required wind data information
*/
class WindData
{
private:
    /**
    Date class object holding the date of wind record
    */
    Date m_date;

    /**
    Time class object holding the time of wind record
    */
    Time m_time;

    /**
    Wind speed at time of record
    */
    float m_speed;

    /**
    Air Temperature at time of record
    */
    float m_airTemp;

    /**
    Solar radiation at time of record
    */
    int m_solarRad;

public:
    /**
    Default constructor
    */
    WindData();

    /**
    Constructor to initialize the WindData attribute
    @param date - Time of wind record
    @param time - Date of wind record
    @param speed - Wind Speed
    @param airTemp - Air Temperature
    @param solarRad - Solar Radiation
    */
    WindData(Date date,Time time,float speed,float airTemp,int solarRad);

    /**
    Get date
    @param date - Date object to be retrieved to
    */
    void GetDate(Date &date) const;

    /**
    Get time
    @param time - Date object to be retrieved to
    */
    void GetTime(Time &time) const;

    /**
    Get speed
    @return speed - Speed of wind
    */
    float GetSpeed() const;

    /**
    Get air temperature
    @return airTemp - Air temperature
    */
    float GetAirTemp() const;

    /**
    Get solar radiation
    @return solarRad - Solar radiation
    */
    int GetSolarRad() const;

    /**
    Set date
    @param date - Date object to be set
    */
    void SetDate(const Date &date);

    /**
    Set time
    @param time - Time object to be set
    */
    void SetTime(const Time &time);

    /**
    Set speed
    @param speed - Speed to be set
    */
    void SetSpeed(float speed);

    /**
    Set air temperature
    @param airTemp - Air temperature to be set
    */
    void SetAirTemp(float airTemp);

    /**
    Set solar radiation
    @param solarRad - Solar radiation to be set
    */
    void SetSolarRad(int solarRad);

};

/**
Overloaded >> operator to read attributes of a WindData
@param input - Variable initialized to store input stream
@param wd - WindData object whose attributes is to be set
@return input - Return EOF once all lines are read
*/
ostream & operator <<( ostream & os, const WindData & wd );
#endif // WINDDATA_H_INCLUDED
