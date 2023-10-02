#include<stdio.h>
#include<string.h>
int main()
{
    char b[1000];
    int i,j;
    gets(b);
    for(i=0;i<strlen(b);i++)
    {
        if((b[i]>=65&&b[i]<=87)||(b[i]>=97&&b[i]<=119))  b[i]+=3;
        else if((b[i]>=88&&b[i]<=90)||(b[i]>=120&&b[i]<=122)) b[i]-=23;
    }
    puts(b);
    return 0;
}