#include <iostream>
using namespace std;

void Table(int k, int **a);

int main()
{
    // �������������
    int num;
    cout << "�����������������";
    cin >> num;
    int n = num;
    int k; // ѭ������
    for (int i = 1; num != 1; i++)
    {
        num = num / 2;
        k = i;
    }
    // ���ݲ��������������ά����ռ�
    int **a = new int *[n + 1];
    for (int i = 1; i <= n; i++)
        a[i] = new int[n + 1];
    // ����ѭ�����ճ̱�
    Table(k, a);
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
        delete[] a[i];
    delete[] a;
    return 0;
}

void Table(int k, int **a)
{
    // �������������
    int n = 1;
    for (int i = 1; i <= k; i++)
        n *= 2;
    // Ϊ��һ�и�ֵ
    for (int i = 1; i <= n; i++)
        a[1][i] = i;
    int m = 1;
    for (int s = 1; s <= k; s++) // ����k��
    {
        n /= 2;                      // ÿ�δ���ķ����С����
        for (int t = 1; t <= n; t++) // ����ǰ�ֵ�����С����
        {
            for (int i = m + 1; i <= m * 2; i++) // ������
            {
                for (int j = m + 1; j <= m * 2; j++) // ������
                {
                    // ����ǰλ�õı�Ÿ��Ƶ����Ϻ����µ�λ�ã�ȡ����m�Ĵ�С��
                    a[i][j + (t - 1) * m * 2] = a[i - m][j + (t - 1) * m * 2 - m]; // ����
                    a[i][j + (t - 1) * m * 2 - m] = a[i - m][j + (t - 1) * m * 2]; // ����
                }
            }
        }
        m *= 2; // ��ǰС����ı߳�����2��������һ�ֵ���
    }
}
