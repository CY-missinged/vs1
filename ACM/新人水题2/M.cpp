#include<stdio.h>
void js(int x[],int y);
int main()
{
    int n,m,a[105],b[105],c[105],i,j,k,l;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0) break;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            
        }        
        for(i=0;i<m;i++)
        {
            scanf("%d",&b[i]);
            
        }
        l=0;
        for(i=0;i<n;i++)
        {
            k=1;
            for(j=0;j<m;j++)
            {
                if(a[i]==b[j]) k--;
            }
            if(k==1) 
                {
                    c[l]=a[i];
                    l++;
                }
        }
        js(c,l);
        if(l==0) printf("NULL");
        else 
            for(i=0;i<l;i++)
            {
                printf("%d ",c[i]);
            }
        printf("\n");
    }
    return 0;
}
void js(int x[],int y)
{
    int i,j,t;
    for(i=1;i<y;i++)
    {
        for(j=0;j<y-1;j++)
        {
            if(x[j]>x[j+1])
            {
                t=x[j];
                x[j]=x[j+1];
                x[j+1]=t;
            }
        }
    }
}