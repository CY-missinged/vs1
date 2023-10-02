#include <stdio.h>
void ssyz(int x);
int main()
{
    int m;
    scanf("%d", &m);
    ssyz(m);
    return 0;
}
void ssyz(int x)
{
    int i;
    for (i = 2; i <= x;)

    {
        if (x % i == 0)
        {
            x = x / i;
            printf("%d ", i);
        }
        else
            i++;
    }
}