#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int t,a[5][5],i,j,k,maxi;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            cin>>a[i][j];
        }
    }
        for(i=0;i<5;i++)
    {
        k=0;
        maxi=fabs(a[i][0]);
        for(j=0;j<5;j++)
        {
            if(fabs(a[i][j])>maxi) 
            {
                maxi=fabs(a[i][j]);
                k=j;
            }
        }
        t=a[i][i];
        a[i][i]=a[i][k];
        a[i][k]=t;
    }
        for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(j==4) cout<<a[i][j];
            else cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}