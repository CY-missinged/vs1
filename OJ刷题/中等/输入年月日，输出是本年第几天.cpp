#include<stdio.h>
int day(int a,int b,int c);
int main()
{
    int x,y,z,sum;
    scanf("%d %d %d",&x,&y,&z);
    sum=day(x,y,z);
    printf("%d",sum);
    return 0;
}
int day(int a,int b,int c)
{
    int sum;
    sum=0;
    switch(b-1)
    {
    case 11:sum=sum+30;
        case 10:sum=sum+31;
        case 9:sum=sum+30;
        case 8:sum=sum+31;
        case 7:sum=sum+31;
        case 6:sum=sum+30;
        case 5:sum=sum+31;
        case 4:sum=sum+30;
        case 3:sum=sum+31;
        case 2:if(a%4==0&&a%100!=0||a%400==0) sum=sum+29;
                else sum=sum+28;
        case 1:sum=sum+31;
        case 0:sum=c+sum;
    }
    return (sum);
}