// 3、定义一个3维向量类Vector，通过定义运算符重载实现两个向量的相加（+）和相乘（*，内积）运算，
// 写出完整的程序，要求从键盘输入向量的初始值。
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
    cout << "请输入第一个向量:\n";
    cin >> x >> y >> z;
    Vector A(x, y, z);
    cout << "请输入第二个向量:\n";
    cin >> x >> y >> z;
    Vector B(x, y, z);
    Vector  C= A + B;
    cout << "两个向量相加为";
    C.Out();
    cout << "两个向量相乘为" << A * B << endl;
    return 0;
}
