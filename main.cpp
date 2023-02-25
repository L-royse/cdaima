/*
 *
 在编写程序之前，需要书写cmake文件来使得makefile文件可执行
 格式如下：

project(hello_jelly)
set(APP_SRC main.c)
add_executable(${PROJECT_NAME} main.c)
#print message
message(${PROJECT_SOURCE_DIR})

第一个行project不是强制性的，最好加上，这会引入两个变量：

HELLO_BINARY_DIR, HELLO_SOURCE_DIR

同时也会定义两个等价的变量：

PROJECT_BINARY_DIR, PROJECT_SOURCE_DIR

外部编译要时刻区分这两个变量对应的目录

可以通过message进行输出

message(${PROJECT_SOURCE_DIR})

set 命令用来设置变量

add_exectuable 告诉工程生成一个可执行文件。

add_library 则告诉生成一个库文件。

CMakeList.txt 文件中，命令名字是不区分大小写的，而参数和变量是大小写相关的。

*/
/*   块注释符

 标准化注释

 是不可以使用的。

#if 0 ... #endif 属于条件编译，0 即为参数。

此外，我们还可以使用 #if 0 ... #endif 来实现注释，且可以实现嵌套，格式为：

#if 0
   code
#endif
你可以把 #if 0 改成 #if 1 来执行 code 的代码。

这种形式对程序调试也可以帮助，测试时使用 #if 1 来执行测试代码，发布后使用 #if 0 来屏蔽测试代码。

#if 后可以是任意的条件语句。

下面的代码如果 condition 条件为 true 执行 code1 ，否则执行 code2。

#if condition
  code1
#else
  code2
#endif
 */


//           第一章
//    基础操作，输入输出，规范化
//
/*
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int mony=435.83;
    short int cs=53434; //存储超过short int的长度导致存储出现误差
    float pi=3.1415926535;
    double pI=3.1415926535;
    double x=15;
    cout<<"money(int)"<<mony<<endl;
    cout<<"cs(s int)"<<cs<<endl;
    cout.setf(ios::showpoint|ios::fixed);
    cout.precision(14);
    cout<<"pi(float)"<<pi<<endl;
    cout<<"pi(double)"<<pI<<endl;
    cout<<"x(double)"<<x<<endl;
    return 0;
}
*/
/*#include <iostream>
#include <cmath>     // std::cout, std::endl
using namespace std;

int main ()
{
const double x=7.2312;
x=2;
cout<<x<<endl;
return 0;
}
 */
/*#include <iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    m=n%2;
    if(m==1)
        cout<<n<<"jishu"<<endl;
    else
        cout<<n<<"oushu"<<endl;
    return 0;
}*/
/*#include <iostream>
using namespace std;
int main()
{
    int resint;
    double resdouble;
    resint=16/3;
    resdouble=16/3;
    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(14);
    cout<<resint<<endl;
    cout<<resdouble<<endl;

    resint=16.0/3.0;
    resdouble=16/3.0;
    cout<<resint<<endl;
    cout<<resdouble<<endl;
    return 0;
}*/
/*#include <iostream>
#include <iomanip>  //使用标准输出的库
using namespace std;
int main()
{
    double x,y,z,q;
    x=2+5.0*4-6.0*7/2;
    y=(2+5.0)*4-(6.0*7/2);
    z=2+(5.0*4-6.0)*7/2;
    q=2+5.0*(4-6.0*7)/2;

    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(3);
    cout<<x<<endl;
    cout<<y<<endl;
    cout<<z<<endl;
    cout<<q<<endl;
    return 0;
}
 */
/*
#include <iostream>
#include <iomanip>

using namespace std; //换行符的使用，还有不同的/——符号来表示不同的意思

int main()
{
   cout<<"\n how are you like "
   <<"\"c++ projcaiia today 2ND edition\"?";
   cout<<"\n the \\n is an escape sequence for a newline.\n\n";
    return 0;
}*/
/*
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double pi=3.141592653589793;
    double feet=5280;
    double number=123.456789;

    cout.precision(5);   //规格化5个数
    cout.setf(ios::showpoint);  //展示小数点，缺少会导致整数缺少小数，从而达不到5位
    cout<<pi<<'\n'<<feet<<'\n'<<number<<'\n'<<endl;
    cout.setf(ios::fixed); //输出5个小数
    cout<<pi<<'\n'<<feet<<'\n'<<number<<'\n'<<endl;
    return 0;
}
 */

//这块就需要掌握不同的输出方式和输出的结果
//掌握setprecision（n）的用法，规定输出的数个数为n个
//掌握setw（）来设置数据的宽度
//掌握setf（ios：：fixed）使用，输出格式的设置，unsetf不使用格式
//掌握数据转化的方式，static_cast<要转化的类型>（变量）

/*#include<iostream>
#include <string>
using namespace std;
int main()
{
    string name;
    string school;
    string favlang="c++,of course";
    cout<<"输入学生名字";
    getline(cin,name);
    cout<<"输入学校;";
    getline(cin,school);
    cout<<name<<" "<<school<<" "<<favlang<<endl;
    return 0;
}
 */
//用sting类的输入函数getline好处在于对比cin当cin出现空格时就会输入停止，而getline正是消除了这一问题
//cin不适合读入字符串对象，而string中的getline就哼容易的解决了这个问题，出现变量。size的时候；例如a.size（）时这就是对取字符串的长度
/*#include <iostream>
#include <string>
using namespace std;
int main()
{
    string sentence;
    string word;
    getline(cin,sentence);
    getline(cin,word);
    int sentsize=sentence.size();
    int wordsize=word.size();

    int wordinsentence=sentence.find(word);
    cout<<sentence<<endl;
    cout<<word<<endl;
    cout<<sentsize<<endl;
    cout<<wordsize<<endl;
    cout<<wordinsentence<<endl;
    return 0;
}
 */
//
//这里讲的是程序运行字符串长度的测量.size（）来测取字符串的长度，而z=a.find（b）是用来选招字符串b在a的第几个字符串出现的，如果b存在与a中
//那么z会给出所出现的位值，而不存在与a中的时候就会现实-1来强调在a字符串中找不到b字符串。
//
/*#include<iostream>
#include <cmath>
#include<iomanip>
#define pi 3.1415926535
using namespace std;
int main()
{
    double r1,r2,l,v;  //r1球半径，r2为圆柱体半径，l为长度
    cin>>r1>>r2>>l;
    v=2*((4.0/3.)*pi*pow(r1,3))+pi*pow(r2,2)*l;
    cout.setf(ios::fixed|ios::showpoint);
    cout.precision(3);
    cout<<"请输出工件的尺寸r1球半径，r2为圆柱体半径，l为长度："<<endl;
    cout<<setw(15)<<v<<endl;
    return 0;
}
 */
/*
#include <iostream>
#include <iomanip>   //iomanip
using namespace std;
int main()
{
    char char1,char2;
    int nchar1,nchar2;
    cout<<"输入任意字符"<<endl;
    cin>>char1>>char2;
    cout<<setw(5)<<char1;
    cout<<setw(5)<<char2<<endl;

    nchar1=static_cast<int>(char1);
    nchar2=static_cast<int>(char2);
    cout<<setw(5)<<nchar1;
    cout<<setw(5)<<nchar2<<endl;  //
    cout.unsetf(ios::dec);
    cout.setf(ios::oct);
    cout<<setw(5)<<nchar1<<setw(5)<<nchar2<<endl;

    cout.unsetf(ios::oct);
    cout.setf(ios::hex);
    cout<<setw(5)<<nchar1<<setw(5)<<nchar2<<endl;

    return 0;

}
 */
//输出格式可以变成不同进制间的转换，方法和函数是cout.setf（ios：：hex）hex为十六进制，oct为八进制
// 注意不能随便转化⚠️
//由于输入的是字符串，要将字符串转化为整形要求学会的是类型的强制转化，static_cast<A >(B),A为要转化的类型，B为要转化的变量
//在变量转化的时候还要注意cout.unsetf(ios：：）需要去掉前面的格式
//二进制是Binary，简写为B。
//八进制是Octal，简写为O。
//十进制为Decimal，简写为D。
//十六进制为Hexadecimal，简写为H。

/*#include<iostream>
#include <iomanip>
using namespace std;
int main()
{
    char char1,char2;
    int a,b;

    cin>>char1>>char2;
    a=static_cast<int>(char1);
    b=static_cast<int>(char2);
    cout.setf(ios::dec);
    cout<<setw(5)<<a<<setw(5)<<b<<endl;
    cout.unsetf(ios::dec);
    cout.setf(ios::oct);
    cout<<setw(5)<<a<<setw(5)<<b<<endl;
    cout.unsetf(ios::oct);
    cout.setf(ios::hex);
    cout<<setw(5)<<a<<setw(5)<<b<<endl;
    return 0;
}*/
//                    第二章
//              控制语句和循环语句的使用
//
//
//
/*目前我自己的循环水平
#include <iostream>
using namespace std;
int main()
{
    int x,sum=0;
    cin>>x;
    for(int i=0;i<x;i++)
        sum=sum+i;
        cout<<sum<<endl;
    return 0;
}
 */
/*#include <iostream>
using namespace std;
int main()
{
  int number;
  cin>>number;
  switch(number)
  {
      case 1:
          cout<<"选1"<<endl;
          break;
      case 2:
          cout<<"选2"<<endl;
          break;
      case 3:
          cout<<"选3"<<endl;
          break;
      default:
          cout<<"不选"<<endl;
  }
   return 0;
}
 */
//switch语句一定要和case和break搭配使用
//当出现选项之外的情况是default来表示。
/*#include <iostream>
using namespace std;
int main()
{
    int  a,b;
    cout<<"多少个hello oworld"<<endl;
    cin>>a;
    for(b=0;b<a;++b)
    {
        cout<<"hello world"<<endl;

    }
    return 0;
}*/
/*#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int letter_ctr,i;
    letter_ctr=0;
    for(i=65;i<91;++i)
    {
        cout<<setw(4)<<static_cast<char>(i);
        letter_ctr++;
        if(letter_ctr==)
        {
            cout<<endl;
            letter_ctr=0;
        }
    }
   return 0;
}*/
//对26个英文字母的输出，在其中需要注意的是将int型转化为char型，int对应的数值就是char的ascii码值
//输出是还需要注意列数的限制循环从而达到标准输出
/*#include <iostream>
#include <string>
using namespace std;
int main()
{
    string answer="yes";
    while(answer=="yes")
    {
        cout<<"xxxxxxxxx"<<endl;
        cout<<"xxxxxx"<<endl;
        getline(cin,answer);
    }
    cout<<"xxx"<<endl;
    return 0;

}
 */
/*#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a;
    b=0;
    while(b<a)
    {
        cout<<"hello world"<<endl;
        b++;

    }
    return 0;
}
while循环的使用方法
 */
/*#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    string answer;
    cout<<"这是我的诗";
    do
    {
        cout<<"xxxxxx"<<endl;
        getline(cin,answer);
    }while(answer=="yes");
        cout<<"你喜欢吗"<<endl;
    return 0;
}*/
//do while的使用方法，while是判断语句如果达到while的条件则do继续循环，如果不满足while的条件则跳出循环
/*
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string password;
    cout<<"请输入密码：";
    cin>>password;
    for(int i=0;i<5;++i)
    {
        getline(cin,password);
        if(password=="letmein")
            break;
    }
    return 0;
}
*/
//密码输入和匹配不完全
/*#include <iostream>
#include <cmath>  //运用fabs函数（绝对值函数）
using namespace std;
int main()
{
    float a=static_cast<float>(0.0);
    float b=static_cast<float>(0.05);
    float c=static_cast<float>(1.00);
    for(int i=0;i<20;++i)
    {
        a=a+b;
    }

    if(a==c)
    {
        cout<<"first check:sum is $1.00";
    }
    else
    {
        cout<<"fist check:sum is not $1.00";
    }
    if(fabs(a-c)<0.000001)
    {
        cout<<"second check:sum is $1.00"<<endl;
    }
    else
    {
        cout<<"second check:sum is not $1.00"<<endl;
    }
    return 0;
}
 //cin与getline的区别在对字符串输入的时候，cin会把空格当成下一个输入元素输入到变量之中，作为cin的停止标志位
 //而getline在下程序中就把空格当作输入的字符串处理，
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
    int a;
    string color;
    cin>>a;
    getline(cin,color);
    cout<<a<<" "<<color<<endl;
    return 0;
}
 */
//                       c++类与vector类
// c++提供的是标准模版库，包含了大量的类
// vector类可供程序员随时进行访问和使用
// vector是动态增长的，不用担心对其的内存消耗
//
/*#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main()
{
    vector<int>vmnms;
    cout<<"\n demonstration of c++ vector \n";
    vmnms.push_back(35);
    vmnms.push_back(99);
    vmnms.push_back(27);
    vmnms.push_back(3);
    vmnms.push_back(54);
    cout<<"元素个数"<<vmnms.size();
    vmnms.push_back(15);
    vmnms.push_back(72);
    cout<<"加两个元素个数"<<vmnms.size()<<endl;
    cout<<"输出全部元素"<<endl;
    for (int i=0;i<vmnms.size();++i)
    {
        cout<<setw(5)<<vmnms.at(i)<<endl;
    }
    return 0;
}
 */
//这里讲述了vector函数的用法，vector<int>vmnms;比如vmnm.push（）是将数据输入到函数库里面，vmnm为函数的名字
//这里的调用push和输出的at都是函数vector必要的，还有size计算函数的长度
//cin.ignore()函数将会忽虐（）内的信息
/*
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
    int nterms; double pi=3.1415926535;
    double numerator,denom;
    double picalc;
    string answer;
    cout<<"\n pi calculation progream\n";
    do{
        cout<<"\n enter number of terms for pi calculation:";
        cin>>nterms;
        cin.ignore();
        picalc=0.0;
        numerator=4.0;
        denom=1.0;
        for(int i=0;i<nterms;++i)
        {
            picalc=picalc+numerator/denom;
            numerator=-1.0*numerator;
        }
        cout<<"\n result \n number of terms:"<<nterms<<setprecision(10)<<"pi = "<<pi<<
        "calc oi"<<picalc<<endl;
        cout<<"\n do more pi calation ? yes/no";
        getline (cin,answer);
    }while(answer=="yes");

    return 0;
}
 */
//
//随机生成数函数
//
///
//
//rand（）伪随机生成数函数，返回0——max_rand之间的一个整数。srand（）函数的整形参数作为种子，种子能设置随机数的生成起点，
// 和srand（）包含在cstilb库中
/*#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;
int main()
{
    cout<<"\n random number cenerator demo";

    int seed,number,i;
    string answer;

    cout<<"\n\n first ,here are 8 random number."<<"\n we used the time function for seed value.\n";
    //将系统时间作为种子，观察随机算
    srand(unsigned(time(NULL)));
    for( i=0;i<8;++i)
    {
        number=rand();
        cout<<setw(8)<<number<<endl;
    }
    cout<<"\n now we well let you choose the seed value.";
    do
    {
        cout<<"\n\n please enter a seed value for rand()";
        cin>>seed;

        cin.ignore();
        srand(seed);

        cout<<"\n eight number with"<<seed<<endl;
        for(i=0;i<8;++i)
        {
            number=rand();
            cout<<setw(8)<<number;
        }
        cout<<"\n do another set of number? yes/no";
        getline(cin,answer);
    }while(answer=="yes");
    return 0;
}
*/
//c++的随机生成方法一
/*#include <iostream>
#include <random>
using namespace std;

constexpr int MIN = 1;
constexpr int MAX = 100;

constexpr int RAND_NUMS_TO_GENERATE = 10;

int main() {
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(MIN, MAX);

    for (int n = 0; n < RAND_NUMS_TO_GENERATE; ++n) {
        cout << distr(eng) << "; ";
    }
    cout << endl;
    return 0;
}
*/
/*#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
int main()
{
    cout<<"\n 随机数生成"<<endl;
    srand((unsigned)time(NULL));
    int number;
    cout<<"产生0-6之间的随机数";
    for(int i=0;i<10;++i)
    {
        number=rand()%7;  //rand()会产生随机整数，让随机的整数%7得到的余数就是0——6之间的随机数
        cout<<setw(5)<<number;
    }
    cout<<"\n\n 规定限制在0——1。000之间的随机数"
    <<"\n integers between 0 -1000,and divide by 10000. \n";
    double random;
    cout.precision(3);
    cout.setf(ios::fixed);
    for(int i=0;i<10;++i)           //随机数范围和个数控制
    {
        number =rand()%1001; //现将随机数控制在0——1000内
        random=number/1000.0; //再将函数缩放在0-1之间就行
        cout<<setw(7)<<random;
    }
    cout<<"\n\n产生-25到25之间的随机数"<<"\n and subtract 25.\n";
    for(int i=0;i<10;++i)
    {
        number=rand()%51; //先随机生成数，再控制再0-50的随机数
        number=number-25; //将他们全部左移25个到了-25到25的随机数
        cout<<setw(5)<<number;
    }
    cout<<"\n\n 随机数输出完成"<<endl;
    return 0;
}
*/
//随机数的生成库可以是别的，但是大多数是srand((unsigned)time(NULL))，用系统时间作为随机数生成点
//然后把生成的随机数进行相对应的操作时期满足锁需要的随机数范围就行，大多利用取余和倍数缩放
//除此之外随机数个数的生成也需要一个for 循环来实现
/*#include <iostream>   //简单的随机数生成
#include <iomanip>
using namespace std;
int main()
{
    int a;
    srand((unsigned)time(NULL));
    for(int i=0;i<5;++i)
    {
        a=rand();
        cout<<a<<" ";

    }

    return 0;
}
*/
//      vector函数库的运用就和数据库的表差不多，用于数据的录入和读取
//       vector自带的数据录入格式为：vector<int,float,double,string>变量名；
//        数据录入格式：变量名.push_back("内容");
//         下面代码设置了index来搜索库内的信息
//          如果想多次搜索和查询可以运动do while函数在while结尾给出判断循环条件
/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    vector<string>names;
    vector<string>origins;    //参数定义
    names.push_back("张三");
    origins.push_back("1geek,meaning stranger");

    names.push_back("里斯");
    origins.push_back("2geek,meaning stranger");

    names.push_back("刘飞");
    origins.push_back("3geek,meaning stranger");

    names.push_back("刘翔");
    origins.push_back("4geek,meaning stranger");

    names.push_back("王二麻子");
    origins.push_back("5geek,meaning stranger");

    names.push_back("猪头三");
    origins.push_back("6geek,meaning stranger");  //数据录入

    string answer,username;     //姓名搜索
    do{
        bool bdidnotfindit=true;
        cout<<"输入名字"<<endl;
        getline(cin,username);
        int index=0;     //设置index相当于指针对库内的录入数据和输入的对比，当相同时就可以输出信息
        while(index<names.size()&& bdidnotfindit==true)
        {
            if(username==names.at(index))
            {
                cout<<"名字是"<<names.at(index)<<" ";
                cout<<origins.at(index);
                bdidnotfindit=false;
            }
            else
            {
                ++index;
            }
        }
        if(bdidnotfindit)
        {
            cout<<"名字不在库中"<<endl;
        }
        cout<<"还需要查询吗? 是/否";
        getline(cin,answer);
        cin,ignore;
    }while(answer=="是");
    return 0;
}
 */
//char 可以定义符号，输入符号什么的
//
/*
#include <iostream>
using namespace std;
int main()
{
    int choice,hr,min,sec,totalsec;
    char colon;
    cout<<"时间进制转化问题"<<endl;
    do
    {
        cout<<"\n1.小时化秒"<<"\n2、秒化小时"<<"\n3.退出"<<"输入选项"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"输入时:分:秒"<<endl;
                cin>>hr>>colon>>min>>colon>>sec;
                if(hr>24 ||min>60 ||sec>60)
                {
                    cout<<"输入有误"<<endl;
                    break;
                }
                else
                {
                    totalsec=hr*3600+min*60+sec;
                    cout<<totalsec<<endl;
                    break;
                }
            case 2:
                cout<<"输入秒"<<endl;
                cin>>totalsec;
                hr=totalsec/3600;
                totalsec=totalsec-hr*3600;
                min=totalsec/60;
                totalsec=totalsec-min*60;
                sec=totalsec;
                cout<<"时间是"<<hr<<":"<<min<<":"<<sec<<endl;
                break;
            case 3:
                cout<<"退出程序"<<endl;
                break;
            default:
                cout<<"输入有误"<<endl;
        }
    }while(choice!=3);
    return 0;
}
 */

//xuanhuantaoyufa1
/*#include <iostream>
#include <string>
#include <cctype>   //提供同tolower（）。ispunct（）和isspace（）
using namespace std;
int main()
{
    cout<<"筛选元音字母的程序";
    string answer="yes";
    string sentence;
    char letter;
    int acount,ecount,icount,ocount,ucount;
    int puncount,spacecount;
    while(answer=="yes")
    {
        acount=ecount=icount=ocount=ucount=0;
        puncount=spacecount=0;
        cout<<"输入压迫斯艾轩的句子"<<endl;
        getline(cin,sentence);
        for(int i=0;i<sentence.size();++i){
            letter=sentence.at(i);
            letter=tolower(letter);
            switch (letter)
            {
                case 'a':
                    acount++;
                    break;
                case'e':
                    ecount++;
                    break;
                case'i':
                    icount++;
                    break;
                case'o':
                    ocount++;
                    break;
                case'u':
                    ucount++;
                    break;
            }
            if(ispunct(letter)!=0)
                puncount++;
            if(isspace(letter)>0)
                spacecount++;
        }
        cout<<"句子"<<sentence<<endl;
        cout<<"a"<<"  "<<acount<<endl;
        cout<<"e"<<"  "<<ecount<<endl;
        cout<<"i"<<"  "<<icount<<endl;
        cout<<"o"<<"  "<<ocount<<endl;
        cout<<"u"<<"  "<<ucount<<endl;
        cout<<"punctcount"<<"  "<<puncount<<" "<<"spacecount"<<"  "<<spacecount<<endl;
        cout<<"还需要别的句子分析吗？是/否";
        getline(cin,answer);
    }
    return 0;
}
*/
//编写输入一段数字，筛选每个位置的奇偶数量
/*
#include <iostream>
#include <string>
#include <cctype>   //提供同tolower（）。ispunct（）和isspace（）
using namespace std;
int main()
{
    string sentence;
    int scount,dcount,a;
    cout<<"输入一串数看有几位奇数几为偶数"<<endl;
    cin>>sentence;
    for(int i=0;i<sentence.size();++i)
    {
        a=sentence.at(i)%2;
        switch (a)
        {
            case 0:
                dcount++;
                break;
            case 1:
                scount++;
                break;
        }
        cout<<i<<endl;
    }
    cout<<"奇数"<<scount<<endl;
    cout<<"偶数"<<dcount<<endl;
    return 0;
}
*/
/*#include <iostream>
#include <vector>
#include<string>
int main()
{
    vector<int>pumps;
    string answer;
    pumps.push_back(350);
    pumps.push_back(600);
    pumps.push_back(950);
    pumps.push_back(1200);
    pumps.push_back(1600);
    pumps.push_back(2500);
    pumps.push_back(3200);
    pumps.push_back(5000);
    int w,d,l;
    do
    {
        cin>>l>>w>>d;
        cin.ingore();
        int v=w*l*d;
        float G=v/231.0;
        cout<<G<<endl;
        int cap=G*2.0;
        int numpumps=pumps.size();
        int index;
        bool bgoodfit=true;
        if(cap<pumps.at(0)) {
            index = 0;
            if (cap < pumps.at(0) / 3) {
                bgoodfit = false;
            }
        }
            else if(cap>pumps.at(numpumps-1))
            {
                index=numpumps-1;
                bgoodfit=false;
            }
            else
            {
                for(int i=0;i<numpumps-1;++i)
                {
                    if(cap>pumps.at(i)&&cap<pumps.at(i+1))
                    {
                        index=i+1;
                        break;
                    }
                }
            }
            if(bgoodfit==true)
            {
                cout<<"你需要买的pump大小"<<pumps.at(index)<<endl;
            }
            else
            {
                cout<<pumps,at(index)
            }
            cout<<"真的假的？"<<endl;
            getline(cin,answer);
        }
    }while(answer=='yes');
return 0;
}
 */
//                第四章  函数
// c++包含很多个函数，但是只有一个main函数，可以有多个子函数，包含在main函数中间
//出了主函数以外还有库函数，在头文件里面，还有自定义函数，和类
//首先要对函数进行声明
//函数要进行编辑和定义
//函数的调用和返回
//自定义函数是  a   b（c）； a是返回值类型或者不返回值void，b是自己对函数的命名（）内是函数的自变量类型声明，c为函数的输入数据
//当c=0是就是不输入信息的函数
/*编写函数来进行信息的录入
#include <iostream>
using namespace std;
void writehello();
string askname();     //返回值的类型是string类型的名字
int askage();         //返回值的类型是int年龄
void write(string name,int age);
int main()
{
    int age;
    string name;
    writehello();
    name=askname();
    age=askage();
    write(name,age);
    return 0;

}
void writehello()
{
    cout<<"你好这是一个信息录入信息函数"<<endl;
}
string askname()
{
    string name;
    cout<<"输入名字"<<endl;
    getline(cin,name);
    return name;
}
int askage()
{
    int age;
    cout<<"输入年龄"<<endl;
    cin>>age;
    return age;
}
void write(string name,int age)
{
    cout<<"名字是:"<<name<<"  "<<"年龄："<<age<<endl;

}
*/
//    编写函数来实现旅馆问题
//编写函数来计算旅馆住宿问题
//
//
/*
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
void writegreen();   //问候语句表面函数用途
int howmanypeople();  //人数统计
int howmuch();  //住几晚上
string room();  //啥类型的房子
float calccost(int people,int night,string roomtype);  //计算总花费
void summary(int people,int night,string roomtype,float cast);  //输出所有的信息
int main()
{
    int people,night;  //定义输入人数，几晚，总花费
    float cast;
    string roomtype;   //房间类型

     writegreen();
    people=howmanypeople();  //调用人数函数；
    night=howmuch();   //调用住几晚函数
    roomtype=room();   //调用房间类型函数

    cast=calccost(people,night,roomtype);  //调用计算总开销函数
    summary(people,night,roomtype,cast);  //调用输出函数
    return 0;
}
int howmanypeople()      //录入人数
{
    int num;
    cout<<"多少个人？"<<endl;
    cin>>num;
    return num;
}
int howmuch()        //录入住几晚上
{
    int nig;
    cout<<"住几晚上？"<<endl;
    cin>>nig;
    cin.ignore();
    return nig;
}
string room()      //用vector储存房间类型，并且选择房间
{
    vector<string>vrooms;
    vrooms.push_back("小房子");
    vrooms.push_back("中房子");
    vrooms.push_back("大房子");
    cout<<"什么类型的房子"<<endl;
    for(int i=0;i<vrooms.size();++i)
        cout<<i+1<<vrooms.at(i)<<endl;
    cout<<"输入你的房间"<<endl;
    int whichone;
    cin>>whichone;
    cin.ignore();
    return vrooms.at(whichone-1);
}
float calccost(int people,int night,string roomtype)   //计算房间总花销
{
    float coast,rate;
    float addpresoncost=static_cast<float>(0.0);
    if(people>1)
        addpresoncost=static_cast<float>(10.00)*(people-1);
    if(roomtype=="大房子")
        rate=static_cast<float>(69.95);
    else if(roomtype=="中房子")
        rate=static_cast<float>(79.95);
    else if(roomtype=="小房子")
        rate=static_cast<float>(99.95);
    coast=(rate+addpresoncost)*night;
    return coast;
    //也可以替换为return (rate+addpresoncost)*night；
    //因为coast=(rate+addpresoncost)*night;
}
void writegreen()  //问候函数
{
    cout<<"欢迎来到订房app:"<<endl;

}
void summary(int people,int night,string roomtype,float cast)   //输出·订房信息
{
    cout.setf(ios::fixed);
    cout.precision(2);
    cout<<"订购一个信息，人数"<<people<<"几晚"<<night<<"房间类型"<<roomtype<<"总花费"<<cast<<endl;

}
*/
//好的编程方法是将主函数写出来，然后再在主函数里面添加附属函数来做到实现程序的作用
//1、函数是干嘛的
//2、为了完成函数，要给它那些值
//3、返回值的类型

//main函数不需要原型，操作系统会自动寻找程序中的main（）；
/*
#include <iostream>
#include <iomanip>
using namespace std;
int sum(int i);    //对求前n个和的子函数定义
void green();     //问候子函数
int main()      //祝函数
{
    int n,he;
    green();    //调用问候子函数
    cin>>n;
    he=sum(n);   //调用求和子函数
    cout<<"输出1+2+3+...+"<<n<<endl;  //输出
    cout<<he<<endl;
    return 0;
}
void green()     //问候子函数
{
    cout<<"这是个输出一个数求前n和"<<endl;
}
int sum(int s)    //求和子函数
{
    int n;
    for(int i=0;i<=s;i++)
    {
        n=n+i;
    }
    return n;
}
 */
/*
#include <iostream>
#include <string>
using namespace std;
void wenhou();
int askage();
string askname();
void xiechu(string name,int age);
int main()
{
    int age;
    string name;
    wenhou();
    name=askname();
    age=askage();
    xiechu(name,age);
    return 0;
}
void wenhou()
{
    cout<<"这是用来写姓名和年纪的程序："<<endl;
}
string name()
{
    string name;
    cout<<"输入名字"<<endl;
    getline(cin,name);
    cin.ignore();
    return name;
}
int age()
{
    int age;
    cout<<"输入年纪；"<<endl;
    cin>>age;
    return age;
}
void xiechu(string name,int age)
{
    cout<<"姓名"<<name<<"  "<<"年纪"<<age;
}
*/
//                函数重载 （函数名相同，但是输入列表不同的函数）
////试想如果没有函数重载机制，如在C中，你必须要这样去做：为这个print函数取不同的名字，如print_int、print_string。
/// 这里还只是两个的情况，如果是很多个的话，就需要为实现同一个功能的函数取很多个名字，如加入打印long型、char*、各种类型的数组等等。这样做很不友好！
////类的构造函数跟类名相同，也就是说：构造函数都同名。如果没有函数重载机制，要想实例化不同的对象，那是相当的麻烦！
////操作符重载，本质上就是函数重载，它大大丰富了已有操作符的含义，方便使用，如+可用于连接字符串等！
//我们还漏了函数重载的重要限定——作用域。上面我们介绍的函数重载都是全局函数，下面我们来看一下一个类中的函数重载，用类的对象调用print函数，并根据实参调用不同的函数：
//现在已经解决了重载函数命名冲突的问题，在定义完重载函数之后，用函数名调用的时候是如何去解析的？为了估计哪个重载函数最适合，需要依次按照下列规则来判断：
//
//精确匹配：参数匹配而不做转换，或者只是做微不足道的转换，如数组名到指针、函数名到指向函数的指针、T到const T；
//提升匹配：即整数提升（如bool 到 int、char到int、short 到int），float到double
//使用标准转换匹配：如int 到double、double到int、double到long double、Derived*到Base*、T*到void*、int到unsigned int；
//使用用户自定义匹配；
//使用省略号匹配：类似printf中省略号参数
//如果在最高层有多个匹配函数找到，调用将被拒绝（因为有歧义、模凌两可
//通常为了完整性而实现一系列的函数重载，但不是全部运用在程序里面
/*
#include <iostream>
#include <string>
using namespace std;
void saygoodnight();
void saygoodnight(string name1);
void saygoodnight(string name1,string name2);
void saygoodnight(int number);
int main()
{
    saygoodnight();
    saygoodnight("bob");
    saygoodnight("susan","mesie");
    saygoodnight(5);
    return 0;
}
void saygoodnight()
{
    cout<<"good night"<<endl;
}
void saygoodnight(string name1)
{
    cout<<"说goodnight对"<<name1<<endl;

}
void saygoodnight(string name1,string name2)
{
    cout<<"说goodnight对"<<name1<<" "<<name2<<endl;
}
void saygoodnight(int number)
{
    for(int i=0;i<number;i++)
        cout<<"goodnight"<<endl;
}
 */
//1、声明/定义重载函数时，是如何解决命名冲突的？（抛开函数重载不谈，using就是一种解决命名冲突的方法，解决命名冲突还有很多其它的方法，这里就不论述了）
//2、当我们调用一个重载的函数时，又是如何去解析的？（即怎么知道调用的是哪个函数呢）
//
//
/*
#include <iostream>
using namespace std;
void drawlines(char symbol='&',int numofsymbols=25,int numoflines=1);    //定义函数，当有定义值时
int main()
{
    drawlines();   //当存在定义值时直接输出25个& 1行
    drawlines('a',30);  //重新定义，输出30个a 1行
    drawlines('%',15,3); //暑促15个 % 要3行
    drawlines('#',6);  //输出6个# 1行
    return 0;
}
void drawlines(char symbol,int numofsymbols,int numoflines)    //重载不同的输入值，然后输出不同的值
{
    int i,j;
    for(i=0;i<numoflines;i++)
    {
        for(j=0;j<numofsymbols;j++)
        {
            cout<<symbol;
        }
        cout<<endl;
    }
}
*/
//局部变量和全局变量和静态变量
//变量范围，在程序运行中，变量存在时间的长度，它决定了变量对程序那部分是可见的和可访问的
//局部变量，在函数内部或函数头部声明的变量，只存在函数的内部
//块范围，在{}内声明的变量
//全局变量可以用来保存文件指针和流
/*
#include <iostream>
#include <string>
using namespace std;
void writehello();
void askforname();
void askforage();
void write();
int age;
string name;
int main()
{
    writehello();
    askforname();
    askforage();
    write();
    return 0;
}
void writehello()
{
    cout<<"hello c++"<<endl;
}
void askforname()
{
    cout<<"输入名字"<<endl;
    cin>>name;
    cin.ignore();

}
void askforage()
{
    cout<<"输入年纪"<<endl;
    cin>>age;
}
void write()
{
    cout<<name<<" "<<age<<endl;
}
*/
//静态变量，该变量的值能保留到程序结束
/*
#include <iostream>
#include <string>
using namespace std;
float howmuch();
int main()
{
    float total;
    string answer="yes";
    cout.precision(2);
    cout.setf(ios::fixed);
    while(answer=="yes")
    {
        total=howmuch();
        cout<<total<<endl;
        cout<<"是否继续？ yes/no"<<endl;
        getline(cin,answer);
    }
    cout<<total<<endl;
    return 0;
}
float howmuch()
{
    static float total=static_cast<float>(0.0);   //设置静态变量static
    float amount;
    cout<<"输出数量"<<endl;
    cin>>amount;
    cin.ignore();
    total=total+amount;
    return total;
}
 */
//一次结果会和下次输入想关联，多和循环函数有关
//     c++stringstream类
//字符串和数字类时，需要stringstream类，添加头文件<sstream>;
//istringstream、ostringstream 和 stringstream，分别用来进行流的输入、输出和输入输出操作。本文以 stringstream 为主，介绍流的输入和输出操作。
//由于 <sstream> 使用 string 对象来代替字符数组（snprintf 方式），避免了缓冲区溢出的危险；而且，因为传入参数和目标对象的类型会被自动推导出来，所以不存在错误的格式化符号的问题。
/*
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    cout<<"欢迎来到sstream程序"<<endl;
    double pi=3.1415926535;
    float dollar=1.00;
    int dozen=12;

    string text;
    stringstream ss;

    ss<<dozen<<endl;
    ss.setf(ios::fixed);
    ss.precision(2);
    ss<<dollar<<endl;
    ss.precision(10);  //精确到小数点后几位

    ss<<pi<<".";
    text=ss.str();  //将ss中的内容赋给一个string对象，使用str（）函数str（）函数就是自带的格式
    cout<<text<<endl;  //所有的信息存在了str（）内部，再将str（）给text就得到了
    return 0;
}
 */
//输出的precision（）函数是用来控制小树点个数的
/*
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
int main()
{
    stringstream sstream;

    // 将多个字符串放入 sstream 中
    sstream << "first" << " " << "string,";
    sstream << " second string";             //输入两个字符串进入sstream中
    cout << "结果是: " << sstream.str() << endl;   //用str（）输出sstream内的字符串合集

    // 清空 sstream
    sstream.str("");   //将字符串库内的内容清零
    sstream << "third string";    //再输入字符串3
    cout << "清空以后: " << sstream.str() << endl;
    return 0;
}
*/
//1、每一个函数必须有函数的原型和函数定义，即函数的实现代码
//2、函数的原型与函数的标题行基本相同，包含函数的返回值，输入参数的类型以及输入参数的声明
//3、函数调用的语句是程序中函数被实际调用的地方
//4、函数调用只需要是指定传递的参数变量名，而不需要指定类型变量的类型；
//5、如果一个函数有返回值需要将返回值赋给一个已经定义的变量之中
//6、函数可以被重载，函数名可以相同，输入参数可以不同
//7、全局变量在源文件中所有函数之外声明，对于所有的函数都可见
//8、熟悉不同变量对函数的作用位子
/*
#include <iostream>
#include <string>
using namespace std;
int shuru();    //输入函数
bool prime(int number);
bool check(int number);
int main()
{
    int n;
    string answer;
    do{
    n=shuru();
    bool result=prime(n);
    if (result==true)
    {
        cout<<"奇数"<<endl;
    }
    else
    {
        cout<<"偶数"<<endl;
    }
    cout<<"继续吗？ yes/no"<<endl;
    getline(cin,answer);
    }while(answer=="yes");
    return 0;
}
int shuru()
{
    int num;
    bool ok;
    do
    {
        cin>>num;
        cin.ignore();
        ok=check(num);
        if(ok==false)
        {
            cout<<"需要重新输入；"<<endl;
        }
    }while(ok==false);
    return num;
}
bool check(int number)
{
    if(number<=0)
        return false;
    else
        return true;
}
bool prime(int number)
{
    int remainder,ctr=2;   //从2到n-1循环
    while(ctr<number)
    {
        remainder=number%ctr;
        if(remainder==0)
        {
            return false;
        }
        ctr++;
    }
    return true;
}
*/
/*
 基础计算pi的程序
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;


int shuru();
double jisuan(int number);
string jieguo(double pi,double zhenpi,int number);

int main()
{
    int number;
    double pi=3.141592653589793;
    double zhenpi;
    string reslut,answer;
    do
    {
        number=shuru();
        zhenpi=jisuan(number);
        reslut=jieguo(pi,zhenpi,number);
        cout<<reslut<<endl;
        cout<<"是否继续 yes/no？"<<endl;
        getline(cin,answer);
    }while(answer=="yes");
    return 0;
}
int shuru()
{
    int n;
    cout<<"push a nuber for cycle"<<endl;
    cin>>n;
    cin.ignore();
    return n;
}
double jisuan(int number)
{
    double zhenpi=0.0;
    double numerator=4.0,demo=1.0;
    for(int i=0;i<number;i++)
    {
        zhenpi=zhenpi+numerator/demo;
        demo+=2.0;
        numerator=-1.0*numerator;
    }
    return zhenpi;
}
string jieguo(double pi,double zhenpi,int number)
{
    stringstream pistring;
    pistring.setf(ios::fixed);
    pistring<<number<<"  "<<setprecision(10)<<pi<<"  "<<zhenpi<<endl;
    return pistring.str();
}
*/
//学会头文件的创建和书写，以及调用
//              指针和数组
//地址&。当创建诸如char，short和float的变量时，将为该变量分配足够的空间来容纳该变量数据类型的值。
// 例如，char的一个字节，shorts的两个字节和int的4字节是常见的。
// 存储器的每个字节都有一个唯一地址，变量的指定地址是信息的第一个字节存储的位置。       计算机&的地址一般是32位的
//取子长sizeof
//指针有两种使用情况，对于数组必须要使用，对于堆栈操作。其次是当程序要进行动态内存分配（在程序运行是为其分配空间）是要用到指针
//第一步，指针变量的定义
//第二步，指向首地址
//第三步，进行相关操作
//
//
/*
#include <iostream>
using namespace std;
int main()
{
    int a,b;
    double c,d;
    char n,m;

    cout<<&a<<" "<<&b<<endl;
    cout<<&c<<" "<<&d<<endl;
    cout<<&n<<" "<<&m<<endl;

    return 0;
}
 */
/*
#include <iostream>
using namespace std;
int main()
{
    int *p,a[]={1,2,3,4,5};   //定义一个指针和一个数组
    p=a;
    while(p<a+5)
    {
        cout<<*p<<endl;
        p++;
    }

}
*/
/*
#include <iostream>

using namespace std;

int main() {
    int a = 10;
    int d[]={1,2,3};
    double b;
    b = a;
    cout << &b << endl;
    cout<< &a<<endl;
    int *p;     //定义指针*p
    p=&a;       //对指针*p是指向地址p的对应结果
    int *c;
    c=d;     //d为数组的受地址和变量不同，变量得要把地址给p而数组不需要；
    cout<<*p<<endl;
    cout<<*c<<endl;
   //使用指针不需要返回值，指向结果就是得到的数据
}
*/
/*
#include <iostream>
using namespace std;
int main()
{
    int *p,a[]={1,2,3,4,5,6,7,8,9};
    int sum=0;
    p=a;
    */
/* 方法一求和
 for(int i=0;i<9;i++)
 {
     sum=sum+*(p+i);
 }
 cout<<sum<<endl;
 */
/*方法二求和
 while(p<a+9)
 {
     sum=sum+*p;
     p++;
 }
 cout<<sum<<endl;
 */
/*
 return 0;
}
*/
// 数组移动的写法
/*
#include <iostream>
using namespace std;
void mobe(int a[],int n,int m);
int main()
{
    int a[10]={1,2,3,4,5,6,7,9,0};
    mobe(a,10,4);
    for(int i=0;i<9;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}
void mobe(int a[],int n,int m)
{
    int i,j,k;
   for(i=0;i<=m;i++)      //移动m个数要做的操作
   {                    //移动一个数要做的操作
       k=*(a+n-1);
       for(j=n-2;j>=0;j--)
       {
           *(a+j+1)=*(a+j);
       }
       *a=k;
   }
}
*/
/*
#include <iostream>
#include <stdio.h>    //为了使用gets（）来读取字符串
using namespace std;
int strin(char *p);
int main()
{
    char c[20];          //定义一个字符串长为20
    cout<<"输入字符串:"<<endl;
    int len;     //定义长度
    gets(c);     //读取字符串
    len=strin(c);    //调用测长函数来测试字符串长度
    cout<<len<<endl;
    return 0;
}
int strin(char *p)    //读取进去的是字符串指向的指针
{
    int len=0;
    while(*p!='\0')      //字符串非空时len++
    {
        len++;
        p++;
    }
    return len;
}
*/
//    字符串转换问题，输入一串字符串，例如32jjjdja2323？dwdw里面的32和2323就放入数组a中记为a【0】和a【1】；
//1、字符的123和123不一样，差了48需要减去48，存储为ascii码存储
//
/*
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int shuru(char b[30],int a[20]);
int main()
{
    int a[20]={0},num,i;
    char b[30];
    cin>>b;
    num=shuru(b,a);
    for(i=0;i<=num;i++)
        cout<<a[i]<<endl;
    return 0;
}
int shuru(char b[30],int a[20])
{
    int num=0,flag=0;      //num可以规定输出的数组范围
    char *p;
    for(p=b;*p!='\0';p++)    //循环来判断
    {
        if(*p>='0'&&*p<='9')   //条件一是否是0-9之间的数
        {
            if(flag==1)    //条件二是否是单独的整数
            {
                num++;
                flag=0;
            }
            a[num]=a[num]*10+*p-48;
        }
        else
            flag=1;
    }
    return num;     //返回搜索到的数
}
*/
//字符串比较问题
/*
#include <iostream>
#include <string>
using namespace std;
int panbie(char *a,char *b);
int main()
{
    char a[20];char b[20];
    cin>>a>>b;

    int i;
    //指向a，b数组
    i=panbie(a,b);  //调用对比函数
    if(i==0)
    {
        cout<<"一样长"<<endl;
    }
    else if(i>0)
    {
        cout<<"a长"<<endl;
    }
    else
    {
        cout<<"b长"<<endl;
    }
    return 0;
}
int panbie(char *a,char *b)    //对比长度函数，将数组a，b的指针拿出来操作
{
    while(*a!='\0'&&*b!='\0'&&*a==*b)
    {a++;b++;}
    if(*a=='\0'&&*b=='\0')
        return 0;
    else
        return *a-*b;
}
*/
/*a.size();
//sizeof();不一样
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a;
    string b;
    getline(cin,a);
    cin.ignore();
    getline(cin,b);

    cout<<a.size()<<"  "<<b.size();

    return 0;
}
*/
//用指针来找数组中最大数
/*
#include <iostream>
using namespace std;
int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,0},max;
    int *p;
    p=a;
    max=*p;
    for(int i=0;i<10;i++)
    {
        if(*p>max)
            max=*p;
        p++;
    }
    return max;
}
 */
/*
#include <iostream>

using namespace std;

int main() {
    int a[10][10],i,j;
    for ( i = 0; i < 10; i++)    //矩阵a[i][0]=1;a[i][i]=1;
    {
        a[i][0] = 1;
        a[i][i] = 1;
    }
    for ( i = 2; i < 10; i++)        //计算别的位置上的值
        for (j = 1; j < i; j++) {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];   //由上一层左右两个和构成
        }
    for (i = 0; i < 10; i++) {
        for (j = 0; j <=i; j++) {
            cout << a[i][j] <<"  ";      //输出矩阵
        }
        cout<<endl;
    }
    return 0;
}
*/
//求一个叔数组里面的行最大列最小对于的值
//找出行最大，找出列最大，
//对比行列同一个值就输出
/*
#include <iostream>

using namespace std;

int main() {
    int a[3][3] = {{1,   3,  2},
                   {-12, 23, 31},
                   {6,   5,  54}}, max, min, i, j,row,col;
   for(i=0;i<3;i++)
   {
       for(j=0;j<3;j++)
       {
          if(max<a[i][j])
          {
              col=j;
              max=a[i][col];
          }
       }
     min=a[i][col];
       for(j=0;j<3;j++)
           if(min>a[j][col])
           {
               min=a[j][col];
           }
       if(min==max)
       {
           cout<<max<<endl;
       }
   }
    return 0;
}
 */
/*
#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main()
{
    char str[3][20],sum1,sum2,sum3,i,j;
    sum1=sum2=sum3=0;
    for(i=0;i<3;i++)
    {
        cin>>str[i];
        cin.ignore();
    }
    for(i=0;i<3;i++)
    {
        j=0;
        while(str[i][j]!='\0')
        {
            if(str[i][j]>='A'&&str[i][j]<='Z')
                sum1++;
            else if(str[i][j]>='a'&&str[i][j]<='z')
                sum2++;
            else  if(str[i][j]>='0'&&str[i][j]<='9')
                sum3++;
            j++;
        }
    }
    cout<<sum1<<endl;
    cout<<sum2<<endl;
    cout<<sum3<<endl;
    return 0;
}
 */
//如果数目不对，可使用switch语句搜索
//来减小时间复杂度，空间附加度加大
//
//
//Queue容器允许从一端新增元素，从另一端移除元素。
//Queue容器中，只有队头和队尾允许访问，其余不允许访问
//队列进数据称为入队----push()
//队列出数据称为出队----pop()
//队列queue操作，先进先出，
//堆栈，后进先出
//queue<type> QueueName;		   //queue采用模板类实现构造，queue的默认构造形式
//queue(const queue & que);      //拷贝构造函数
//queue& operator=(const queue& que);    //重载等号操作符
/*push(elem);		//从队尾入对
pop();			//弹出队头元素
back();			//返回最后一个元素
front();		//返回队头元素
 empty();			//判断队列是否为空
size();				//返回队列的大小
 */
/*
#include <iostream>
#include <queue>    //调用队列
#include <string>
using namespace std;
int show();                           //做选择函数
void showline(queue<string>&rline);   //展示队列全部信息
void addline(queue<string>&rline);    //添加进入队列
void first(queue<string>&rline);      //为第一个入服务

int main()
{
    cout << "this is a c++ bank" << endl;
    queue<string> bankline;
    int choice = 0;
    while (choice != 4) {
        choice = show();
        switch (choice) {
            case 1:
                showline(bankline);
                break;
            case 2:
                addline(bankline);
                break;
            case 3:
                first(bankline);
                break;
        }
    }
    cout << "thanks " << endl;
    return 0;
}
int show()
{
    int choice;
    cout<<"1.show line"<<'\n'<<"2.add person"<<
        '\n'<<"3.server person "<<'\n'<<"4 exit"<<endl;
    cin>>choice;
    cin.ignore();
    return choice;
}
void showline(queue<string>&rline)
{
    int num=rline.size();
    if(num==0)
        cout<<"no one is in line"<<endl;
    else
        cout<<"there are "<<num<<"  "<<"people"<<",the first person is  "<<rline.front()<<endl;

}
void addline(queue<string>&rline)
{
    string name;
    cout<<"do you want add person in this line"<<endl;
    getline(cin,name);
    rline.push(name);
}
void  first(queue<string>&rline)
{
    if(rline.empty()==true)
        cout<<"the line is empty";
    else
    {
        cout<<"get in ";
        rline.pop();
    }
}
 */
//数据类型    double int 什么的
//数据所需字节数  不同类型占用的字节数
//变量名   double x 中的x
//地址   用&查看，在计算机ram内的物理地址
//变量值  x=多少的值
//指针和引用是被用来存储十六进制地址的
//用*运算符来声明一个指针，用&运算符来声明一个引用，是将&的取地址赋给指针，在指针函数运用时虽然是变量名，但是实际上是对地址的调用
/*#include <iostream>
using namespace std;
void askforxandy(int *px,int *py);
void askforxandy(int &rx,int &ry);
int main()
{
    int x,y;
    askforxandy(&x,&y);
    askforxandy(x,y);
    return 0;
}
void askforxandy(int *px,int *py)
{
    cout<<"enter x and y"<<endl;
    cin>>*px>>*py;
}
void askforxandy(int &rx,int &ry)
{
    cout<<"enter x and y"<<endl;
    cin>>rx>>ry;
}
*/
/*
#include <iostream>
#include <string>      //字符串应用
using namespace std;
int getnumber();      //获取数字的函数
bool check(int number);   //检测输入数字是否是符合要求的数字，不是素数的话进行prime函数进行分解
bool prime(int number,int &divisor);   //对规范的数进行分解，看是不是素数，。布尔型变量的值只有 真（true）和假（false）
int main()
{
    int number,divisor;
    string answer;
    do       //do循环可以多次使用程序
    {
        number=getnumber();    //将函数得到的数字复制给number
        bool result=prime(number,divisor);  //判断是不是素数
        if(result==true )
        {
            cout<<"是质数"<<endl;       //bool返回真值
        }
        else
        {
            cout<<"不是质数"<<'\n'<<divisor<<endl;    //bool返回假
        }
        cout<<"继续？ yes/no"<<endl;
        getline(cin,answer);
    }while(answer=="yes");     //循环条件，看用户是否还需要继续
    return 0;
}
int getnumber()     //输入函数
{
    int number;
    bool ok;
    do
    {
        cout<<"输入"<<endl;
        cin>>number;
        cin.ignore();
        ok=check(number);
        if(ok==false)
        {
            cout<<"因子是";
        }
    }while(ok==false);
    return number;
}
bool check(int number)        //判断输入的数是否为正数
{
    if(number<=0) return false;
    else
        return true;
}
bool prime(int number,int &divisor)    //判断正数是否为质数
{
    int remainder,ctr=2;
    divisor=1;
    while(ctr<number)       //判断条件是给定一个数a，b=2，a除以b看是否能整除，如果不行b++，直到a=b时，就说明a是质数，如果存在某一个b能整除以a，那么a就不是素数
    {
        remainder=number%ctr;
        if(remainder==0)
        {
            divisor=ctr;
            return false;
        }
        ctr++;
    }
    return true;
}
*/
/*
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
#define pi 3.1415926;
void asksome(double *h,double *r,string *simlie);
double tast(double v1,double v2);
int main()
{
    double h,r;
    double v;
    string flavor;
    cout<<"c++ programe"<<endl;
    asksome(&h,&r,&flavor);
    v=tast(h,r);
    cout.precision(1);
    cout.setf(ios::fixed| ios::showpoint);
    cout<<"the simlie is"<<flavor<<endl;
    cout<<r<<","<<h<<endl;
    cout.precision(3);
    cout<<"the simlie "<<flavor<<" ,"<<v<<endl;
    return 0;
}
void asksome(double *h,double *r,string *simlie)
{
    cout<<"sheng mo kou wei"<<endl;
    getline(cin,*simlie);
    cout<<"gao "<<endl;
    cin>>*h;
    cout<<"banjin "<<endl;
    cin>>*r;
    cin.ignore();
}
double tast(double r,double h)
{
    double v;
    v=pi*pow(r,2)*h/3.0+4.0/3.0*pi*pow(r,3);
    return v;
}
 */
/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "namefunction.h"     //调用编写好的头文件
int main()
{
    cout<<"欢迎开到c++搜索"<<endl;
    vector<string> names;     //定义vector类型专制的names，origins变量；
    vector<string> origins;
    fillvector(names,origins);    //调用函数fillvector，里面有两个参数names，origins
    string username,nameorigins,answer;    //变量定义
    bool bfoundit;    //bool型定义，
    do
    {
        username=askuserforname();    //输入函数
    bfoundit=searchforname(names,origins,username,nameoriginxs);   //查询函数
        if(bfoundit)
        {
            cout<<"有"<<username<<endl;
            cout<<nameorigins;
        }
        else
        {
            cout<<"sorry"<<endl;
        }
        cout<<"继续吗？yes/no?"<<endl;
        getline(cin,answer);
    }while(answer=="yes");
    return 0;
}
*/
/*
#include <iostream>
#include <string>
#include <iomanip>
#include "boatfunction.h"
using namespace std;
int main()
{
    write();        //问候函数
    string boattype;
    boattype=whatkind();     //选择船只类型
    int hours=rentalduration(boattype);  //选择租用时间
    float boatcost=coast(boattype,hours);   //计算船只的话费
    cout<<"船支类型是"<<boattype<<setprecision(2)<<setiosflags(ios::fixed)<<"组用时间是"<<hours<<"付款"<<boatcost<<endl;
    return 0;
}
 */
//结构体学习
//整形变量和浮点型变量的负值等号就可以实现
//字符数组的负值就需要strcpy来进行，字符串拷贝
//结构体变量的输出方法，变量名.要输出的值，例如stu1.name,输出结构体变量stu1的name
//
/*
#include <iostream>
#include <string>
using namespace std;
int main()
{
    struct student     //结构体定义
    {
        char name[20];
        int age;
        float score[5];
    };
    struct student stu1,stu2;    //定义结构体变量stu1
    strcpy(stu1.name,"liuliang");
    strcpy(stu2.name,"zhangsan");
    stu1.age=24;
    stu2.age=23;
    stu1.score[0]=stu1.score[1]=90;
    stu2.score[1]=stu2.score[2]=99;
    cout<<stu1.name<<","<<stu1.age<<","<<stu1.score[0]<<" ,"<<stu1.score[1]<<endl;
    cout<<stu2.name<<","<<stu2.age<<","<<stu2.score[2]<<" ,"<<stu2.score[1]<<endl;
    return 0;
}
 */
/*
//用结构体来计算时间是这一年的第多少天
#include <iostream>
using namespace std;
int main()
{
    struct day
    {
        int year;int month;int day;
    };
    struct day day1;
    int sum=0;
    int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};         //先按照普通年份计算
    cout<<"这是计算日期的c++机构体程序"<<"\n输入计算的时间"<<endl;
    cin>>day1.year>>day1.month>>day1.day;
    for(int i=1;i<=day1.month;i++)     //应用数组方法，计算月份对应的日期，但是注意-1，7月应该计算前6个月和7月的day之和
    {
        sum=sum+a[i-1];
        sum=sum+day1.day;
    }
    if(day1.year%4==0 && day1.year%100!=0 || day1.year%400==0)         //当year为闰年是需要sum+1多一天
        //润年判断标准可被4和100整除，或者能被400整除
    {
        sum=sum+1;
    }
    cout<<day1.year<<"年"<<day1.month<<"月"<<day1.day<<"日，是"<<sum<<"天"<<endl;
    return 0;
}
*/
/*
#include <iostream>
using namespace std;
int main()
{
    struct student
    {
        char name[20];
        int age;
        float score[3];
    };
    struct student stu[10];
    for(int i=0;i<10;i++)
    {
        cin>>stu[i].name>>stu[i].age>>stu[i].score[0];
    }
    for(int i=0;i<10;i++)
    {
        cout<<"第"<<i<<"个学生信息"<<stu[i].name<<stu[i].age<<stu[i].score[0]<<endl;
    }
}
*/
/*
#include "function.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
    writess();
    string results;
    float size,rate;
    int depth;
    depth=askdepth();
    size=asksize();
    rate=askrate();
    results=talkthev(depth,rate,size);
    cout<<results<<endl;
    return 0;
}
 */
/*
#include <iostream>
#include <string>
using namespace std;
int main()
{
    float phone_bills[12];
    float sum,ave;
    string month[12]={"jan","feb","mar","apr","may"
    ,"june","july","aug","sept","oct","nov","dec"};
    int i;
    for(i=0;i<12;++i)
    {
        cout<<"输入每个月的话费"<<month[i]<<"$";
        cin>>phone_bills[i];
    }
    sum=0.0;
    for(i=0;i<12;++i)
    {
        sum=sum+phone_bills[i];
    }
    ave=sum/12;
    cout.precision(2);
    cout.setf(ios::fixed);
    cout<<"总消费"<<sum<<"\n 平均消费"<<ave<<endl;
    return 0;
}
*/
/*
#include <iostream>
using namespace std;
#include "dwarfunction.h"
int main()
{
    char dwarfs[7][10];
    char verticaldwarfs[10][8];
    char backwards[7][10];
    bool good=readnames(dwarfs);
    if(!good)
    {
        cout<<"\n couldnot find the file";
        exit(1);
    }
    turnvertical(dwarfs,verticaldwarfs);
    reversenames(dwarfs,backwards);
    writename(dwarfs,verticaldwarfs,backwards);
    return 0;
}
*/
/*
#include <iostream>
#include <fstream>

int main()
{
    std::ifstream fin("names.txt");
    if(!fin)
    {
        std::cout<<"File open error!\n";
        return 1;
    }
    char c;
    while((c=fin.get())!=EOF)   //注意结束条件的判断
    {
        std::cout<<c;
    }
    fin.close();
    return 0;
}
 */
/*
#include <iostream>
using namespace std;
extern int a,b;
extern int c;
extern float f;
int main()
{
    int a,b,c;
    float f;
    a=0X10;b=0x10;c=a+b;
    f=
    cout<<c<<endl;
    return 0;
}
*/
//左值（lvalue）：指向内存位置的表达式被称为左值（lvalue）表达式。左值可以出现在赋值号的左边或右边。
//右值（rvalue）：术语右值（rvalue）指的是存储在内存中某些地址的数值。右值是不能对其进行赋值的表达式，也就是说，右值可以出现在赋值号的右边，但不能出现在赋值号的左边。
//变量是左值，因此可以出现在赋值号的左边。数值型的字面值是右值，因此不能被赋值，不能出现在赋值号的左边。下面是一个有效的语句：
//数与数之间不能负值
//int g = 20;
//整数常量可以是十进制、八进制或十六进制的常量。前缀指定基数：0x 或 0X 表示十六进制，0 表示八进制，不带前缀则默认表示十进制。
//0x表示十六进制，o表示8进制，不带后缀就是10进制，U和L就是有符号数和无符号数，
//使用 #define 预处理器。宏定义是字符替换，没有数据类型的区别，同时这种替换没有类型安全检查，可能产生边际效应等错误；
//const常量是常量的声明，有类型区别，需要在编译阶段进行类型检查
//使用 const 关键字。其只能使用不能修改其值
// void f1 ()
//{
//    #define N 12
//    const int n 12;
//}
//由于const定义实在函数体之内而define 不受定义域的限制
//void f2 ()
//{
//    cout<<N <<endl; //正确，N已经定义过，不受定义域限制
//    cout<<n <<endl; //错误，n定义域只在f1函数中
//}
//定义的取消#undef，宏定义不能作为参数传递函数，而const可出现在参数列表之间
// 整数常量也可以带一个后缀，后缀是 U 和 L 的组合，U 表示无符号整数（unsigned），L 表示长整数（long）。后缀可以是大写，也可以是小写，U 和 L 的顺序任意
//
//
//修饰符
//例如熟悉的有符号数和无符号数，unsigned和signed分别是无符号数和有符号数
// 只需要在变量定义时候把unsigned和signed放在格之前
//
/*
#include <iostream>
using namespace std;


int main()
{
    short int i;           // 有符号短整数
    short unsigned int j;  // 无符号短整数

    j = 50000;  //无符号数强制转化为有符号数

    i = j;
    cout << i << " " << j;

    return 0;
}
*/
//修饰符 volatile 告诉编译器不需要优化volatile声明的变量，
// 让程序可以直接从内存中读取变量。对于一般的变量编译器会对变量进行优化，
// 将内存中的变量值放在寄存器中以加快读写效率。
//储存类
/*
#include <iostream>

void func(void);
static int a = 10;
int main()
{

    while(a--)
    {
        func();
    }  //while循环韩素当循环到0结束
    return 0;
}
void func(void)
{
    static int i=5;
    i++;
    std::cout<<i;
    std::cout<<a<<std::endl;

}
*/
//mutable 存储类
//mutable 说明符仅适用于类的对象，这将在本教程的最后进行讲解。它允许对象的成员替代常量。
// 也就是说，mutable 成员可以通过 const 成员函数修改。
//thread_local 存储类
//使用 thread_local 说明符声明的变量仅可在它在其上创建的线程上访问。 变量在创建线程时创建，并在销毁线程时销毁。 每个线程都有其自己的变量副本。
//
//thread_local 说明符可以与 static 或 extern 合并。
//
//可以将 thread_local 仅应用于数据声明和定义，thread_local 不能用于函数声明或定义。
//
//以下演示了可以被声明为 thread_local 的变量：
/*
thread_local int x;  // 命名空间下的全局变量
class X
{
    static thread_local std::string s; // 类的static成员变量
};
static thread_local std::string X::s;  // X::s 是需要定义的

void foo()
{
    thread_local std::vector<int> v;  // 本地变量
}
 */
//位运算符
//位运算符作用于位，并逐位执行操作。&、 | 和 ^ 的真值表如下所示：
//
//p	q	p & q	p | q	p ^ q
//0	0	0	0	0
//0	1	0	1	1
//1	1	1	1	0
//1	0	0	1	1
//假设如果 A = 60，且 B = 13，现在以二进制格式表示，它们如下所示：
//
//A = 0011 1100
//
//B = 0000 1101
//
//A&B = 0000 1100
//
//A|B = 0011 1101
//
//A^B = 0011 0001
//
//~A  = 1100 0011
//二进制左移运算符。将一个运算对象的各二进制位全部左移若干位（左边的二进制位丢弃，右边补0）。
// A << 2 将得到 240，即为 1111 0000
//二进制右移运算符。将一个数的各二进制位全部右移若干位，正数左补0，负数左补1，右边丢弃。
// A >> 2 将得到 15，即为 0000 1111

//函数
//return_type function_name( parameter list )
//{
//   body of the function
//}
//函数返回类型 函数名 （输入值）
//{
//     函数体
//}
//函数参数传递
//1传递值类型，在函数调用时把参数赋给函数体，传入函数体内
//2指针调用类型，其实传递时是传递了指针所指向的值，需要在函数定义时定义函数的输入格式为指针
//3应用调用，把引用的地址复制给形式参数。在函数内，该引用用于访问调用中要用到的实际参数。这意味着，修改形式参数会影响实际参数。
//4参数默认类型，在定义时给定参数的值，或者为空只需要进行函数输出就行。
//5Lambda 函数与表达式，Lambda 表达式可以像对象一样使用，比如可以将它们赋给变量和作为参数传递，还可以像函数一样对其求值。
//字符串计数是从第0位开始的
 //例如对字符串操作的find，inset，replace，eraes，rfind，assign（复制），at（i），append连接字符
 /*
#include <string>
#include <iostream>
using namespace std;
int main()
{
    string s1="one potato two potatoes";
    string s2="potato";
    char fist_pos;
    fist_pos=s1.at(1);
    cout<<fist_pos<<endl;
    int rfist_pos;
    rfist_pos=s1.rfind(s2,string::npos);
    cout<<rfist_pos<<endl;
    string s3("l love c++");
    const char *array;
    array=s3.c_str();
    cout<<array<<endl;
    return 0;
}
*/
//                     类和对象
//1、类的声明  类的类型说明，是一段包含数据声明和函数原型的代码块，类中包含的数据和函数称为数据成员，
// c++类中函数可以直接访问，使用和修改类内的数据，而不需要作为参数传递
//2、类中的访问控制符：private私有区域和public共有区域，该类之外的代码不可访问私有
//3、变量声明在访问控制权限之后有变量的定义或者函数的定义。如果函数代码很多的情况可以放在。cpp中，少的话可以直接写入函数定义之中
//4、构造函数可以重载，但是没有返回类型。
//5、头文件文件以#ifndef和#define开始，#endif结束（预编译指令），意思是如果之前程序中未定义写的类，就可以定义和使用自己写的类，如果已经定义不可重复使用
#ifndef _DATE_H
#define _DATE_H

#include <string>
using namespace std;
class Date
{
private:
    int month,day,year;
    string description;
    int shanghaizilia

};