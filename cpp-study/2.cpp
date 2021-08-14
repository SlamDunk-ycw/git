#include<iostream>
using namespace std;
//内联函数
//编译时，被调函数直接被写入到主调函数，不允许有循环结构和switch语句
inline int add(int a,int b)
{
    return a+b;
}
int main()
{
    cout<<add(2,3);
    return 0;
} 
