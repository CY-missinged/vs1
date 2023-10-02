#include<stdio.h>
int main()
{
    int a[1000],b[1000],m,n,i,j;
    scanf("%d %d",&m,&n);
    for(i=0;i<m;i++)
    scanf("%d",&a[i]);
    for(i=m-1,j=n-1;i>=m-n;i--,j--)
        b[j]=a[i];
    for(i=0,j=n;i<m;i++,j++) 
        b[j]=a[i];
    for(i=0;i<m;i++)
        a[i]=b[i];
    for(i=0;i<m;i++)
        if(i==0) printf("%d",a[i]);
        else printf(" %d",a[i]);
    return 0;
}
/*#include<stdio.h>
int main()
{
    int a[1000],b[1000],m,n,i,j,t;
    scanf("%d %d",&m,&n);
    for(i=0;i<m;i++)
    scanf("%d",&a[i]);
    for(j=1;j<=n;j++)
    {
        t=a[m-1];
        for(i=m-1;i>=0;i--)  
            a[i]=a[i-1];
        a[0]=t;
    }
    for(i=0;i<m;i++)
        if(i==0) printf("%d",a[i]);
        else printf(" %d",a[i]);
    return 0;
}*/