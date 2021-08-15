#include<iostream>
using namespace std;
                        /**************链表***************/
struct node
{
    int a;
    node * p;
};//链表结构体

int main()
{
    node* L;
    L=new node;
    L->a=1;
    L->p=NULL;
    int i=2;
    for(i;i<10;i++)
    {
        node* str=L;
        str->p=new node;
        str->p->a=i;
        str->p->p=NULL;
        str=str->p;
    }
    //销毁链表
    while(L!=NULL)
    {
        node* str=L->p;
        delete L;
        L=str;
    }
}