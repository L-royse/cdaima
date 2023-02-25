//
// Created by L-royse on 2022/1/19.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool searchforname(vector<string>&names,vector<string>&origins,string &username,string &nameorigin)
{
    int index=0;
    while(index<names.size())
    {
        if(username==names.at(index))
        {
            nameorigin=origins.at(index);
            return true;
        }
        else
        {
            ++index;
        }
    }
    return false;
}
void fillvector(vector<string>&names,vector<string>&origins)  //vector库函数，存储信息在里面
{
    names.push_back("barbar");
    origins.push_back("greek,meaning stranger");

    names.push_back("kelly");
    origins.push_back("l am kelly ");

    names.push_back("zhangsan");
    origins.push_back("zhangsan zuishuai");

    names.push_back("lisi");
    origins.push_back("lisi is a dog");

    names.push_back("wanglaowu");
    origins.push_back("wanglaowu sha bi");

    names.push_back("lucy");
    origins.push_back("lucy is no one");
}
string askuserforname()
{
    string uname;
    cout<<"输入名字"<<endl;
    getline(cin,uname);
    return uname;
}
