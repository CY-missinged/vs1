#include<stdio.h>
int main()
{
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        int x=0;
        while(1)
        {
            x+=c;
            if(x>=a&&x<=b) break;
            if(x>b) {x=-1;break;}
        }
        printf("%d\n",x);
    }
    return 0;
}