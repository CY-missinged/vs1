#include<stdio.h>
int hws(int x);
int main()
{
    int n,a;
    scanf("%d",&n);
    a=hws(n);
    if(a==n) printf("yes");
    else printf("no");
    return 0;
}
int hws(int x)
{
    int n1=0;
    while (x!=0)
    {
        n1=n1*10+x%10;
        x=x/10;
    }
    return n1;
}