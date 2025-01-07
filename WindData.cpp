#include "WindData.h"

WindData::WindData()
{
    m_speed = 0;
    m_airTemp = 0;
    m_solarRad = 0;
}

WindData::WindData(Date date,Time time,float speed,float airTemp,int solarRad)
{
    m_date = date;
    m_time = time;
    m_speed = speed;
    m_airTemp = airTemp;
    m_solarRad = solarRad;
}

void WindData::GetDate(Date &date) const
{
    date = m_date;
}

void WindData::GetTime(Time &time) const
{
    time = m_time;
}

float WindData::GetSpeed() const
{
    return m_speed;
}

float WindData::GetAirTemp() const
{
    return m_airTemp;
}

int WindData::GetSolarRad() const
{
    return m_solarRad;
}

void WindData::SetDate(const Date &date)
{
    m_date = date;
}

void WindData::SetTime(const Time &time)
{
    m_time = time;
}

void WindData::SetSpeed(float speed)
{
    m_speed = speed;
}

void WindData::SetAirTemp(float airTemp)
{
    m_airTemp = airTemp;
}

void WindData::SetSolarRad(int solarRad)
{
    //only store solar radiation if >= 100
    if(solarRad >= 100)
    {
        m_solarRad = solarRad;
    }
    else
    {
        m_solarRad = 0;
    }

}

ostream & operator <<( ostream & os, const WindData & wd )
{
    Date d;
    wd.GetDate(d);
    Time t;
    wd.GetTime(t);
    os << d;
    os << t;
    os << "Speed           : " << wd.GetSpeed() << endl;
    os << "Air Temperature : " << wd.GetAirTemp() << endl;
    os << "Solar Radiation : " << wd.GetSolarRad() << endl;

    return os;
}



