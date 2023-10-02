// OK
#include<stdio.h>
int main()
{
    int a[300][300];
    int x,y,i,j,m,n,k,b[300][5];
    scanf("%d %d %d",&x,&y,&i);
    for(j=0;j<i;j++)
    {
        scanf("%d %d %d %d",&b[j][0],&b[j][1],&b[j][2],&b[j][3]);
        for(m=b[j][0];m<=b[j][2];m++)
        {
            for(n=b[j][1];n<=b[j][3];n++)
            {
                a[m][n]=1;
            }
        }
    }
    k=0;
    for(m=1;m<=x;m++)
    {
        for(n=1;n<=y;n++)
        {
            if(a[m][n]==1) k++;
        }
    }
    printf("%d",k);
    return 0;
}