// encoding=GBK
#include<stdio.h>

// Fibonacci数列
int Fibonacci(int n)
{
    if(n==1||n==2)
        return 1;
    return  Fibonacci(n-1)+Fibonacci(n-2);
}

int main()
{
    int x;
    scanf("%d",&x);
    printf("%d",Fibonacci(x));
    return 0;
}
