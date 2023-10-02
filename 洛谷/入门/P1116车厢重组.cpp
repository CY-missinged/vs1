// OK
#include <stdio.h>
int main()
{
    int x, a[10005], I, i, j, k = 0, t;
    scanf("%d", &x);
    for (j = 0; j < x; j++)
    {
        scanf("%d", &a[j]);
    }
    for (I = 1; I < x; I++)
    {
        for (i = 0; i < x; i++)
        {
            for (j = i + 1; j < x; j++)
            {
                if (a[i] > a[j])
                {
                    k++;
                    t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }
            }
        }
    }
    printf("%d", k);
    return 0;
}