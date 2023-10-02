#include<stdio.h>
void px(int *a,int *b,int *c,int x,int y,int z);
int main()
{
    int x,y,z;
    int *x1,*y1,*z1;
    scanf("%d %d %d",&x,&y,&z);
    x1=&x;
    y1=&y;
    z1=&z;
    px(x1,y1,z1,x,y,z);
    printf("%d<%d<%d",*x1,*y1,*z1);
    return 0;
}
void px(int *a,int *b,int *c,int x,int y,int z)
{
    int d;
    if(x>y) {
        d=*a;
        *a=*b;
        *b=d;
    }
    if(x>z){
        d=*a;
        *a=*c;
        *c=d;
    }
    if(y>z){
        d=*b;
        *b=*c;
        *c=d;
    }
}