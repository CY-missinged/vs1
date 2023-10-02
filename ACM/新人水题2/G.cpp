#include<stdio.h>
#include<string.h>
int main()
{
    int len,i;
    char a[105];
    while(gets(a))
    {
        len=strlen(a);
        for(i=0;i<len;i++)
        {
            if(i==0) a[i]=a[i]-32;
            if(a[i]==' ') a[i+1]=a[i+1]-32;
        }
        printf("%s\n",a);
    }
}