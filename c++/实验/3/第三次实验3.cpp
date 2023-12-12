

#include <iostream>

using namespace std;

class Shape
{
public:
    virtual double Perimeter()  = 0;
    virtual double Area()  = 0;
    double GetArea()
    {
        return Area();
    }
    double GetPerim()
    {
        return Perimeter();
    }
};

class Rectangle : public Shape
{
private:
    double x, y;

public:
    Rectangle()
    {
        x = 0;
        y = 0;
    }
    Rectangle(double a, double b)
    {
        x = a;
        y = b;
    }
    double Perimeter()
    {
        return 2 * (x + y);
    }
    double Area()
    {
        return x * y;
    }
};

int main()
{
    Shape *sp;
    double a, b;
    cin >> a >> b;
    Rectangle r(a, b);
    sp = &r;
    cout << "矩形的面积是：" << sp->GetArea() << endl;
    cout << "矩形的周长是：" << sp->GetPerim() << endl;
    return 0;
}
