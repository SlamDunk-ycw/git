#include<iostream>
#include<string.h>
using namespace std;
						/********引用*********/
//引用不是创建一个新的对象，而是对已知对象的别名而已

//用引用类型来做形参可以达到修改实参的效果
void change(int &a,int& b)
{
	int k=a;
	a=b;
	b=k;
}

//函数返回类型为引用类型
//返回的不是一个新的对象，而是一个已知对象
int& max(int &a,int& b)
{
	if(a>b)
	return a;
	else return b;
}

int main()
{
    //这是引用类型
	//简单的说引用类型就是一个对象的别名
	int x;
	int &r=x;
	//引用是const类型，申明后不能再是别的对象的引用
	//声明时就要初始化它
	int y=1,z=2;
	change(y,z);
		cout<<y<<z<<endl;

	int m=15,n=10,p=5,q=4;
	p=max(m,n);
		cout<<p<<endl;
	//返回为引用类型，其实就是某一个已知的对象的别称，在等号中可以在左边
	max(m,n)=q;
		cout<<m<<endl;

				/**********指向函数的指针变量***************/
	//函数名代表函数，又是函数的指针
	//可以定义指向函数的指针的指针变量
	/*	
	形式：返回类型 （*函数指针变量名）（形式参数列表）
		指向如下形式的函数
		返回类型  函数名（形式参数列表）
		{
			函数体
		}
	*/
	void (*str)(int&a,int&b);
	str=change;
	//调用change函数就可以用str（a，b）==change（a，b）
	return 0;
}       
