// OK
#include<stdio.h>
#include<string.h>
int main()
{
    int m,x,i,j;
    char n[1005];
    scanf("%d %s",&m,n);
    x=strlen(n);
    for(j=0,i=x-1;i>=0;i--,j++)
    {
        if(j==0) printf("%c*%d^%d",n[j],m,i);
        else if(n[j]!='0') printf("+%c*%d^%d",n[j],m,i);
    }
    return 0;
}