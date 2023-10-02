#include<stdio.h>
int main()
{
    int n,a[1000],i,j,maxi;
    while(scanf("%d",&n)!=EOF)
    {
        j=1;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(i==0) maxi=a[0];
            else
            {
                if(maxi<a[i]) 
                {
                    j++;
                }
                maxi=a[i];
            }
        }
        printf("%d\n",j);
    }
    return 0;
}