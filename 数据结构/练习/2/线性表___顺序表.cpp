#include <stdio.h>
#include <malloc.h>//#include<stdlib.h>

#define M 100

//  具体问题具体设计
// typedef struct  //定义表中的存储数据
// {
//     int a;
//     float b;
// } Datatype;
typedef int Datatype;

typedef struct  //定义顺序表
{
    Datatype data[M + 1]; //舍弃0单元,不用第0个
    int len;
} Lin_list;

Lin_list *INit_Lin_list() //线性表的初始化
{
    Lin_list *L;
    L = (Lin_list *)malloc(sizeof(Lin_list));
    L->len = 0;
    return L;   //返回线性表的首地址
}

int Locate_Lin_List(Lin_list *L,Datatype x) //查找
{
    int i;
    i=L->len;
    while(i>0&&L->data!=&x)
        i--;
    return i;
}

int Lnsert_Lin_list(Lin_list *L,int i,Datatype x)   //在第i个位置插入x
{
    int j;
    if(L->len==M)
    {
        printf("顺序表已满！");
        return 0;
    }
    if(i<1||i>L->len+1)
    {
        printf("位置不合法！");
        return 0;
    }
    for(j=L->len;j>=i;j--)
    {
        L->data[j+1]=L->data[j];
    }
    L->data[i]=x;
    L->len++;
    return 1;
}

int main()
{
    Lin_list *L1;
    L1=INit_Lin_list();  //接受首地址
    return 0;
}