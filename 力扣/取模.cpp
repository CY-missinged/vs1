#include<stdio.h>
typedef long long ll;
ll qumo(ll a,ll b,ll c);
int main()
{
    ll a,b,c,d;
    scanf("%lld%lld%lld",&a,&b,&c);
    d=qumo(a,b,c);
    printf("%lld",d);
    return 0;
}
ll qumo(ll a,ll b,ll c)
{
    ll x=1;
    a=a%c;
    while(b>0)
    {
        if(b%2==1)
        x=x*a%c;
        b=b/2;//或 b>>=1;
        a=(a%c)*(a%c)%c;
    }
    return x;
}