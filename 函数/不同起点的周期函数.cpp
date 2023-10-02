#include<stdio.h>
int main()
{
    int i=0,j=0,a,b,a1,b1,k=0,t;
    scanf("%d%d%d%d",&a,&a1,&b,&b1);
    while(a*i+a1!=b*j+b1)
    {        
        k++;
        printf("%d:%d %d ",k,i,j);
        if(a*i+a1>b*j+b1) j++;
        else i++;
        t=a*i+a1;
        printf("%d\n",t);
    }
    printf("***%d*%d***",i,j);
    return 0;
}