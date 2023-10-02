#include<stdio.h>
int main()
{
    int i=0,i1=0,j=0,j1=0,k=0,k1=0,a,b,c,a1,b1,c1,cs=0,t1,t2,t3;
    scanf("%d%d%d%d%d%d",&a,&a1,&b,&b1,&c,&c1);
    for(;;)
    {
        j1=k1=i1=0;
        if(a*i+a1==b*j+b1&&b*j+b1==c*k+c1&&a*i+a1==c*k+c1) 
            break;
        cs++;
        printf("%d:%d %d %d ",cs,i,j,k);
        if(a*i+a1>b*j+b1) {j++;j1++;}
        if(a*i+a1<b*j+b1) {i++;i1++;}
        if(a*i+a1>c*k+c1) {k++;k1++;}
        if(a*i+a1<c*k+c1) {i++;i1++;}
        if(c*k+c1>b*j+b1) {j++;j1++;}
        if(c*k+c1<b*j+b1) {k++;k1++;}
        if(k1==2) k--;
        if(i1==2) i--;
        if(j1==2) j--;
        t1=a*i+a1;
        t2=b*j+b1;
        t3=c*k+c1;
        printf("|||%d %d %d\n",t1,t2,t3);
    }
    printf("***%d*%d*%d***",i,j,k);
    return 0;
}