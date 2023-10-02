#include<stdio.h>
#include<math.h>
int main()
{
    int m,n,a[100][100],i,j,i1=0,j1=0,maxi;
    while(scanf("%d%d",&m,&n)!=EOF)
    {   
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    maxi=a[0][0];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        if(abs(a[i][j])>maxi) 
        {
            maxi=abs(a[i][j]);
            i1=i;
            j1=j;
        }
    }
    printf("%d %d %d\n",i1+1,j1+1,a[i1][j1]);
    }    
    return 0;
}