#include<iostream>
#include"math.h"

using namespace std;

class yuan
{
    public:
        yuan();
        yuan(double a)
        {
            r=a;
        }
        ~yuan();
        float gets();
    private:
        float r;
};

yuan::yuan()
{
    r=0;
}

yuan::~yuan()
{
    cout<<"已执行"<<endl;
}

float yuan::gets()
{
    return r*r*3.14;
}

int main()
{
    float a;
    cout<<"请输入圆的半径："<<endl;
    cin>>a;
    yuan b(a);
    yuan *p=&b;
    cout<<p->gets()<<endl;
    return 0;
}
