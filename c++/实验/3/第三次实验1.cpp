// 采用protected继承从基类（Base）派生出1个新类（Derived）。
// 然后通过派生类的对象obj访问基类的私有数据成员。
// 基类中的私有成员是int x

#include <iostream>

using namespace std;

class Base
{
public:
    Base()
    {
        x = 0;
    }
    Base(int a)
    {
        x = a;
    }
    ~Base()
    {
        ;
    }
    void Base_cin(int a)
    {
        x = a;
    }
    void Print1()
    {
        cout << x << endl;
    }

private:
    int x;
};

class Derived : protected Base
{
public:
    Derived(int a)
    {
        Base_cin(a);
    }
    ~Derived()
    {
        ;
    }
    void Print()
    {
        Print1();
    }
};

int main()
{
    Derived obj(10);
    obj.Print();
    return 0;
}
