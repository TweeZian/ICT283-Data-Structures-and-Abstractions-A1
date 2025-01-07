#include "WindDataArray.h"

WindDataArray::WindDataArray()
{

}

void WindDataArray::Get(WindData &element, int index)
{
    element = m_array.At(index);
}

int WindDataArray::Size()
{
    return m_array.Size();
}

bool WindDataArray::ReadInputFileToStorage(const string &fileName)
{
    ifstream infile(fileName);
    if( !infile ) return false;

    string line;
    getline(infile,line); // get header column names
    SetHeaderNames(line);
    while(getline(infile,line))
    {
        WindData wd;
        istringstream iss(line); // initialize row into stream format to be used for processing data into individual columns
        string ssline;
        int currentColumn = 0; // first column starts at 0

        while(getline(iss,ssline,','))
        {
            // runs through every storage column, when matching column found, store data into right storage
            StoreDateAndTime(wd,ssline,currentColumn);
            StoreAirTemp(wd,ssline,currentColumn);
            StoreSpeed(wd,ssline,currentColumn);
            StoreSolarRad(wd,ssline,currentColumn);

            currentColumn++;
        }
        m_array.Add(wd);
    }
    infile.close();
    return true;
}

void WindDataArray::StoreDateAndTime(WindData &wd, string &line, int currentColumn)
{
    string name = m_headerNames.At(currentColumn);

    if(name.compare("WAST") == 0)
    {
        Date d;
        Time t;
        istringstream iss(line);
        iss >> d >> t;
        wd.SetDate(d);
        wd.SetTime(t);
    }

}

void WindDataArray::StoreAirTemp(WindData &wd, string &line, int currentColumn)
{
    string name = m_headerNames.At(currentColumn);
    if(name.compare("T") == 0)
    {
        wd.SetAirTemp(stof(line));
    }

}

void WindDataArray::StoreSpeed(WindData &wd, string &line, int currentColumn)
{
    string name = m_headerNames.At(currentColumn);
    if(name.compare("S") == 0)
    {
        wd.SetSpeed(stof(line));
    }
}

void WindDataArray::StoreSolarRad(WindData &wd, string &line, int currentColumn)
{
    string name = m_headerNames.At(currentColumn);
    if(name.compare("SR") == 0)
    {
        wd.SetSolarRad(stoi(line));
    }
}

void WindDataArray::SetHeaderNames(string &line)
{
    istringstream iss(line);
    while(getline(iss,line,','))
    {
        m_headerNames.Add(line);
    }
}

float WindDataArray::CalculateWindSpeedMean(int month, int year)
{
    float sum;
    float counter;
    for(int i = 0; i < Size(); i++)
    {
        WindData wd;
        wd = m_array.At(i);
        Date d;
        wd.GetDate(d);
        if(d.GetYear() == year) // run through every year to find right year
        {
            if(d.GetMonth() == month)
            {
                sum += wd.GetSpeed();
                counter++;
            }
        }
    }
    float mean = sum / counter;

    if(mean == 0)
    {
        return 0;
    }
    else
    {
        return mean;
    }

}

float WindDataArray::CalculateWindSpeedSD(int month, int year)
{
    float mean = CalculateWindSpeedMean(month,year);
    float sum;
    float counter;
    for(int i = 0; i < Size(); i++)
    {
        WindData wd;
        wd = m_array.At(i);
        Date d;
        wd.GetDate(d);
        if(d.GetYear() == year)
        {
            if(d.GetMonth() == month)
            {
                sum += (wd.GetSpeed() - mean)*(wd.GetSpeed() - mean);
                counter++;
            }
        }
    }

    sum = sum / counter;
    sqrt(sum);

    if(sum == 0)
    {
        return 0;
    }
    else
    {
        return sum;
    }
}

float WindDataArray::CalculateAirTempMean(int month, int year)
{
    float sum;
    float counter;
    for(int i = 0; i < Size(); i++)
    {
        WindData wd;
        wd = m_array.At(i);
        Date d;
        wd.GetDate(d);
        if(d.GetYear() == year)
        {
            if(d.GetMonth() == month)
            {
                sum += wd.GetAirTemp();
                counter++;
            }
        }
    }
    float mean = sum / counter;

    if(mean == 0)
    {
        return 0;
    }
    else
    {
        return mean;
    }
}

float WindDataArray::CalculateAirTempSD(int month, int year)
{
    float mean = CalculateAirTempMean(month,year);
    float sum;
    float counter;
    for(int i = 0; i < Size(); i++)
    {
        WindData wd;
        wd = m_array.At(i);
        Date d;
        wd.GetDate(d);
        if(d.GetYear() == year)
        {
            if(d.GetMonth() == month)
            {
                sum += (wd.GetAirTemp() - mean)*(wd.GetAirTemp() - mean);
                counter++;
            }
        }
    }

    sum = sum / counter;
    sqrt(sum);

    if(sum == 0)
    {
        return 0;
    }
    else
    {
        return sum;
    }
}

int WindDataArray::CalculateSolarRadTotal(int month, int year)
{
    int sum;
    for(int i = 0; i < Size(); i++)
    {
        WindData wd;
        wd = m_array.At(i);
        Date d;
        wd.GetDate(d);
        if(d.GetYear() == year)
        {
            if(d.GetMonth() == month)
            {
                sum += wd.GetSolarRad();
            }
        }
    }
    return sum;
}


