#include "Date.h"

Date::Date()
{
    m_date = "null";
}

Date::Date(string date)
{
    m_date = date;
}

int Date::GetDay() const
{
    return m_day;
}

int Date::GetMonth() const
{
    return m_month;
}

int Date::GetYear() const
{
    return m_year;
}

void Date::SetDay(const int day)
{
    m_day = day;
}

void Date::SetMonth(const int month)
{
    m_month = month;
}

void Date::SetYear(const int year)
{
    m_year = year;
}

string Date::GetDate() const
{
    return m_date;
}

void Date::SetDate(const string &date)
{
    m_date = date;
}

istream & operator >>( istream & input, Date & date )
{
    string tempString;
    getline(input,tempString,' ');
    date.SetDate(tempString);

    istringstream iss(tempString); // takes the date and initialize it as a stream to be split
    getline(iss,tempString,'/');
    date.SetDay(stoi(tempString));
    getline(iss,tempString,'/');
    date.SetMonth(stoi(tempString));
    getline(iss,tempString);
    date.SetYear(stoi(tempString));

    return input;
}

ostream & operator <<( ostream & os, const Date & date )
{
    os << "Date : " << date.GetDate() << '\n';
    return os;
}
