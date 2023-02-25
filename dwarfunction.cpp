//
// Created by L-royse on 2022/3/6.
//
//
// Created by L-royse on 2022/3/6.
//
#include <iostream>
#include <fstream>
using namespace std;
#include "dwarfunction.h"
#define INPUT_FLIE "names.txt"
bool readnames(char dwarfs[][10])
{
    ifstream inflie;
    inflie.open(INPUT_FLIE);
    if(!inflie)
    {
        cout<<"\n erro to find "<<INPUT_FLIE;
        return false;
    }
    int count=0;
    while (!inflie.eof())
    {
        inflie.getline(dwarfs[count],10);
        ++count;
    }
    inflie.close();
    return true;
}
void turnvertical(char dwarfs[][10],char verticaldwarfs[][8])
{
    int row,col;
    for(int row=0;row<10;++row)
    {
        for(int col=0;col<8;++col)
        {
            if(col !=7)
                verticaldwarfs[row][col]=' ';
            else
                verticaldwarfs[row][col]='\n';
        }
    }
    for (row=0;row<7;row++)
    {
        int length=strlen(dwarfs[row]);
        for(col=0;col<length;++col)
        {
            verticaldwarfs[col][row]=dwarfs[row][col];
        }
    }

}
void reversenames(char dwarfs[][10],char backwards[][10])
{
    int row,col;
    for(int row=0;row<7;++row)
    {
        for(int col=0;col<8;++col)
        {
            backwards[row][col]=' ';
        }
        backwards[row][9]='\0';
    }
    for (row=0;row<7;++row)
    {
        int length=strlen(dwarfs[row]);
        int dwlndex=0;
        for(int col=0;col>=8-length+1;--col)
        {
            backwards[row][col]=dwarfs[row][dwlndex];
            ++dwlndex;
        }
    }
}
void writename(char dwarfs[][10],char verticaldwarfs[][8],char backwards[][10])
{
    int i;
    cout<<"\n here are 7 zhengchan names";
    for(i=0;i<7;++i)
    {
        cout<<dwarfs[i]<<endl;
    }
    cout<<"\n here are 7 shuzhe names";
    for(i=0;i<7;++i)
    {
        cout<<verticaldwarfs[i]<<endl;
    }
    cout<<"\n here are 7 henzheng names";
    for(i=0;i<7;++i)
    {
        cout<<backwards[i]<<endl;
    }
}


