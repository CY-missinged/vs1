#include<stdio.h>
#include<stdlib.h>

int my_gets(char *ptr,int size)
{
    int i;
    for(i=0;i<=size;i++)
    {
        ptr[i]=getchar();
    }
    return i;
}
int main()
{
    int x=1,y=1;
    printf("%d\n",x++==1);
        printf("%d\n",y==1);
    return 0;
}