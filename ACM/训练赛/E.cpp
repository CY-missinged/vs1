#include<stdio.h>
#include<math.h>
int main()
{
    int a,b;
    long long sum;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        sum=1;
        int i;
        for(i=0;i<abs(a-b);i++)
            sum=sum*32.0;
    printf("%lld\n",sum);
    }
    return 0;
}