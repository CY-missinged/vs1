//1、定义一个复数类（Complex），且对象均为常对象，定义静态成员函数IsEqual，通过该成员函数来判断两个复数是否相等，并给出完整的程序。
//要求：键盘输入复数的实部和虚部，当两个复数不相等时，采用成员函数Print输出两个复数。
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
    cout << "请输入第一个复数的实部与虚部:\n";
    cin >> x >> y;
    const Complex A(x, y);
    cout << "请输入第二个复数的实部与虚部:\n";
    cin >> x >> y;
    const Complex B(x, y);
    if (Complex::IsEqual(A, B))
        cout << "两个复数相等\n";
    else
    {
        cout << "两个复数不相等，两个复数输出如下:\n";
        A.Print();
        B.Print();
    }
    return 0;
}
