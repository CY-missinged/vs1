#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,k,j,l,x;
    char s[55];
    scanf("%d\n",&t);
    for(i=1;i<=t;i++)
    {
        j=0;
        l=0;
        gets(s);
        x=strlen(s);
        for(k=0;k<x;k++)
        {
            if(s[k]=='B') j++;
            if(s[k]=='A'||s[k]=='C') l++;
        }
        printf("%d",j);
        printf("%d",l);
        if(j==l) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}