#include <iostream>
#include"Point.h"
#include "math.h"

using namespace std;

// class Point
// {
// private:
//     double x, y;

// public:
//     void input();
//     double juli(Point a, Point b);
//     ~Point();
// };

Point::Point()
{
    x=0;
    y=0;
}

Point::~Point()
{
    cout << "OK" << endl;
}

void Point::input()
{
    cout << "请输入点的坐标X，Y" << endl;
    cin >> x >> y;
}

double Point::juli(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{
    Point p1, p2, p;
    p1.input();
    p2.input();
    double x = p.juli(p1, p2);
    cout << x << "\n";
    return 0;
}
