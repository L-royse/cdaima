//
// Created by L-royse on 2022/1/27.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
void writess ()
{
    cout<<"这是一个c++农行灌溉程序"<<"\n 多大的英尺"
    <<"你需要输入面积大小，，灌溉深度，水的流速，程序会给出所需要的水量和灌溉所需要的时间";
}
float asksize()
{
    float size;
    cout<<"输入面积大小"<<endl;
    cin>>size;
    cin.ignore();
    return size;
}
int askdepth()
{
    int depth;
    cout<<"你想灌溉多深的土地"<<endl;
    cin>>depth;
    cin.ignore();
    return depth;
}
float askrate()
{
    float rate;
    cout<<"输入水流速"<<endl;
    cin>>rate;
    cin.ignore();
    return rate;
}
string talkthev(int depth,float rate,float size)
{
    int adre=43560;
    int totalfeet=adre*size;
    int inches=totalfeet*144;   //转化为英寸标准化
    int fieldv=inches*depth;    //灌溉体积
    float gallons=fieldv/231.0;
    float time=gallons/rate;
    stringstream ssobj;
    ssobj<<"A  "<<size<<"acre field "<<"flooded  to "<<depth<<" inches"<<
    "\n require "<<gallons<<"water"<<endl;
    ssobj<<"水流速为"<<rate<<" 需要"<<time<<endl;
    return ssobj.str();
}
