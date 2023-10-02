/*#include<stdio.h>
int main()
{
    int m,i,j,k,x,y;
    scanf("%d",&m);
    m=m-8;
    x=m/5;
    m=m%5;
    y=m/2;
    m=m%2;
    printf("%d %d %d\n",x+1,y+1,m+1);
    return 0;
}*/
#include<stdio.h>
int main()
{
    int m,i,j,k,x,y,z;
    scanf("%d",&m);
    m=m-8;
    j=1;i=1;k=1;
    for(i=1;m>5;i++)
    {
        m=m-5;
    }
    for(j=1;m>=2;j++)
    {
        m=m-2;
    }
    printf("%d %d %d",i,j,k+m);
    return 0;
}