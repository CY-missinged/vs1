#include<stdio.h>
#define N 4
int bdd_ef(int x[],int n,int y);
int main()
{
    int i,j,a[N],x;
    scanf("%d",&x);
    for(i=0;i<N;i++)
    {
        scanf("%d",&a[i]);
    }
    j=bdd_ef(a,N,x);
    if(j==-1) printf("sorry");
    else printf("%d",a[j]);
    return 0;
}
int bdd_ef(int x[],int n,int y)
{
    int mid,left=0,right=n-1;
    while(left<=right)
    {
        mid=left/2+right/2;
        if(y==x[mid]) return mid;
        if(y<x[mid]) right=mid-1;
        else left=mid+1;
    }
    return -1;
}