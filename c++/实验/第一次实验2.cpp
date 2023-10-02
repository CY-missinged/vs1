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
    cout << "�������һ���������:\n";
    cout << "������x:";
    cin >> a;
    cout << "������y:";
    cin >> b;
    Point p1(a, b);
    cout << "������ڶ����������:\n";
    cout << "������x:";
    cin >> a;
    cout << "������y:";
    cin >> b;
    Point p2(a, b);
    cout << "����֮��ľ���Ϊ" << A.juli(p1, p2) << endl;
    return 0;
}
