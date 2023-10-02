#include<stdio.h>
#include<math.h>
double pfh(double x,int n);
int main()
{
    double x,m;
    int n;
    scanf("%lf %d",&x,&n);
    m=pfh(x,n);
    printf("%.2lf",m);
    return 0;
}
double pfh(double x,int n)
{
    double m=0;
    int i;
    for(i=1;i<=n;i++)
    {
        m=m+pow(x,i)*pow(-1,i+1);
        
	}
    return m;
}