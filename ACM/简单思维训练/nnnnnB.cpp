#include<stdio.h>
int main()
{
    int t,n,i,j,k,l;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        k=0;
        l=0;
        for(j=1;j<=2*n;j++)
        {
            if(k=l) 
            {
                printf("'('");
                k++;
            }
            if(k>l&&k<n) {k++;printf("%c",40)||printf("')'");l++;}
            printf("%d %d",k,l);
        }

    }
    return 0;
}