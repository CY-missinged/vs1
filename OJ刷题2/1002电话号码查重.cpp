#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int compare(const void *a, const void *b);
int main()
{
    int n, m, i, j, k, l = 0, flag;
    char a[100005][20], b[100];
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++)
    {
        gets(a[i]);
        m = 0;
        for (j = 0; j < strlen(a[i]); j++)
        {
            if (a[i][j] == '0')
            {
                b[m] = '0';
                m++;
            }
            if (a[i][j] == '1')
            {
                b[m] = '1';
                m++;
            }
            if (a[i][j] == 'A' || a[i][j] == 'B' || a[i][j] == 'C' || a[i][j] == '2')
            {
                b[m] = '2';
                m++;
            }
            if (a[i][j] == 'D' || a[i][j] == 'E' || a[i][j] == 'F' || a[i][j] == '3')
            {
                b[m] = '3';
                m++;
            }
            if (a[i][j] == 'G' || a[i][j] == 'H' || a[i][j] == 'I' || a[i][j] == '4')
            {
                b[m] = '4';
                m++;
            }
            if (a[i][j] == 'J' || a[i][j] == 'K' || a[i][j] == 'L' || a[i][j] == '5')
            {
                b[m] = '5';
                m++;
            }
            if (a[i][j] == 'M' || a[i][j] == 'N' || a[i][j] == 'O' || a[i][j] == '6')
            {
                b[m] = '6';
                m++;
            }
            if (a[i][j] == 'P' || a[i][j] == 'R' || a[i][j] == 'S' || a[i][j] == '7')
            {
                b[m] = '7';
                m++;
            }
            if (a[i][j] == 'T' || a[i][j] == 'U' || a[i][j] == 'V' || a[i][j] == '8')
            {
                b[m] = '8';
                m++;
            }
            if (a[i][j] == 'W' || a[i][j] == 'X' || a[i][j] == 'Y' || a[i][j] == '9')
            {
                b[m] = '9';
                m++;
            }
        }
        strcpy(a[i], b);
    }
    qsort(a,n,20, compare) ;
    for (i = 0; i < n;)
    {
        k=i;
        while(i<n&&!strcmp(a[i],a[k])) i++;
        if (i-k>1)
        {
            for (j = 0; j < 7; j++)
            {
                if (j == 3)
                    printf("-");
                printf("%c", a[k][j]);
                if (j == 6)
                    printf(" %d\n",i-k);
            }
            l = 1;
        }
    }
    if (l == 0)
        printf("No duplicates.");
    return 0;
}
int compare(const void *a, const void *b)
{
    char *pa = (char *)a;
    char *pb = (char *)b;
    return strcmp(pa,pb);
}