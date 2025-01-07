/***
@author Thien Twee Zian
@since 24/06/2023
@version 1.01
Holds the time for records of wind speed
*/

#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

/**
This class is used to store the time for each record of wind information
*/
class Time
{
private:
    /**
    The time of each wind recording
    */
    string m_time;

public:
    /**
    Default constructor to initialize all attributes
    */
    Time();

    /**
    Constructor to initialize the Time attribute
    @param time - Time of wind record
    */
    Time(string time);

    /**
    Get time
    @return m_time - Time of wind record
    */
    string GetTime() const;

    /**
    Set time
    @param time - Time of wind record
    */
    void SetTime(const string time);

};

/**
Overloaded << operator to print attributes of the Time
@param os - Variable initialized to store output stream
@param time - Time object containing data to be printed
@return os - Return output stream to be printed
*/
ostream & operator <<( ostream & os, const Time & time );

/**
Overloaded >> operator to read attributes of a Time
@param input - Variable initialized to store input stream
@param time - Time object whose attributes is to be set
@return input - Return EOF once all lines are read
*/
istream & operator >>( istream & input, Time & time );

#endif // TIME_H_INCLUDED
