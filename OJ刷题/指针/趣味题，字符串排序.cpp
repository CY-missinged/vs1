#include <stdio.h>
#include <string.h>
void zh(char *m, char *n, char *k);
void yy(char a[], char b[], char c[]);
void hhab(char a[], char b[]);
int main()
{
    char a[100], b[100], c[100];
    char *m, *n, *k;
    gets(a);
    gets(b);
    gets(c);
    m = a;
    n = b;
    k = c;
    zh(m, n, k);
    printf("%s\n%s\n%s\n", m, n, k);
    yy(a,b,c);
    printf("%s\n%s\n%s\n",a,b,c);
    return 0;
}
void zh(char *m, char *n, char *k)
{
    char *t;
    if (strcmp(m, n) == 1)
    {
        hhab(m, n);
    }
    if (strcmp(n, k) == 1)
    {
        hhab(n, k);
    }
    if (strcmp(m, n) == 1)
    {
        hhab(m, n);
    }
}
void yy(char a[], char b[], char c[])
{
    if (strcmp(a, b) == 1)
    {
        hhab(a, b);
    }
    if (strcmp(b, c) == 1)
    {
        hhab(b, c);
    }
    if (strcmp(a, b) == 1)
    {
        hhab(a, b);
    }
}
void hhab(char a[], char b[])
{
    char x[100];
    strcpy(x, a);
    strcpy(a, b);
    strcpy(b, x);
}