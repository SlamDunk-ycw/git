/*                  运算符重载
返回类型 operator 运算符符号（形式参数列表）
{
    函数体
}
1.运算符重载为类中的成员函数，此时运算符函数的形式参数个数比运算符规定的个数要少一个，原因是非静态成员
函数都有一个隐含的this指针，运算符函数可以用this指针隐式的访问类对象的成员，因此这个对象自身的数据可以
直接访问，不需要放到形式参数列表里面，少了的运算对象就是对象本身
    双目运算符重载为类函数的定义形式
    返回类型 类名：：operator op（const 所属类型 &obj2）
    {
        ......//this指针指向第一个对象obj1
    }
    obj1 op obj2==obj1.operator（obj2）
2.运算符重载为类的友元函数
函数的形式参数列表的个数不变
3.注意：
前置单目运算符参数只有一个，后置单目运算符在参数列表中要加个int，以区分
4.对流插入和流提取运算符重载具有固定的格式
ostream& operator<<(ostream& os，const 类类型&obj)流提取
{
    os<<.....
    return os;
}
istream& operator>>(istream& is，const 类类型&obj)流插入
{
    is>>......
    return is;
}
//不能作为成员函数
5.类型转换运算符的重载
比如对double的转换，注意不用指定返回类型，和类型运算符保持一致就行
*/
#include<iostream>
using namespace std;
class complex
{
public:
    complex(double a,double b);
    complex()
    {
        cout<<"ok";
    }
    void output()
    {
        cout<<real<<" "<<imag<<endl;
    }
    complex operator-(const complex& obj);
    complex operator++(int);//后置运算符
private:
    double real;
    double imag;
    friend complex operator+(const complex&a,const complex&b);
    friend ostream& operator<<(ostream& os,const complex&obj);
    friend istream& operator>>(istream& is,complex& obj);
};
complex::complex(double a,double b):real(a),imag(b)
{
    cout<<"ok"<<endl;
}
complex operator+(const complex&a,const complex&b)
{
    double real=a.real+b.real;
    double imag=a.imag+b.imag;
    complex result(real,imag);
    return result;
}
complex complex::operator-(const complex&obj)
{
    complex result;
    result.real=this->real-obj.real;
    result.imag=this->imag-obj.imag;
    return result;
}
complex complex::operator++(int)
{
    complex result;
    result.real=real;
    result.imag=imag;
    real++;
    imag++;
    return result;
}
ostream& operator<<(ostream& os,const complex&obj)
{
    os<<"实部为："<<obj.real<<"虚部为："<<obj.imag;
    return os;
}
istream& operator>>(istream& is,complex& obj)
{
    char ch1,ch2;
    is>>obj.real>>ch1>>obj.imag>>ch2;
    return is;
}
int main()
{
    complex a(1,2),b(2,2),c;
    c=a+b;
    c.output();
    a++;
    a.output();
    return 0;
}