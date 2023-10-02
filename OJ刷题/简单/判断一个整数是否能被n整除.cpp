#include<stdio.h>
int fxxxxxx(int m,int n);
int main()
{
    int n,m,i,s,sum;
    sum=0;
    scanf("%d",&n);
    while(1)
    {
    scanf("%d",&m);
    if(m==fxxxxxx(m,n)) sum=sum+m;
    if(m==0) break;
    }
    printf("%d",sum);
    return 0;
}
int fxxxxxx(int m,int n)
{
    if(m%n==0) return m;
    else return 0;
}

