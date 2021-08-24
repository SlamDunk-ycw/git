/*
类模板
解决数据类型不同，但是基本操作一样的类重复定义的问题，只用定义一次就可以了
和函数模板差不多
template <模板形参表>          模板形参表也可以是非类型的形参,此时当定义对象时，必须对其使用一个常量表达式
class 类模板名
{
    类体
}
1.在类外部定义成员函数
template <模板形参表>
返回类型 类名<类型参数表>::函数名(形式参数列表)
{
    函数体
}
2.用类模板来定义对象时，定义的格式
类模板名<模板实参列表> 对象名列表
类模板名<模板实参表> 对象名1（实参列表）.....
3.export类似于extern，extern int n， export template<class T>class A<int> a;
实例化类模板对象a
export template<class T>void f(T& a);实例化函数模板
*/
#include<iostream>
using namespace std;
template < class  T=int , int N=10>//可以对模板形式参数列表附加默认值，可以是非类型参数，比如说int N
class Point
{
public:
    Point()
    {
        cout<<"ok";
    }
    Point(const T& a,const T& b );
    void display()
    {
        cout<<"x="<<x<<"y="<<y<<endl;
    }
private:
    T x;
    T y;
    T array[N];
};
template <class T ,int N>
Point<T,N>::Point(const T& a,const T& b )
{
    x=a;y=b;
    cout<<"ok";
}
template <class T, int N>
void Point<T,N>::display()
{
    cout<<x<<" "<<y<<endl;
}
int main()
{
    Point<int,5> a(1,2);
    a.display();
    return 0;
}