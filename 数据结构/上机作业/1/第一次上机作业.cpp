#include <stdio.h>
// #include <string.h>

struct goods_type
{
    int num;       //商品编号
    char name[50]; //商品名称
    float price;   //商品单价
    int stock;     //商品库存量
};

int mean();     // 菜单
int fun1(goods_type *p,goods_type *q[]); // 1.输入商品信息
void fun2(goods_type *a[],int max); // 2.按编号排序
void fun3(goods_type *a[],int max); // 3.按库存排序
void fun4(goods_type *q[],int max); // 4.输出商品信息

int main()
{
    int i,number;
    goods_type goods[100],*q[100];
    do
    {
        i=mean();   //菜单，执行序号
        switch (i)
        {
            case 0:
                printf("---已退出系统---\n");
                break;
            case 1:
                number=fun1(goods,q);
                break;
            case 2:
                fun2(q,number);
                break;
            case 3:
                fun3(q,number);
                break;
            case 4:
                fun4(q,number);
                break;
            default:
                printf("输入错误，请重新输入\n");
        }
    } 
    while (i != 0);
    return 0;
}

int mean()
{
    int i;
    printf("***********系统功能菜单***************\n");
    printf("*     1-----------输入商品信息       *\n");
    printf("*     2-----------按编号排序         *\n");
    printf("*     3-----------按库存排序         *\n");
    printf("*     4-----------输出商品信息       *\n");
    printf("*     0-----------退出系统           *\n");
    printf("**************************************\n");
    printf("请输入需要执行的序号:\n");
    scanf("%d", &i);
    return i;
}

int fun1(goods_type *p,goods_type *q[])
{
    int i,number;
    printf("请输入需要输入商品信息的个数\n");
    scanf("%d", &number);
    for (i = 0; i< number; i++)
    {
        printf("请输入第%d个商品的信息\n输入格式如下；\n商品编号 商品名称 商品单价 商品库存量)\n", i + 1);
        scanf("%d %s %f %d", &(*p).num, (*p).name, &(*p).price, &(*p).stock);
        q[i]=p++;
    }
    printf("输入成功！\n");
    return number;
}

void fun2(goods_type *a[],int max)
{
    goods_type *b;
    int i,j,k;
    for(i=0;i<max;i++)
    {
        for(j=0;j<max;j++)
        {
            if(a[i]->num<a[j]->num)
            {
                b=a[i];
                a[i]=a[j];
                a[j]=b;
            }
        }
    }
    printf("排序完成！\n");
}

void fun3(goods_type *a[],int max)
{
        goods_type *b;
    int i,j,k;
    for(i=0;i<max;i++)
    {
        for(j=0;j<max;j++)
        {
            if(a[i]->stock<a[j]->stock)
            {
                b=a[i];
                a[i]=a[j];
                a[j]=b;
            }
        }
    }
    printf("排序完成！\n");
}

void fun4(goods_type *q[],int max)
{
    int i;
    printf("商品信息如下：\n");
    for (i = 0; i < max; i++,q++)
    {
        printf("%d --- ",i+1);
        printf("%-4d %-4s %6.2f %-6d\n",(*q)->num, (*q)->name, (*q)->price, (*q)->stock);
    }
    printf("\n");
}