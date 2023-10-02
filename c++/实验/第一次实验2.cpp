#include <iostream>
#include <math.h>

using namespace std;

class Point
{
public:
    Point();
    Point(double a, double b)
    {
        x = a;
        y = b;
    }
    ~Point(){};
    friend class Distance;
private:
    double x, y;
};

class Distance
{
public:
    double juli(Point p1, Point p2)
    {
        return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
    }

private:
};

int main()
{
    Distance A;
    double a, b;
    cout << "请输入第一个点的坐标:\n";
    cout << "请输入x:";
    cin >> a;
    cout << "请输入y:";
    cin >> b;
    Point p1(a, b);
    cout << "请输入第二个点的坐标:\n";
    cout << "请输入x:";
    cin >> a;
    cout << "请输入y:";
    cin >> b;
    Point p2(a, b);
    cout << "两点之间的距离为" << A.juli(p1, p2) << endl;
    return 0;
}
