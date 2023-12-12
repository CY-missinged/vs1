#include <iostream>
using namespace std;

// �������Ͻ�С�������Ͻ�
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

// �������Ͻ�С�������½�
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

// �������Ͻ�С�������½�
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
        // �ݹ鴦�����Ͻ�С����
        Plan(a, size / 2);
        Copy2(a, size);
        Copy3(a, size);
        Copy4(a, size);
    }
}

int main()
{
    int n;
    cout << "�����������������";
    cin >> n;
    // �����ά����ռ�
    int **a = new int *[n + 1];
    for (int i = 1; i <= n; i++)
    {
        a[i] = new int[n + 1];
    }
    // ����ѭ�����ճ̱�
    Plan(a, n);
    // ����ճ̱�
    cout << "ѭ�����ճ̱����£�" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
    // �ͷŶ�̬�ڴ�
    for (int i = 1; i <= n; i++)
    {
        delete[] a[i];
    }
    delete[] a;
    return 0;
}
