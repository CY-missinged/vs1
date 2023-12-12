#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Point
{
    double a, b;

public:
    Point(double x, double y) : a(x), b(y){};
    int operator==(Point x)
    {
        if (a == x.a && b == x.b)
            return 1;
        else
            return 0;
    }
    double geta()
    {
        return a;
    }
    double getb()
    {
        return b;
    }
};
int main()
{
    // Point p1(1, 2), p2(3, 4);
    // if (p1 == p2)
    // {
    //     cout << "ok" << endl;
    // }
    // else
    //     cout << "no" << endl;
    // ofstream out("point.txt");
    // if (out)
    // {
    //     out << p1.geta() << " " << p1.getb() << " ";
    //     out << p2.geta() << " " << p2.getb() << " ";
    //     out.close();
    // }
    ofstream iin("point.txt");
    if (iin)
    {
        cout << "ok";
        // double a, b, c, d;
        // iin >> a >> b >> c >> d;
        // cout << a << endl;
        // cout << b << endl;
        // cout << c << endl;
        // cout << d << endl;
        iin.close();
    }
    return 0;
}
