#include<stdio.h>
int main() 
{
    struct std
    {
        int a;
        char b[10];
        float c1;
        float c2;
        float c3;
    };
    struct std xs[10];
    int i,j,k,flag;
    float t[10],maxi;
    for(i=0;i<5;i++)
    {
        scanf("%d %s %f %f %f",&xs[i].a,xs[i].b,&xs[i].c1,&xs[i].c2,&xs[i].c3);
        t[i]=(xs[i].c1+xs[i].c2+xs[i].c3)/3;
    }
    for(i=0;i<5;i++)
    {
        printf("%d %s %.2f %.2f %.2f %.2f\n",xs[i].a,xs[i].b,xs[i].c1,xs[i].c2,xs[i].c3,t[i]);
    }
    for(flag=1;flag<=3;flag++)
    {
        k=0;
        maxi=t[0];
        for(j=0;j<5;j++)
        if(t[j]>maxi) 
            {
                maxi=t[j];
                k=j;
            }
        printf("%d %s %.2f %.2f %.2f %.2f\n",xs[k].a,xs[k].b,xs[k].c1,xs[k].c2,xs[k].c3,t[k]);
        t[k]=-1;
    }
    return 0;
}