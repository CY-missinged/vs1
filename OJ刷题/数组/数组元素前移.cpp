#include<iostream>
using namespace std;
int main()
{
    int t,i,a[15];
    for(i=0;i<10;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<10;i++)
    {
        if(i==0) t=a[0];
        if(i!=0) a[i-1]=a[i];
        if(i==9) a[9]=t;
    }
    for(i=0;i<10;i++)
    {
        cout<<a[i]<<' ';
    } 
    return 0;
}