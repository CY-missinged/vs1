#include <stdio.h>
#include <string.h>
int LastWordLength(char *s)
{
    char a[100];
    strcpy(a, s);
    int i, x = 0, y = 0;
    for (i = 0; i < strlen(a); i++)
    {
        if (a[i] != ' ')
            x++;
        else
        {
            if (x != 0)
            {
                y = x;
            }
            x = 0;
        }
    }
    if (x != 0)
    {
        y = x;
    }
    return y;
}

int main()
{
    char s[100];
    gets(s);
    printf("%d", LastWordLength(s)); // Êä³ö 5
    return 0;
}
