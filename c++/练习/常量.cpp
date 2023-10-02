#include <iostream>
using namespace std;
void fun1(int *x,int *y)
{
    int z;
    z=*x;
    *x=*y;
    *y=z;
}

void fun2(int &x,int &y)
{
    int z;
    z=x;
    x=y;
    y=z;
}
int main()
[
    int i=10;j=20,m=10,n=20;
    fun1()
]
