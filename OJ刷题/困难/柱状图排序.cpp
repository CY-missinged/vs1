#include<stdio.h>
#include<string.h>
int main()
{
    int t,x,i,j,k,chang,bc,b[30];
    char a[30][30];
    char c;
while(scanf("%d",&x)!=EOF)
{
    if(x<=0) break;
    getchar();
    for(i=1;i<=x;i++)
    {
        gets(a[0]);
        bc=strlen(a[0]);
        for(j=1;j<=bc;j++)
        {
            gets(a[j]);
        }
        for(j=0;j<bc;j++)
        {
            b[j]=0;
        }
        for(j=0;j<bc;j++)
        {
            for(k=0;k<bc;k++)
            {
                if(a[k][j]=='#') b[j]++;
            }
        }
        for(j=0;j<bc;j++)
        {
            for(k=0;k<bc-1;k++)
            {
                if(b[k]<b[k+1]) 
                {
                    c=a[bc][k];
                    a[bc][k]=a[bc][k+1];
                    a[bc][k+1]=c;
                    t=b[k];
                    b[k]=b[k+1];
                    b[k+1]=t;
                }
            }
        }
        printf("Case #%d:\n%d\n",i,bc);
        for(j=0;j<bc;j++)
        {
            printf("%c %d\n",a[bc][j],b[j]);
        }
    }
}
    return 0;
}               