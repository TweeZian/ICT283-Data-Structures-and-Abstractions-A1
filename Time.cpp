#include "Time.h"

Time::Time()
{
    m_time = "null";
}

Time::Time(string time)
{
    m_time = time;
}

string Time::GetTime() const
{
    return m_time;
}

void Time::SetTime(const string time)
{
    m_time = time;
}

ostream & operator <<( ostream & os, const Time & time )
{
    os << "Time : " << time.GetTime() << '\n';
    return os;
}

istream & operator >>( istream & input, Time & time )
{
    string tempString;
    getline(input, tempString, ',');
    time.SetTime(tempString);

    return input;
}
