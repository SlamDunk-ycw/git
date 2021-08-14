#include<iostream>
using namespace std;
/*默认参数和函数的重载*/

//函数在定义时可以设定默认值，这样在调用时如果形参和实参数目不一致，这采用默认值
//默认值的参数要放后面

/*函数重载*/
//同一个域中，同一个函数名，来定义多个函数，但是函数的参数列表应该彼此不同，或者是参数个数不同，
int add(int a,int b,int c=2)
{
    return a+b+c;
}
//函数重载
double add(double a,double b)
{
    return a+b;
}

int main()
{
    int a=1,b=1;
    cout<<add(1,2)<<" "<<add(1,2,3)<<endl;
    cout<<add(1.0,2.1);
    return 0;
}