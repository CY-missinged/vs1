#include <iostream>
#include <math.h>
using namespace std;
class Point
{
public:
    Point();
    Point(double a, double b);
    ~Point();
    double Distance1(Point p2);
    double Getx();
    double Gety();

private:
    double x;
    double y;
};

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(double a, double b)
{
    x = a;
    y = b;
}

Point::~Point()
{
}

double Point::Distance1(Point p2)
{
    return sqrt((x - p2.x) * (x - p2.x) + (y - p2.y) * (y - p2.y));
}

double Point::Getx()
{
    return x;
}

double Point::Gety()
{
    return y;
}

// double Distance2(double x1, double y1, double x2, double y2)
// {
//     return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
// }

double Distance2(Point p1,Point p2)
{
    return sqrt((p1.Getx()-p2.Getx())*(p1.Getx()-p2.Getx())+(p1.Gety()-p2.Gety())*(p1.Gety()-p2.Gety()));
}

int main()
{
    double x1, y1, x2, y2;
    cout << "请输入第一个点的x y:\n";
    cin >> x1 >> y1;
    cout << "请输入第二个点的x y:\n";
    cin >> x2 >> y2;
    Point p1(x1, y1), p2(x2, y2);
    cout << "两点之间的距离为:(调用成员函数)\n";
    cout << p1.Distance1(p2) << endl;
    cout << "两点之间的距离为:(调用用户自定义函数)\n";
    cout << Distance2(p1,p2) << endl;
    return 0;
}
