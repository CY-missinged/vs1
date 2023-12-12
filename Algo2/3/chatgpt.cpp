#include <iostream>
using namespace std;

void Table(int k, int **a);

int main()
{
    // 读入参赛队伍数
    int num;
    cout << "请输入参赛队伍数：";
    cin >> num;
    int n = num;
    int k; // 循环次数
    for (int i = 1; num != 1; i++)
    {
        num = num / 2;
        k = i;
    }
    // 根据参赛队伍数申请二维数组空间
    int **a = new int *[n + 1];
    for (int i = 1; i <= n; i++)
        a[i] = new int[n + 1];
    // 构建循环赛日程表
    Table(k, a);
    // 输出日程表
    cout << "循环赛日程表如下：" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
    // 释放动态内存
    for (int i = 1; i <= n; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

void Table(int k, int **a)
{
    // 计算比赛场次数
    int n = 1;
    for (int i = 1; i <= k; i++)
        n *= 2;
    // 为第一行赋值
    for (int i = 1; i <= n; i++)
        a[1][i] = i;
    int m = 1;
    for (int s = 1; s <= k; s++) // 复制k次
    {
        n /= 2;                      // 每次处理的方阵大小减半
        for (int t = 1; t <= n; t++) // 处理当前轮的所有小方阵
        {
            for (int i = m + 1; i <= m * 2; i++) // 遍历行
            {
                for (int j = m + 1; j <= m * 2; j++) // 遍历列
                {
                    // 将当前位置的编号复制到右上和左下的位置（取决于m的大小）
                    a[i][j + (t - 1) * m * 2] = a[i - m][j + (t - 1) * m * 2 - m]; // 右上
                    a[i][j + (t - 1) * m * 2 - m] = a[i - m][j + (t - 1) * m * 2]; // 左下
                }
            }
        }
        m *= 2; // 当前小方阵的边长乘以2，进入下一轮迭代
    }
}
