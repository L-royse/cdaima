//
// Created by L-royse on 2022/4/15.
//

#ifndef UNTITLED19_DATEE_H
#define UNTITLED19_DATEE_H
#include <string>
using namespace std;
class Datee {
private:
    int month,day,year;
    string description;
    int dayofyear;
    bool bleap;
    void calcdayofyear();
    void determinleaptear();
public:
    Datee();
    Datee(int m,int d,int y,string desc);
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


#endif //UNTITLED19_DATEE_H
