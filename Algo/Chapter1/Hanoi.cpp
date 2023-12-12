// encoding=GBK
#include <stdio.h>

// ��ŵ������
// 1.ÿ��ֻ���ƶ�һ������
// 2.������ֻ����С����֮��
// 3.����1,2��ǰ���£���left�ϵ�����ȫ���Ƶ�right��

int num = 0; // ����

// ��n��left�ƶ���middle
void move(int left, int middle, int n)
{
    num++;
    printf("%3dtimes: move %d from %d to %d\n", num, n, left, middle);
}

// ��left������n�����ֽ��в�������left�������������middle��ת��right��
void hanoi(int n, int left, int middle, int right)
{
    if (n > 0)
    {
        hanoi(n - 1, left, right, middle);
        move(left, right, n);
        hanoi(n - 1, middle, left, right);
    }
}

int main()
{
    int x;
    scanf("%d", &x);
    hanoi(x, -1, -2, -3);
    return 0;
}
