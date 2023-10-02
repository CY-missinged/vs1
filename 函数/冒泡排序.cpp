#include<stdio.h>
#define N 10
void bdd_mppx_sx(int x[],int y);
int main()
{
    int a[N],i,j;
    for(i=0;i<N;i++)
    {
        scanf("%d",&a[i]);
    }
    bdd_mppx_sx(a,N);
    for(i=0;i<N;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
void bdd_mppx_sx(int x[],int y)
{
    int i,j,t,flag;
    for(i=0;i<y-1;i++)
    {
        flag=0;
        for(j=0;j<y-1;j++)
        {
            if(x[j]>x[j+1])
            {
                t=x[j];
                x[j]=x[j+1];
                x[j+1]=t;
                flag=0;
            }
        }
        if(flag==1) break;
    }
}