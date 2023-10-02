#include<stdio.h>
int main()
{
    int a[15][5],t,i,j,k,l,a1,a2;
    scanf("%d",&t);
        for(j=0;j<t;j++)
        {
            for(k=0;k<3;k++)
            {
                scanf("%d",&a[j][k]);
                if(k<2) getchar();
            }
        }
    for(i=0;i<t;i++)
    {
        printf("%02d/%02d/%02d\n",a[i][1],a[i][2],a[i][0]);
    }
    return 0;    
}