#include<stdio.h>
int main()
{
    struct jgt
    {
        int a;
        char b[20];
        int c;
    };
    struct jgt d[5];
    int i,k=0;
    int a1;
    for(i=0;i<5;i++)
        scanf("%d %s %d",&d[i].a,d[i].b,&d[i].c);
    scanf("%d",&a1);
    for(i=0;i<5;i++)
    {
        if(a1==d[i].a) 
        {
        printf("%d %s %d",d[i].a,d[i].b,d[i].c);
        k=1;
        }
    }
    if(k==0) printf("not found");
    return 0;
}