#include<stdio.h>
int cxy(int x);
int ccc(int x,int y);
int main()
{
    int n,a,b;
    long long m[55];
    long double sum,da;
    int i,j,k,l,t,d;
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%d%d",&a,&b);
        if(a>b) a=b;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&m[i]);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n-1;j++)
            {
                if(m[j]<m[j+1]) 
                {
                    t=m[j];
                    m[j]=m[j+1];
                    m[j+1]=t;
                }
            }
        }
        sum=0;
        for(i=0;i<a;i++)
        {
            sum=m[i]+sum;
        }
        printf("%.6Lf\n",sum/a);
        k=0;
        l=0;
        da=1;
        for(i=0;i<n;i++)
        {
            if(m[a-1]==m[i]) 
                k++;
            if(m[a-1]==m[i]&&i<a) l++;
            
        }
        if(k==l) da=1;
        else da=cxy(k)/(cxy(l)*cxy(k-l));
        d=int(da);
        printf("%d\n",d);
    }
    return 0;
}
int cxy(int x)
{
    if(x!=1) x=x*cxy(x-1);
    return x;
}
int ccc(int x,int y)
{
    int c;
    c=cxy(x)/(cxy(y)*cxy(x-y));
    return c;
}