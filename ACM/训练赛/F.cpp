#include<stdio.h>
#include<string.h>
int main()
{
    char a[10],b[10],c[10];
        char t;
        gets(a);
        gets(b);
        int i=0,k=1,x;
        x=strlen(a)-1;
            for(i=0;i<x;i++)
            {
                strcpy(c,a);
                if(strcmp(a,b)==0) k--;
                t=a[i];
                a[i]=a[i+1];
                a[i+1]=t;
                if(strcmp(a,b)==0) k--;
                strcpy(a,c);
            }
        if(k==1) printf("No\n");
        else printf("Yes\n");
    return 0;
}