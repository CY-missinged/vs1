//OK 这个/要考虑除数是否为零
#include <stdio.h>
int main()
{
    int k, m, n, a[30000][5], i, t, x = 0;
    scanf("%d %d %d", &k, &m, &n);
    for (i = 0; i < m; i++)
    {
        a[i][2] = 0;
        scanf("%d %d", &a[i][0], &a[i][1]);
        if (a[i][0] == 0)
        {
            a[i][2] = 1;
            x++;
        }
        else
        {
            t = k / a[i][0];
            if (t > 0 && (a[i][1] * t > n || t * a[i][1] == n))
            {
                a[i][2] = 1;
                x++;
            }
        }
    }
    if (x == 0)
        printf("-1");
    else
    {
        for (i = 0; i < m; i++)
        {
            if (a[i][2] == 1)
                printf("%d ", i + 1);
        }
    }
    return 0;
}