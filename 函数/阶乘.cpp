#include<stdio.h>
typedef long long int lli;
lli bdd_jc(lli a);
int main()
{
    long long int x,y;
    scanf("%lld",&x);
    y=bdd_jc(x);
    printf("%lld",y);
    return 0;
}
lli bdd_jc(lli a)
{
    //long long int x<20 20!=2432902008176640000
    if(a!=1) a=a*bdd_jc(a-1);
    return a;
}