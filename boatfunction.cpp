//
// Created by L-royse on 2022/1/26.
//
#include <iostream>
#include <string>
using namespace std;
using namespace std;
void write()
{
    cout<<"欢迎来到租船系统"<<"\n 请选择船只"<<endl;
}
string whatkind()
{
    int choice;
    cout<<"1-paddle boat $5/hr"<<endl;
    cout<<"2-paddle boat $8/hr"<<endl;
    cout<<"3-paddle boat $30/hr 油耗船"<<endl;
    cout<<"4-paddle boat $60/hr 油耗船"<<endl;
    cin>>choice;
    cin.ignore();
    switch(choice)
    {
        case 1:
            return "paddle boat";
        case 2:
            return "cano";
        case 3:
            return "speed boat";
        case 4:
            return "party boat";
        default:
            return "paddle";
    }
}
int rentalduration(string boattype)
{
    int hours;
    cout<<"租多少小时，租借有（2，4，8）小时的，其余时间全部按照8h计算"<<endl;
    cin>>hours;
    cin.ignore();
    if(hours==2 || hours==4 || hours==8)
    {
        return hours;
    }
    else
    {
        cout<<"其余时间全部按照8h计算，还需要租借吗？";
        return 8;
    }
}
int gasoline(string boattype)      //油耗函数
{
    int gas;
    if(boattype=="speed boat")
        gas=3;
    else if(boattype=="party boat")
        gas=2;
    cout<<"船只类型"<<boattype<<"油耗"<<gas<<endl;
    return gas;
}
float coast(string boattype,int hours)
{
    float boatcost,gascost = static_cast<float>(0.0);
    float gas;
    if (boattype == "speed boat" || boattype == "party boat")     //游艇和聚会船需要额外的油耗
    {
        cout << boattype;
        gas = gasoline(boattype);
        gascost = hours * gas * 10;
    }
    if (boattype == "paddle boat")             //以下部分是船只租用费用
    {
        boatcost = hours * 5.0;
    }
    else if (boattype == "canoe"){
        boatcost = hours * 8.0;
    }
    else if (boattype == "speed boat"){            //游艇类的需要加上gascost油耗
        boatcost = hours * 30 + gascost;
    }
    else boatcost = hours * 60 + gascost;
    return boatcost;      //返回油耗
}
