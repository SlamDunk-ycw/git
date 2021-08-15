#include<iostream>
using namespace std;
//inline内联函数
inline int f1(int a,int b);
//函数的重载和默认参数
int f2(int a,int b=0);
double f2(double a,double b);
//函数模板
template<typename T,typename S>T f3(T a,S b);
extern int a;
int main()
{
   
    a=1;
    //引用和指向函数的指针
    int x=5;
    int &s=x;
    //
    int(*p)(int a,int b);
    p=f2;
    //变量的作用域以及生命周期
     int a=5;
    cout<<a<<endl;
    register int b=1;
    //动态分配空间
    int *p1;
    p1=new int;
    delete p1;
    p1=new int[10];
    delete[] p1;
    p1=NULL;
}