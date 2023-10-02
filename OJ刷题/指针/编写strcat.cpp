#include<stdio.h>
#include<string.h>
void lj(char *a,char *b);
void llj(char *a,char *b);
int main()
{
    int l;
    char *x,*y;
    char a[20],b[10];
    scanf("%s%s",a,b);
    x=a;
    y=&b[0];
    //llj与lj均可
    llj(x,y);
    puts(a);
    return 0;
}
void lj(char *a,char *b)
{
    int i=0,j=0;
    while(*a)
    {
        a++;
    }
    while(*b)
    {
        *a=*b;
        a++;
        b++;
    }
    *b='\0';
}
void llj(char *a,char *b)
{
    int i=0,j=0;
    while(*a)
    {
        a++;
    }
    while(*a++=*b++);
}