// 3������һ��3ά������Vector��ͨ���������������ʵ��������������ӣ�+������ˣ�*���ڻ������㣬
// д�������ĳ���Ҫ��Ӽ������������ĳ�ʼֵ��
#include <iostream>
using namespace std;

class Vector
{
public:
    Vector()
    {
        i = j = k = 0;
    }
    Vector(double x, double y, double z)
    {
        i = x;
        j = y;
        k = z;
    }
    ~Vector()
    {
        ;
    }
    Vector operator+(Vector s1)
    {
        Vector T;
        T.i = i + s1.i;
        T.j = j + s1.j;
        T.k = k + s1.k;
        return T;
    }
    double operator*(Vector s1)
    {
        return i * s1.i + j * s1.j + k * s1.k;
    }
    void Out()
    {
        cout << "(" << i << "," << j << "," << k << ")" << endl;
    }

private:
    double i, j, k;
};

int main()
{
    double x, y, z;
    cout << "�������һ������:\n";
    cin >> x >> y >> z;
    Vector A(x, y, z);
    cout << "������ڶ�������:\n";
    cin >> x >> y >> z;
    Vector B(x, y, z);
    Vector  C= A + B;
    cout << "�����������Ϊ";
    C.Out();
    cout << "�����������Ϊ" << A * B << endl;
    return 0;
}
