// encoding=GBK
#include <stdio.h>

// 整数划分问题
// 将正整数n表示成一系列正整数之和
// eg:6可以写成11种正整数之和
//      6
//      5+1
//      4+2，4+1+1
//      3+3，3+2+1，3+1+1
//      2+2+2，2+2+1+1，2+1+1+1+1
//      1+1+1+1+1+1

// 满足n可以写成的式子中正整数m最大的式子的数量
int intdivi(int n, int m)
{
    if (n == 1 || m == 1)
        return 1;
    if (n < m)
        return intdivi(n, n); // 6=6+?,不存在正整数？
    if (n == m)
        return intdivi(n, m - 1) + 1;// num(6)=num(5)+1,这个1的意义是1+5这个式子的数量
    return intdivi(n, m - 1) + intdivi(n - m, m);
    // intdivi(6,4)即intdivi(6,3)+intdivi(2,2)
    //      4+2，4+1+1                         intdivi(2,2)
    //      3+3，3+2+1，3+1+1                   _____
    //      2+2+2，2+2+1+1，2+1+1+1+1               |__intdivi(6,3)
    //      1+1+1+1+1+1                         ____|
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d\n", intdivi(n, m));
    return 0;
}
