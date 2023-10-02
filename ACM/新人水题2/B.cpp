#include<stdio.h>
int main()
{
    int n,x,i,j,s[105];
    int a,b,c,d,e,sum;
    while(scanf("%d",&n)!=EOF)
    {
        
        if(n==0) break;
        for(i=0;i<n;i++)
        {  
            scanf("%d",&x);
            a=b=c=d=e=0;
            if(x>=100) {a=x/100;x=x%100;}
            if(x>=50) {b=x/50;x=x%50;}
            if(x>=10) {c=x/10;x=x%10;}
            if(x>=5) {d=x/5;x=x%5;}
            if(x>=2) {e=x/2;x=x%2;}
            s[i]=a+b+c+d+e+x;
        }
        sum=0;
        for(j=0;j<n;j++)
        {
            sum=sum+s[j];
        }
        printf("%d\n",sum);
    }
    return 0;
}