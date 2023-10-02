//OK
#include <stdio.h>
int main()
{
    int n, m, x, y, i, j;
    int a[1000][5], b[1000][5];
    scanf("%d %d %d %d", &n, &m, &x, &y);
    for (i = 0; i < x; i++)
    {
        scanf("%d %d %d %d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
    }
    for (i = 0; i < y; i++)
    {
        scanf("%d %d", &b[i][0], &b[i][1]);
        b[i][2] = 0;
        b[i][3] = 0;
    }
    for (i = 0; i < y; i++)
    {
        for (j = 0; j < x; j++)
        {
            if ((b[i][0] > a[j][0] || b[i][0] == a[j][0]) && (b[i][0] < a[j][2] || b[i][0] == a[j][2]) && ((b[i][1] > a[j][1] || b[i][1] == a[j][1])) && (b[i][1] < a[j][3] || b[i][1] == a[j][3]))
            {
                b[i][2] = b[i][2] + 1;
                b[i][3] = j+ 1;
            }
        }
    }
    for (i = 0; i < y; i++)
    {
        if (b[i][2] == 0)
            printf("N");
        else
            printf("Y %d %d", b[i][2], b[i][3]);
        if (i != y - 1)
            printf("\n");
    }
    return 0;
}