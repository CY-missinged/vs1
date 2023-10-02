#include<iostream>
using namespace std;
int main()
{
    int x;
    cin>>x;
    if(x>=100) {
        if((x%100)%10==0) cout<<"Yes";
        else cout<<"No";
    }
    else cout<<"No";
    return 0;
}