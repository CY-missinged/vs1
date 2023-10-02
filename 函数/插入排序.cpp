#include<stdio.h>
int main()
{
    int a[1000],i,j,x,t;
    scanf("%d",&x);
    for(i=0;i<x;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<x;i++)
    {
        for(j=i;j>=0;j--)
        {
            if(a[j]>a[j-1])
                break;
            else
            {
                t=a[j];
                a[j]=a[j-1];
                a[j-1]=t;
            }
        }
    }
    for(i=0;i<x;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}