// encoding=GBK
#include <stdio.h>

// 汉诺塔问题
// 1.每次只能移动一个数字
// 2.大数字只能在小数字之下
// 3.满足1,2的前提下，将left上的数字全部移到right上

int num = 0; // 次数

// 将n从left移动到middle
void move(int left, int middle, int n)
{
    num++;
    printf("%3dtimes: move %d from %d to %d\n", num, n, left, middle);
}

// 对left最上面n个数字进行操作，将left上面的数字利用middle中转到right上
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
