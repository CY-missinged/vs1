//1������һ�������ࣨComplex�����Ҷ����Ϊ�����󣬶��徲̬��Ա����IsEqual��ͨ���ó�Ա�������ж����������Ƿ���ȣ������������ĳ���
//Ҫ�󣺼������븴����ʵ�����鲿�����������������ʱ�����ó�Ա����Print�������������
#include <iostream>

using namespace std;

class Complex
{
public:
    Complex()
    {
        a = 0;
        b = 0;
    }
    Complex(double x, double y)
    {
        a = x;
        b = y;
    }
    ~Complex()
    {
        ;
    }
    void Print() const
    {
        if (b == 0 || a == 0)
            if (b == 0)
                cout << a << endl;
            else
                cout << b << "i" << endl;
        else if (b > 0)
            cout << a << "+" << b << "i" << endl;
        else
            cout << a << b << "i" << endl;
    }
    static int IsEqual(Complex C1, Complex C2)
    {
        if (C1.a == C2.a && C1.b == C2.b)
            return 1;
        else
            return 0;
    }

private:
    double a, b;
};
int main()
{
    double x, y;
    cout << "�������һ��������ʵ�����鲿:\n";
    cin >> x >> y;
    const Complex A(x, y);
    cout << "������ڶ���������ʵ�����鲿:\n";
    cin >> x >> y;
    const Complex B(x, y);
    if (Complex::IsEqual(A, B))
        cout << "�����������\n";
    else
    {
        cout << "������������ȣ����������������:\n";
        A.Print();
        B.Print();
    }
    return 0;
}
