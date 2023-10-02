#include<stdio.h>
int main()
{
    float a[20],b=0;
    int i;
    for(i=0;i<12;i++)
    {
        scanf("%f",&a[i]);
        b=b+a[i];
    }
    printf("$%.2f",b/12);
    return 0;
}