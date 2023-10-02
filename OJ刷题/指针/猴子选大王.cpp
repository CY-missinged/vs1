#include<stdio.h>
int main()
{
    int n,m,i,j,k,x,a[1000];
    scanf("%d %d",&n,&m);
    for(i=0;i<=n;i++){
        a[i]=i+1;
    }
    j=x=k=0;
    while(k<n-1){
        i=0;
        for(;;j++){
            if(a[j]>n) j=0;
            if(a[j]>0) i++;
            if(i==m){
                a[j]=0;
                k++;
                x=j;
                break;
            }
        }
    }
    for(i=0;i<n;i++){
        if(a[i]!=0) printf("%d",a[i]);
    }
    return 0;
}