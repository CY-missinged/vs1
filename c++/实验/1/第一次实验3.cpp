#include <iostream>
using namespace std;
#define MAX 3
class Cat
{
public:
    Cat(){};
    Cat(double a)
    {
        weight = a;
        all_wei += a;
        all_num++;
    }
    ~Cat(){};
    static void Print()
    {
        cout << "Сè��������Ϊ:" << all_wei << endl;
        cout << "Сè��������Ϊ:" << all_num << endl;
    }
    void Show()
    {
        cout << "Сè������Ϊ:" << weight << endl;
    }
private:
    double weight;
    static double all_wei;
    static int all_num;
};

double Cat::all_wei = 0;
int Cat::all_num = 0;

int main()
{
    double a;
    int i = MAX;
    while (i > 0)
    {
        cout << "������Сè������:";
        cin >> a;
        Cat p1(a);
        p1.Show();
        i--;
    }
    Cat p2;
    Cat::Print();
    return 0;
}
