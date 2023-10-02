#include <stdio.h>
double kkk(double x1, double y1, double x2, double y2);
double bbb(double x1, double y1, double k);
int main()
{
    double a[305][2], K, B;
    int n, i, j, x = 0, i1, i2;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%lf%lf", &a[i][0], &a[i][1]);
    }
    for (i1 = 0; i1 < n - 2; i1++)
    {
        for (i2 = i1 + 1; i2 < n - 1; i2++)
        {
            if (a[i1][0] != a[i2][0])
            {
                K = kkk(a[i1][0], a[i1][1], a[i2][0], a[i2][1]);
                B = bbb(a[i1][0], a[i1][1], K);
                for (j = i2 + 1; j < n; j++)
                {
                    if ((K * a[j][0] + B - a[j][1]) > 1e-6)
                        x++;
                    // printf("%d %d %d %.2lf %.2lf %d\n", i1, i2, j, K, B, x);
                }
            }
            else
            {
                for (j = i2 + 1; j < n; j++)
                {
                    // printf("%d %d %d\n", i1, i2, j);
                    if (a[i1][0] != a[j][0])
                        x++;
                }
            }
        }
    }
    printf("%d", x);
    return 0;
}
double kkk(double x1, double y1, double x2, double y2)
{
    double x;
    x = (y1 - y2) / (x1 - x2);
    return x;
}
double bbb(double x1, double y1, double k)
{
    double x;
    x = y1 - x1 * k;
    return x;
}
// #include <stdio.h>
// #include<math.h>
// int kk(int a, int b, int c, int d, int e, int f);
// int main()
// {
//     int a[305][2], i, j, k = 0, n, i1, i2;
//     scanf("%d", &n);
//     for (i = 0; i < n; i++)
//     {
//         scanf("%f%f", &a[i][0], &a[i][1]);
//     }
//     for (i1 = 0; i1 < n - 2; i1++)
//     {
//         for (i2 = i1 + 1; i2 < n - 1; i2++)
//         {
//             for (j = i2 + 1; j < n; j++)
//             {
//                 k = k + kk(a[i1][0], a[i1][1], a[i2][0], a[i2][1], a[j][0], a[j][1]);
//             }
//         }
//     }
//     printf("%d", k);
//     return 0;
// }
// int kk(int a, int b, int c, int d, int e, int f)
// {
//     if (c != a && e != c && e != a)
//     {
//         double k1 = 1.0 * (d - b) / (c - a);
//         double k2 = 1.0 * (f - d) / (e - c);
//         if (k1-k2<1e-6)
//         {
//             return 0;
//         }
//         else
//         {
//             return 1;
//         }
//     }
//     else
//     {
//         if(a == c && c == e)
//         {
//             return 0;
//         }
//         else
//         {
//             if (b == d && d == f)
//                 return 0;
//             else
//                 return 1;
//         }
//     }
// }
