// encoding=GBK
#include <stdio.h>

// ������������
// ��������n��ʾ��һϵ��������֮��
// eg:6����д��11��������֮��
//      6
//      5+1
//      4+2��4+1+1
//      3+3��3+2+1��3+1+1
//      2+2+2��2+2+1+1��2+1+1+1+1
//      1+1+1+1+1+1

// ����n����д�ɵ�ʽ����������m����ʽ�ӵ�����
int intdivi(int n, int m)
{
    if (n == 1 || m == 1)
        return 1;
    if (n < m)
        return intdivi(n, n); // 6=6+?,��������������
    if (n == m)
        return intdivi(n, m - 1) + 1;// num(6)=num(5)+1,���1��������1+5���ʽ�ӵ�����
    return intdivi(n, m - 1) + intdivi(n - m, m);
    // intdivi(6,4)��intdivi(6,3)+intdivi(2,2)
    //      4+2��4+1+1                         intdivi(2,2)
    //      3+3��3+2+1��3+1+1                   _____
    //      2+2+2��2+2+1+1��2+1+1+1+1               |__intdivi(6,3)
    //      1+1+1+1+1+1                         ____|
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d\n", intdivi(n, m));
    return 0;
}
