//
// Created by L-royse on 2022/4/15.
//

#include "Datee.h"
//
// Created by L-royse on 2022/4/15.
//
#include <iostream>

using namespace std;
int main()
{
    Datee mydefdate;
    Datee myowndate(1,10,2998,"mosjcoa dv");
    string sdefdate=mydefdate.getformatteddate();
    string sowndate=myowndate.getformatteddate();\
    cout<<sdefdate<<endl;
    cout<<sowndate<<endl;
    return 0;
}