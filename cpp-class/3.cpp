                                /******静态成员***********/
/*
可以定义类的静态成员，能够实现同类的多个对象之间的数据共享
1.静态数据成员在类里面申明，但同时需要在类外定义
2.静态数据成员可以用作默认实参，非静态数据类型不能
3.静态数据成员的作用域还是在类里面
4.同样的可以定义静态成员函数，里面不能调用*****非静态数据成员******（因为其没有this指针，其不能用const限定
5.静态数据成员的调用，cube：：count，静态成员函数即可以用类：：调用，也可以用对象调用
6.非静态成员函数可以调用静态成员函数
*/
                                /********友元和友元函数，友元类*************/
/*
1.关键字  friend
2.同样可以将一个类声明为另一个类的友元，其里面的函数都是另一个类的友元函数
3.友元的关系不能传递，继承
*/
                                /****************类的继承和派生***************/
/*
1.定义派生类  class 类名：派生类列表（访问标号和类名） {}；
2.继承方式，public，protected，和private，不写就默认private
3.派生类的成员的访问，派生类可以访问protected，派生类不能访问基类里的私有成员
4.派生类的友元只可以访问派生类自己的公有成员，私有成员和保护成员
5.public继承基类的公有成员和保护成员保留原来的访问属性，私有成员任为基类私有
private继承，基类的所有成员在派生类中为私有成员
protectd继承，基类的公有成员和保护成员在派生类中为保护成员，私有成员仍为基类私有
*/
                                    /*赋值兼容规则*/
/*
1.在任何需要基类对象的地方，都可以使用公有派生类的对象来代替
**派生类的对象可以赋值给基类的对象
**派生类的对象可以初始化基类的引用
**派生类对象的地址可以赋值给指向基类对象的指针
*/
#include<iostream>
using namespace std;
class cube
{
    public:
            cube(int a=0,int b=0,int c=0,int d=0);
            cube(const cube& obj):color(obj.color),x(obj.x),y(obj.y),z(obj.z){}
            int size(int a,int b,int c);
            void output()const;//常成员函数
            ~cube()
            {
                cout<<"析构函数被调用"<<endl;
            }
            int color;
            static int count;
            friend int add(const cube& str);
            //静态成员,属于整个类，而不是属于任何一个对象，这里的count是为了计算cube类有多少个实例化的对象
            //友元函数，可以访问类中的私有数据，参数不能是类用户的调用形式
    private:
            int x,y;
    protected:
    int z;
};
//派生类
class cube1 :public cube
{
    public:
    int i;
    cube1(int a):cube(),i(a)
    {
        cout<<"ok";
    }
    void output()
    {
        cout<<z;
    }
};
//静态对象不属于对象，属于类，每个类只有一个静态对象
//静态=0;数据成员需要类外定义并且初始化，类里面只是申明，其他数据成员不需要声明，因为其他数据会在对象的实例化过程中被定义
int cube::count=0;
//******************
int add(const cube &str)
{
    return str.x+str.y;
}
void cube::output()const
{
    cout<<color<<endl<<x<<endl<<endl<<y<<endl<<z;
}
int cube::size(int a,int b,int c)
{
    return a*b*c;
}
cube::cube(int a,int b,int c,int d):color(a),x(b),y(c),z(d)
{
    cout<<"ok"<<endl;
}
int main()
{
    cube1 a(1);
    cube b(1);
    cube1::count++;
    cout<<cube1::count;
    add(b);
    //赋值兼容规则
    cube1 c(2);
    cube d(1,1,1,1);
    cube& e=c;
    cout<<e.color;
    d=c;
    cout<<d.color;
    cube *str=&c;
    cout<<str->color;
    return 0;
}