// 2������һ���������࣬�ó�Ա�����������ܳ�����̬��Ա���������������Ԫ��������
//����������Ӧ�ø��࣬Ҫ��Ӽ������������ε����ߡ�
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
    cout << "�����������ε�����:\n";
    cin >> x >> y >> z;
    Three A(x, y, z);
    cout << "�ܳ�Ϊ" << Three::L(A) << endl;
    cout << "���Ϊ" << S(A) << endl;
    return 0;
}
