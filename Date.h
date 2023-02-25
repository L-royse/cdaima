//
// Created by L-royse on 2022/4/15.
//

#ifndef UNTITLED19_DATE_H
#define UNTITLED19_DATE_H
#include <string>
using namespace std;
class Date
{
private:
    int month,day,year;
    string description;
    int dayofyear;
    bool bleap;
    void calcdayofyear();
    void determinleaptear();
public:
    Date();
    Date(int m,int d,int y,string desc);
    void setdate(int m,int d,int y,string desc);
    void setdesc(string d)
    {
        description=d;
    }
    string getformatteddate();
    int getdayofyear()
    {
        return dayofyear;
    }
    int getyear()
    {
        return year;
    }
    int getmonth()
    {
        return month;
    }
    int getday()
    {
        return day;
    }
    bool isleapyear()
    {
        return bleap;
    }
};
#endif //UNTITLED19_DATE_H
