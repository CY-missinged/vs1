#include<stdio.h>
int cd(char *b);
int main()
{
    int x;
    char a[100],*b;
    scanf("%s",a);
    b=a;
    x=cd(b);
    printf("%d",x);
    return 0;
}
int cd(char *b)
{
    int i=0;
    while(*b){
        i++;
        b++;
    }
    return i;
}