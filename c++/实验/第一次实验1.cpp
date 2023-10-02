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
    double GetX()
    {
        return x;
    }
    double GetY()
    {
        return y;
    }
    friend double Distance(Point *p1, Point *p2);

private:
    double x, y;
};

double Distance(Point *p1, Point *p2)
{
    return sqrt(pow((p1->GetX() - p2->GetX()), 2) + pow((p1->GetY() - p2->GetY()), 2));
}

int main()
{
    double a, b;
    cout << "请输入第一个点的坐标:\n";
    cout << "请输入x:";
    cin >> a;
    cout << "请输入y:";
    cin >> b;
    Point *p1 = new Point(a, b);
    cout << "请输入第二个点的坐标:\n";
    cout << "请输入x:";
    cin >> a;
    cout << "请输入y:";
    cin >> b;
    Point *p2 = new Point(a, b);
    cout<<"两点之间的距离为"<<Distance(p1, p2)<<endl;
    delete p1, p2;
    return 0;
}
