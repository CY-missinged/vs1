#include<stdio.h>
#define N 4
int main()
{
    struct nmzg
    {
        int a;
        char b[10];
        int c;
        union cj
        {
            int d1;
            char d2;
        }fs;
    };
    struct nmzg yf[N];
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %s %d ",&yf[i].a,yf[i].b,&yf[i].c);
        if(yf[i].c>=30) scanf("%c",&yf[i].fs.d2);
        else scanf("%d",&yf[i].fs.d1);
    }
    j=0;
    for(i=0;i<n;i++)
    {
        if(yf[i].c<30) 
            if(yf[i].fs.d1>=60) 
            {
                printf("%d\n",yf[i].fs.d1);
                j++;
            }
        if(yf[i].c>=30&&yf[i].fs.d2!='D') 
            {
                printf("%c\n",yf[i].fs.d2);
                j++;
            }
    }
    printf("%d\n",j);
    return 0;
}