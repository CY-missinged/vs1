#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Partition(int a[], int p, int r);
int RandomizedPartition(int a[], int p, int r);
int RandomizedSelect(int a[], int p, int r, int k);

int main()
{
    srand(time((time_t *)NULL));
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    int x, k;
    k = 8;
    x = RandomizedSelect(a, 0, 8, k);
    printf("%d", x);
    return 0;
}


// 分隔的位置（左边的小右边的大）
int Partition(int a[], int p, int r)
{
    int i = p, j = r + 1;
    int x = a[p];
    while (true)
    {
        while (a[++i] < x && i < r)
            ;
        while (a[--j] > x)
            ;
        if (i >= j)
            break;
        int tem = a[j];
        a[j] = a[i];
        a[i] = tem;
    }
    a[p] = a[j];
    a[j] = x;
    return j;
}

// 第一个随机交换
int RandomizedPartition(int a[], int p, int r)
{
    int i;
    i = (rand() % (r - p + 1)) + p;
    int tem = a[i];
    a[i] = a[p];
    a[p] = tem;
    return Partition(a, p, r);
}

// 递归调用，寻找第k个
int RandomizedSelect(int a[], int p, int r, int k)
{
    if (p == r)
        return a[p];
    int i = RandomizedPartition(a, p, r);
    int j = i - p + 1;
    if (k <= j)
        return RandomizedSelect(a, p, i, k);
    else
        return RandomizedSelect(a, i + 1, r, k - j);
}
