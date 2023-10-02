#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,len;
    char a[105],maxi;
    while(gets(a))
    {
        len=strlen(a);
        for(i=0;i<len;i++)
        {
            if(i==0) maxi=a[0];
            if(maxi<a[i]) maxi=a[i];
        }
        for(i=0;i<len;i++)
        {
            if(a[i]==maxi)
                printf("%c(max)",a[i]);
            else 
                printf("%c",a[i]);
        }
        printf("\n");
    }
    return 0;
}