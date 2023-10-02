/*#include<stdio.h>
int main()
{
    int a[40],x,y,i,k;
    scanf("%d",&x);
    k=0;
    for(i=0;i<40;i++)
    {
        y=x%2;
        a[i]=y;
        x=x/2;
        if(x==0) break;
        else k++;
    }
    for(;k>=0;k--)
    printf("%d",a[k]);
    return 0;
}*/
#include<stdio.h>
void fun(int x);
int main()
{
    int x;
    scanf("%d",&x);
    fun(x);
    return 0;
}
void fun(int x)
{
    if(x!=0)
    {
        fun(x/2);
        printf("%d",x%2);
    }
}