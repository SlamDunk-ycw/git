#include<iostream>
#include<cmath>//math
using namespace std;
//函数模板，多个函数功能相识，只用写一个
//创建一个通用功能的函数
//是一个独立于类型的函数，对于不同类型的参数，产生特定的函数版本

//  template<模板形参表>返回类型  函数名（形参列表）
template<typename T>T add(T a,T b)//T代表一个数据类型
{
    return a+b;
} 
//template<typename T,typename S>T abs(T a,S b)

int main()
{
    cout<<add(1,2)<<endl<<add(1.0,2.0)<<endl;
    return 0;
}