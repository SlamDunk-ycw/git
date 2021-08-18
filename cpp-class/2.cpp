#include<iostream>
using namespace std;
                        /**********对象数组和对象指针***********/
                        /***********成员指针和this指针**********/
                        //常指针，常成员，常对象，常引用
/*
类数组和对象指针
类成员指针：指向类成员的指针，c++指针分为数据指针，函数指针，数据成员指针，成员函数指针，并且不能相互转换
成员指针只适用于非静态成员指针
1.数据成员指针：定义：数据成员类型 类名：：*指针变量名=成员地址初值
2.成员函数指针：定义：返回类型 （类名：：*指针变量名）（形式参数列表）=成员地址初值
3.使用类成员指针：通过对象成员指针引用（.*）访问类成员，通过（->*）可以从指向类对象的指针成员指针访问类成员
this指针
除了静态成员函数以外，每个成员函数都有一个额外的，隐含的形参this，在调用成员函数时，编译器向形参this传递
调用成员函数的对象的地址，！！！是对象的地址！！！！
4.常指针   cube* const str，指针不能改变   const cube* str 不能通过指针改变对象的值
5.常对象 ， const cube a；对象中的所有都是常量，不能改变的，且只有常函数才能被调用
6.常引用，const cube &b=a；不能通过引用来改变对象的值
7.常成员 ，对象中的数据或则函数申明为const型
*/
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
    private:
            int x,y,z;
};
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
        cube a[3]={cube(1,1,1,1),cube(2,2,2,2),cube(3,3,3,3)};
        cube b(4,4,4,4);
        cube *str=&b;


        int cube::*pr=&cube::color;//成员指针
        int (cube::*pt)(int a,int b,int c)=&cube::size;//成员函数指针
        typedef void(cube::*OUT)()const;//给成员函数指针类型起别名;
        OUT pr=&cube::output;
        //数据成员指针和成员函数指针的用法
        cube c;
        cube *p=&c;
        int k=c.color;
        k=c.*pr;
        k=p->color;
        k=p->*pr;//意思就是*pr=color
        int c1=c.size(1,1,1);
        int c2=(c.*pt)(1,1,1);
        int c3=(p->*pt)(1,1,1);
        //*p=c,*pt=size函数，*pr=color
        const cube a1;
        cube *const p2=NULL;//指针值不能变，定义时必须要初始化
        const cube* p3;//不能通过指针改变对象的值，指针值可以改变
        return 0;
}