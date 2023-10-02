#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j,k,len,x,y,z,m,h;
    char a[105];
    while(scanf("%d\n",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            gets(a);
            x=y=z=m=h=0;
            len=strlen(a);
            for(j=0;j<len;j++)
            {
                if(a[j]=='a') x++;
                if(a[j]=='e') y++;
                if(a[j]=='i') z++;
                if(a[j]=='o') m++;
                if(a[j]=='u') h++;
            }
            printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",x,y,z,m,h);
            if(i!=n-1) printf("\n");
        }
    }
    return 0;
}