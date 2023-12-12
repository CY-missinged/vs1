#include <iostream>
using namespace std;

// 复制左上角小方阵到右上角
void Copy2(int **a, int size)
{
    for (int i = 1; i <= size / 2; i++)
    {
        for (int j = 1 + size / 2; j <= size; j++)
        {
            a[i][j] = a[i][j - size / 2] + size / 2;
        }
    }
}

// 复制右上角小方阵到左下角
void Copy3(int **a, int size)
{
    for (int i = 1 + size / 2; i <= size; i++)
    {
        for (int j = 1; j <= size / 2; j++)
        {
            a[i][j] = a[i - size / 2][j + size / 2];
        }
    }
}

// 复制左上角小方阵到右下角
void Copy4(int **a, int size)
{
    for (int i = 1 + size / 2; i <= size; i++)
    {
        for (int j = 1 + size / 2; j <= size; j++)
        {
            a[i][j] = a[i - size / 2][j - size / 2];
        }
    }
}

void Plan(int **a, int size)
{
    if (size == 1)
    {
        a[1][1] = 1;
    }
    else
    {
        // 递归处理左上角小方阵
        Plan(a, size / 2);
        Copy2(a, size);
        Copy3(a, size);
        Copy4(a, size);
    }
}

int main()
{
    int n;
    cout << "请输入参赛队伍数：";
    cin >> n;
    // 申请二维数组空间
    int **a = new int *[n + 1];
    for (int i = 1; i <= n; i++)
    {
        a[i] = new int[n + 1];
    }
    // 生成循环赛日程表
    Plan(a, n);
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
    {
        delete[] a[i];
    }
    delete[] a;
    return 0;
}
