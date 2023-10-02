#include<stdio.h>
#include<math.h>
int znn(int n,int m);
int main()
{
    int x,n,m,k;
    scanf("%d%d",&n,&m);
    if(n>=m)
    {
        if(n==m) x=0;
        if(n>m) x=n-m;
    }
    else {
        x=1;
        while(1){
            n=znn(n,m);
            if(n==m) break;
            else x++; 
        }
    }
    printf("%d",x);
    return 0;
}
int znn(int n,int m)
{
    // if(n==m) return n;
    if(abs(2*n-m)>1)
    {
        if(2*n-m>1) {
            n--;
        }
        if(2*n-m<-1){
            n++;
        }
    }
    else n=2*n;
    return n;
}