#include<iostream>
using namespace std;
int main()
{
    int i,k,a[100000]={1,1},n;
    cin>>n;
    k=0;
    for(i=0;i<n;i++)
    {
        if(i>=2) a[i]=a[i-1]+a[i-2];
        cout<<a[i]<<' ';
        k++;
        if(k%5==0) cout<<endl;
    }
    return 0;
}