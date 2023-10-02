#include<stdio.h>
int main()
{
    struct aaaa
    {
        int a;
        char b[20];
        int c;
        int d;
    };
    int i;
    struct aaaa a[3]={{001,"yi",111,1},{002,"er",222,2},{003,"san",333,3}};
    struct aaaa *p;
    p=a;
    for(;p<a+3;)
    {
        printf("%d %s %d %d\n",(p)->a,(p)->b,(p)->c,(p)->d);
        p++;
    }
    return 0;
}
// #include<stdio.h>
// int main()
// {
//     struct aaaa
//     {
//         int a;
//         char b[20];
//         int c;
//         int d;
//     };
//     struct aaaa a1={001,"yi",111,1};
//     struct aaaa a2={002,"er",222,2};
//     struct aaaa a3={003,"san",333,3};
//     struct aaaa *p1,*p2,*p3;
//     p1=&a1;
//     p2=&a2;
//     p3=&a3;
//     printf("%d %s %d",p1->a,p2->b,(*p3).c);
//     return 0;
// }