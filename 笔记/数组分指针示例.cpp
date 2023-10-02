/*
#include<stdio.h>
int main()
{
    int a[2][3]={{1,3,6},{8,4,2}};
    int (*b)[3],*c;
    for(b=a;b<a+2;b++)
    {
        for(c=*b;c<*b+3;c++)
        {
            printf("%5d",*c);
        }
        printf("\n");
    }
    return 0;
}
*/
#include<stdio.h>
// void f(int (*)[4],int (*)[4]);
// void print(int (*)[4]);
void fx(int a[][4],int b[][4]);
void ppp(int a[][4]);
void pp2(int *p);
int main()
{
    int a[5][4]={{1,2,3,4},{2,3,4,5},{3,4,5,6},{4,5,6,7},{5,6,7,8}};
    int b[5][4]={{6,7,8,9},{7,8,9,10},{8,9,10,11}};
    printf("*****************\n");
    // print(a);
    ppp(a);
    printf("*****************\n");
    // print(b);
    ppp(b);
    printf("*****************\n");
    // f(a,b);
    fx(a,b);
    // print(a);
    // ppp(a);
    pp2(&a[0][0]);
    printf("*****************\n");
    // print(b);
    ppp(b);
    printf("*****************\n");
    return 0;
}

void f(int (*a)[4],int (*b)[4])
{
    int *a1,*b1,*c;
    int (*p)[4];
    p=a;
    while(a<p+5)
    {
        a1=*a;
        b1=*b;
        c=a1+4;
        while(a1<c)
        {
            *a1=*a1+*b1;
            a1++;
            b1++;
        }
        a++;
        b++;
    }
}
void print(int (*p)[4])
{
    int (*q)[4],*a;
    for(q=p;q<p+5;q++)
    {
        for(a=*q;a<*q+4;a++)
        {
            printf("%4d",*a);
        }
        printf("\n");
    }
}
void fx(int a[][4],int b[][4])
{
    int *p1,*p2;
    p1=a[0];
    p2=b[0];
    while(p1<*a+5*4)
    {
        *p1+++=*p2++;
    }
}
void ppp(int a[][4])
{
    int (*b)[4],*c;
    b=a;
    while(b<a+5)
    {
        c=*b;
        while(c<*b+4)
        {
            printf("%4d",*c);
            c++;
        }
        printf("\n");
        b++;
    }
}
void pp2(int *p)
{
    int i,*q;
    q=p;
    while(q<p+5*4)
    {
        printf("%4d",*q);
        q++;
        if((q-p)%4==0) printf("\n");
    }
}