#include<stdio.h>
int bdd_hw(int a);
int main()
{
    int a;
    scanf("%d",&a);
    if(bdd_hw(a)==1) printf("Yes");
    else printf("No");
    return 0;
}
int bdd_hw(int a)
{
    int a1,a2=0;
    a1=a;
    while(a>0)
    {
        a2=a2*10+a%10;
        a=a/10;
    }
    if(a1==a2) return 1;
    else return 0;
}