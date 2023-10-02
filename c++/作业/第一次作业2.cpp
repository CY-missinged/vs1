#include <iostream>
using namespace std;
class Circle
{
public:
    Circle();
    Circle(double a);
    ~Circle();
    double zhouchang();
    double mianji();

private:
    double r;
};

Circle::Circle()
{
    r = 0;
}

Circle::Circle(double a)
{
    r = a;
}

Circle::~Circle()
{
}

double Circle::zhouchang()
{
    return 3.14 * 2 * r;
}
double Circle::mianji()
{
    return 3.14 * r * r;
}

int main()
{
    double r;
    cout << "ÇëÊäÈëÔ²µÄ°ë¾¶£º\n";
    cin >> r;
    Circle *q = new Circle(r);
    cout << q->mianji() << endl;
    cout << q->zhouchang() << endl;
    delete q;
    return 0;
}
