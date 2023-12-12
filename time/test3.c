#include<stdio.h>
int main()
{
    int a=1;
    int b=a+1;
    b=a++;
    a=b+a;
    b=b++;
    b=b+a;
    return 0;
}
