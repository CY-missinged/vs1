#include<stdio.h>
int main()
{
    char a;
    for(;;)
    {
        scanf("%c",&a);
        if(a=='\n') break;
        if(a>='A'&&a<='Z')
        printf("%c",a+32);
        else if(a>='a'&&a<='z') printf("%c",a-32);
        else printf("%c",a);
    }
    return 0;
}