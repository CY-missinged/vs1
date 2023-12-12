#include <iostream>
using namespace std;
class Shape
{
public:
    virtual double GetArea() = 0;
};
class Rect : public Shape
{
    double a, b;

public:
    Rect(double x, double y) : a(x), b(y) {}
    double GetArea()
    {
        return a * b;
    }
};
class Trape : public Shape
{
    double a, b, h;

public:
    Trape(double x, double y, double z) : a(x), b(y) { h = z; }
    double GetArea()
    {
        return (a + b) * h / 2;
    }
};
class Circle : public Shape
{
    double radium;

public:
    Circle(double r) : radium(r) {}
    double GetArea()
    {
        return 3.14 * radium * radium;
    }
};
int main()
{
    Shape *p[] = {new Rect(1, 2), new Trape(3, 4, 6), new Circle(5)};
    int i;
    for (i = 0; i < 3; i++)
        cout << p[i]->GetArea() << endl; //输出每个图形的面积
    return 0;
}
