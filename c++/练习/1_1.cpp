#include<iostream>

using namespace std;

class Point
{
    private:    //私有
        //数据成员
        double x,y;
    public:     //共有
        //函数数据
        double juli();
};

double Point::juli()
{
    //函数体
}

int main()
{
    Point p1, p2;
    int i(4);
    p1.juli();
    return 0;
}