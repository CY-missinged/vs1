#include<stdio.h>
#include<string.h>
int main()
{
    struct xuanpiao
    {
        char name[10];
        int piao;
    };
    struct xuanpiao d1={"Li",0},d2={"Zhang",0},d3={"Wang",0};
    int i=0;
    char b[10];
    for(i=0;i<8;i++)
    {
    scanf("%s",b);
    if(strcmp(d1.name,b)==0) d1.piao++;
    if(strcmp(d2.name,b)==0) d2.piao++;
    if(strcmp(d3.name,b)==0) d3.piao++;
    }
    printf("%s:%d\n",d1.name,d1.piao);
    printf("%s:%d\n",d2.name,d2.piao);
    printf("%s:%d\n",d3.name,d3.piao);
    return 0;
}
//烟雨行舟（原唱：伦桑）