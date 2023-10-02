#include<stdio.h>
int fun(char a);
int main()
{
    int m,yy,i,t;
    char xx;
    scanf("%d\n",&m);
    for(i=0;i<m;i++)
    {
        scanf("\n%c %d",&xx,&yy);
        t=yy+fun(xx);
        printf("%d\n",t);
    }
    return 0;
}
int fun(char abbb)
{
    if(abbb<='Z'&&abbb>='A') return (int)abbb-64;
    if(abbb<='z'&&abbb>='a') return 96-(int)abbb;
}