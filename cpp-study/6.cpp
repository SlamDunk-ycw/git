                    /*******动态内存分配******/
//new和new[]来动态分配内存和数组内存，delete和delete[]删除内存
#include<iostream>
#include<string.h>
using namespace std;
typedef enum color{red=1,green=2}color;
typedef union example
{
    int b1;char b2;
}example;
int main()
{
    int* p1,*p2;
    char *p3;
    p1=new int;//分配一个int大小的空间
    p2=new int(10);//初值为10
    p3=new char[80];//动态数组
    delete p1;
    delete p2;
    delete[] p3;
    p1=NULL;p2=NULL;p3=NULL;
    color a=red;
    example c;
    c.b1=101;
}