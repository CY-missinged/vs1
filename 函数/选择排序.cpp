#include<stdio.h>
#define N 10
void xuan_ze(int x[],int y);
int main()
{
    int a[N],i,j;
    for(i=0;i<N;i++)
    {
        scanf("%d",&a[i]);
    }
    xuan_ze(a,N);
    for(i=0;i<N;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
void xuan_ze(int x[],int y)
{
    int i,j,k,t;
    for(i=0;i<y-1;i++)
    {
        k=i;
        for(j=i+1;j<y;j++)
        {
            if(x[k]>x[j])
            k=j;
        }
        if(k!=i)
        {
            t=x[i];
            x[i]=x[k];
            x[k]=t;
        }
    }
}