#include <iostream>

using namespace std;

class Point
{
private:
    char name[10];

public:
    Point(int a)
    {
        x = a;
        y = a+1;
    }
    ~Point()
    {
        cout<<name;
    }
    void juli()
    {
        cout << x << endl;
        cout << (y = x) << endl;
    }
};

int main()
{
    Point p1(7);
    Point p2(p1);
    // Point p2;
    p2.juli();
    return 0;
}
