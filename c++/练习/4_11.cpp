#include<iostream>
using namespace std;

void fun(){
    static int a=1;
    int i=5;
    a++;
    i++;
    cout<<i<<a<<endl;
}
int main()
{
    fun();
    fun();
    return 0;
}
