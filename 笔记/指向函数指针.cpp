#include<stdio.h>
int add(int a,int b);
int jjj(int a,int b);
void ppp(int ,int ,int (*)(int ,int ));
int main()
{
    int a=1,b=2,c=3;
    int (*p)(int ,int );
    p=add;
    ppp(a,b,p);
    p=jjj;
    ppp(b,c,p);
    return 0;
}
int add(int a,int b)
{
    return a+b;
}
int jjj(int a,int b)
{
    return b-a;
}
void ppp(int a,int b,int (*fun)(int x,int y))
{
    printf("%d\n",(*fun)(a,b));
}