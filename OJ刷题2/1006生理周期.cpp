#include <stdio.h>
void qny(int a, int b, int *x, int *y);
int main()
{
    int *x1, *y1;
    int zx, x, y;
    zx = 23 * 28 * 33;
    int a, b, c, d,i, t; 
    i = 0;
    while (scanf("%d%d%d%d", &a, &b, &c, &d) != EOF)
    {
        if (a == -1 && b == -1 && c == -1 && d == -1)
            break;
        i++;
        x1 = &x;
        y1 = &y;
        qny(28 * 33, 23, x1, y1);
        a = a * 28 * 33 * x;
        qny(23 * 33, 28, x1, y1);
        b = b * 23 * 33 * x;
        qny(23 * 28, 33, x1, y1);
        c = c * 23 * 28 * x;
        t = (a + b + c) % zx;
        t = ((t - d) % zx + zx) % zx;
        if (t <= 0)
            t = t + zx;
        printf("Case %d: the next triple peak occurs in %d days.\n", i, t);
    }
    return 0;
}
void qny(int a, int b, int *x, int *y)
{
    if (b == 0)
    {
        *x = 1;
        *y = 0;
    }
    else
    {
        qny(b, a % b, x, y);
        int tt = *x;
        *x = *y;
        *y = tt - (a / b) * (*y);
    }
}
// 23 28 33
// 19 0 1 364 WA