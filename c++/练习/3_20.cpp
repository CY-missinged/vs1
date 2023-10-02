#include<iostream>
using namespace std;

class aaa
{
    private:
        int a;
    public:
        aaa(int b);
        ~aaa();
};

aaa::aaa(int b)
{
    a=b;
}

aaa::~aaa()
{
    cout<<(this->a)<<endl;
}

int main()
{
    aaa b(3),c(4);
    return 0;
}
