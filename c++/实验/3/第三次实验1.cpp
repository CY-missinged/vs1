// ����protected�̳дӻ��ࣨBase��������1�����ࣨDerived����
// Ȼ��ͨ��������Ķ���obj���ʻ����˽�����ݳ�Ա��
// �����е�˽�г�Ա��int x

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
