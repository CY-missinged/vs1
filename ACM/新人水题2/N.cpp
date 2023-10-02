#include<stdio.h>
int zys(int x);
int main()
{
    int m,i,d[10000];
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        if(zys(a)==b&&a==zys(b)) d[i-1]=1;
        else d[i-1]=0;
    }
    for(i=0;i<m;i++)
    if(d[i]==1) printf("YES\n");
        else printf("NO\n");
    return 0;
}
int zys(int x)
{
    int i,sum=1;
    for(i=2;i<x;i++)
    {
        if(x%i==0) sum=sum+i;
    }
    return sum;
}