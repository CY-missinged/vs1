#include<iostream>
#include<string>
#include<string.h>
#include<cctype>
using namespace std;
int main()
{
    int n,i,j,k,l,d[100];
    j=k=l=i=0;
    string str1; 
    cin>>n;
    while(n--)
    {
        char a[200];
        gets(a);
        k=strlen(a);
        for(j=k-1;j>=0;j--)
        {
            char& at(a[j]);
        }
        cout<<str1.c_str()<<endl;
        if(str1.compare(a)==0) d[i]=1;
        else d[i]=0;
    }
    for(i=1;i<=n;i++)
    {
        if(d[i]==1) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}