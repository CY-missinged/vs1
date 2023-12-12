#include "stdio.h"
#include "stdlib.h"
#define N 100
void Split(int a[], int n, int &l, int &r)
{ // 以中间数字为界，确定左右界
    int mid = n / 2;
    for (l = 0; l <= mid; ++l) // 找左界
        if (a[l] == a[mid])
            break;                // 此时l为左界
    for (r = mid + 1; r < n; ++r) // 找右界
        if (a[r] != a[mid])
            break; // 此时r为右界
}
void getMaxNum(int &num, int &maxnum, int a[], int n)
{ // 求众数和重数
    int l, r, s;
    int mid = n / 2;
    Split(a, n, l, r);
    s = r - l;
    if (s > maxnum)
    { // 如果中间数字的个数大于现在的重数，则更新
        num = a[mid];
        maxnum = s;
    }
    if (s == maxnum) // 如果出现多个众数，输出最小的那个
        if (num > a[mid])
        {
            num = a[mid];
            maxnum = s;
        }
    if (l + 1 > maxnum)
        // 如果左边的个数>maxnum,则搜索左边
        getMaxNum(num, maxnum, a, l + 1);
    if (n - r > maxnum)
        // 如果右边的个数>maxnum,则搜索右边
        getMaxNum(num, maxnum, a + r, n - r);
}
int main()
{
    int i, n, a[N];
    int num = 0;     // num为众数
    int maxnum = 0;  // maxnum为重数
    scanf("%d", &n); // 输入数据个数
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]); // 输入数据
    // sort(a[i]);//将数据排序
    getMaxNum(num, maxnum, a, n);
    printf("%d\n%d", num, maxnum);
    return 0;
}
