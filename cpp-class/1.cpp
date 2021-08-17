                        /*******类class*******/
/*
1.同一个类的不同对象，对每一个对象的数据成员分配不同的空间，对成员函数公用一个共同的空间，数据成员和成员函数分开存储
2.构造函数用来对类进行初始化，构造函数在建立对象是自动调用，定义构造函数函数名与类名一样，不能有返回类型,自动调用，不能手动调用
3.构造函数可以包括构造函数初始化列表  函数名（形式参数列表）：构造函数初始化列表{    }
4.构造函数可以重载，也可以有默认参数
5.默认构造函数是不含参数的构造函数，如果定义的类没有构造函数，则编译器会自动生成一个默认构造函数，有构造函数就不会生成
6.隐式类类型转换：实现其他类型转换到类类型的隐式转换，需要定义合适的构造函数，可以调用！单个！参数 的构造函数
定义从形参类型转换到该类类型的隐式转换（explic修饰构造函数可以禁止隐式转换）
7.*复制构造函数*和合成复制构造函数：复制构造函数用来用一个生成的的对象来初始化另一个同类的对象
不管有没有定义复制构造函数，编译器会自动生成一个复制构造函数，叫做合成复制构造函数：操作为拷贝《对于非静态数据成员
1）内置的数据类型呢直接复制其值
2）类类型的成员使用该类的复制构造函数进行复制
3）数组成员，复制数组
*/
#include<iostream>
using namespace std;

class cube
{
//数据类型可以是结构体，也可以是其他类对象，类中还可以定义自己的数据类型，结构体，类等
    public:
            cube(int a=0,int b=0,int c=0,int d=0);
            //cube();
            //7.复制构造函数,参数是本类对象的引用，调用为 cube a（b），b为另一个已初始化对象，
            cube(const cube& obj):color(obj.color),x(obj.x),y(obj.y),z(obj.z){}
            
//成员函数可以重载以及默认参数
            int size(int a,int b,int c);
            void output();
    protected:

    private:
            int color;
            int x,y,z;
};
void cube::output()
{
    cout<<color<<endl<<x<<endl<<endl<<y<<endl<<z;
}
int cube::size(int a,int b,int c)
{
    return a*b*c;
}
//默认参数只能在类里指定，不能在类外指定
cube::cube(int a,int b,int c,int d):color(a),x(b),y(c),z(d)
{
    cout<<"ok"<<endl;
}
//这时两个构造函数会出现歧义，在无参数时不知调用哪个构造函数
//cube::cube()
//{
//    x=0;y=0;z=0;color=0;
//}
int main()
{
    cube a(1,1,1,1);
    cube b(a);
    b.output();
    return 0;
}