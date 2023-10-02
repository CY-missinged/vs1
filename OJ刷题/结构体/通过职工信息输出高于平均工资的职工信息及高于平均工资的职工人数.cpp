#include<stdio.h>
int main()
{
    struct jgt
    {
        char a[10];
        char b[10];
        int c;
    };
    struct jgt d[5];
    int i,j=0,sum=0,ave;
    for(i=0;i<5;i++)
    {
        scanf("%s%s%d",d[i].a,d[i].b,&d[i].c);
        sum=sum+d[i].c;
    }
    ave=sum/5.0;
    for(i=0;i<5;i++)
    {
        if(d[i].c>ave) 
        {
            printf("%s %s %d\n",d[i].a,d[i].b,d[i].c);
            j++;
        }
    }
    printf("number=%d",j);
    return 0;
}