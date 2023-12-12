// 2、定义一个三角形类，用成员函数计算其周长（静态成员函数）、面积（友元函数），
//给出主函数应用该类，要求从键盘输入三角形的三边。
//
#include <iostream>
#include <math.h>
using namespace std;

class Three
{
public:
    Three()
    {
        a = 0;
        b = 0;
        c = 0;
    }
    Three(double x, double y, double z)
    {
        a = x;
        b = y;
        c = z;
    }
    ~Three()
    {
        ;
    }
    static double L(Three s)
    {
        return s.a + s.b + s.c;
    }
    friend double S(Three s);

private:
    double a, b, c;
};

double S(Three s)
{
    double p = 0.5 * (s.a + s.b + s.c);
    return sqrt(p * (p - s.a) * (p - s.b) * (p - s.c));
}

int main()
{
    double x, y, z;
    cout << "请输入三角形的三边:\n";
    cin >> x >> y >> z;
    Three A(x, y, z);
    cout << "周长为" << Three::L(A) << endl;
    cout << "面积为" << S(A) << endl;
    return 0;
}
