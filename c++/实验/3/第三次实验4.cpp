#include <iostream>

using namespace std;

class fushu
{
private:
    double a, b;

public:
    friend istream &operator>>(istream &in, fushu &s);
    int operator==(fushu fushu1)
    {
        if (a == fushu1.a && b == fushu1.b)
            return 1;
        else
            return 0;
    }
};

istream &operator>>(istream &in, fushu &s)
{
    in >> s.a;
    in >> s.b;
    return in;
}

int main()
{
    fushu p1, p2;
    cin >> p1 >> p2;
    if ((p1.operator==(p2)) == 1)
        cout << "�����������" << endl;
    else
        cout << "�������������" << endl;
    return 0;
}
