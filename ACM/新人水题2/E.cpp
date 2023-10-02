#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j,k,l;
    char a[55];
    while(scanf("%d\n",&n)!=EOF)
    {
        for(k=1;k<=n;k++)
        {
            gets(a);
            l=strlen(a);
            j=0;
            for(i=0;i<l;i++)
            {
                if(a[0]>='0'&&a[0]<='9') j++; 
                if(a[i]>=0&&a[i]<48) j++;
                if(a[i]>=58&&a[i]<=64) j++;
                if(a[i]>=91&&a[i]<95) j++;
                if(a[i]>95&&a[i]<=96) j++;
                if(a[i]>=123) j++;
            }
            if(j==0) printf("yes\n");
            else printf("no\n");
        }
    }
    return 0;
}