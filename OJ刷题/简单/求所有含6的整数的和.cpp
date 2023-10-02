#include<stdio.h>
int main()
{
    int n,i,sum,x,y,z;
    sum=0; 
    scanf("%d",&n);
    for(i=1;i<=n;i++) 
    {
        x=i%10;
        if(i>=10) y=i%100/10;
        if(i>=100) z=i/100;
        if(x==6||y==6||y==6) sum+=i;
    }
    printf("sum=%d\n",sum);
    return 0;
}