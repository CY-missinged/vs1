#include<stdio.h>
int main()
{
    enum ys
    {
        red, yellow, blue, green, black, white
    };
    enum ys color;
    int x;
    scanf("%d",&x);
    switch(x)
    {
        case 0:printf("red");break;
        case 1:printf("yellow");break;
        case 2:printf("blue");break;
        case 3:printf("green");break;
        case 4:printf("black");break;
        case 5:printf("white");break;
    }
    return 0;
}