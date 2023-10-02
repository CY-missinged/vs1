#include<stdio.h>
int main()
{
    float a[3][3];
    int i,j;
    for(i=0;i<3;i++)
    for(j=0;j<3;j++)
    scanf("%f",&a[i][j]);
    for(i=0;i<3;i++)
    for(j=0;j<3;j++)
    {
        if(j<=i) a[i][j]=1.0/a[i][j];
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        printf("%.2f ",a[i][j]);
        printf("\n");
    }
    return 0;
}