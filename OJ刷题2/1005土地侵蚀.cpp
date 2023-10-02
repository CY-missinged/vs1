#include<stdio.h>
#include<math.h>
#define PI acos(-1)
int main()
{
    double a[100][2],b,r2;
    int n,x,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lf%lf",&a[i][0],&a[i][1]);
    }
    for(i=0;i<n;i++)
    {   
        b=a[i][0]*a[i][0]+a[i][1]*a[i][1];
        j=(int)ceil(PI*b/100);
        printf("Property %d: This property will begin eroding in year %d.\n",i+1,j);
    }
    printf("END OF OUTPUT.\n");
    return 0;
}