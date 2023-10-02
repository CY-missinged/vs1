#include<stdio.h>
int yueshu(int a,int b);
int beishu(int a,int b);
int main()
{
	int x,y,m,n;
	scanf("%d%d", &x, &y);
    m=yueshu(x,y);
    n=beishu(x,y);
	printf("%d\n%d",m,n);
	return 0;
}
int yueshu(int a,int b)
{
    int c;
    if (a < b) c = a;
	else c = b;
	while((a % c == 0 && b % c == 0) != 1)
    c=c-1;		
	return c;
}
int beishu(int a,int b)
{ 
    int c,i=1;
    if(a>b) {a=a+b;b=a-b;a=a-b;}
    while(i*a%b!=0)
    {
        i=i+1;
    }
    return i*a;
}