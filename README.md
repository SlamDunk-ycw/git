#                     #########git###########
这是一个git的学习仓库
我们会在这里进行git和c++的学习

1.首先是内联函数
2.函数重载和函数默认参数
3.变量的作用域和存储方式，static，extern，register，库文件
4.函数的模板   template<typename T>(  )
5.引用类型和指向函数的指针
6.动态分配存储空间new和delete
7.链表

8.预处理命令和宏定义
    //1）带参数的宏定义     #define 宏名（参数表）  字符文本   
    引用格式  宏名（引用参数表）
    例如： #define max（a，b） (((a)>(b))?(a):(b))
    #运算符是把文本参数字符串化
    ##运算符是将两个字符文本连接成一个
    //2）不带参数的宏定义  #define PI 3.14159   #define M y*y+3*y

9.文件包含和条件编译
文件包含作用是把指定的文件插入到当前位置，然后再进行编译处理，相当于将文件内容嵌入到当前源文件中一起编译
#include<>和#include" "
#文件包含的重复包含问题
    1.使用条件编译
    2.使用特殊预处理命令#pragma
        1）#ifdef 条件编译命令
        #ifdef DEBUG           如果DEBUG定义了，则编译print后面的语句
        print（.........）
         #endif
        2）#if条件编译命令
        #if 常量表达式
        ..........
        #else 常量表达式
        ........
        #endif
10.类
    1)类的创建
    2）对象数组和对象指针，成员指针