#include <stdio.h>
#include <string.h>

// 输入参数：字符数组s
// NumStr函数内部经过计算，打印出最长的数字子串，如果没有数字子串则不打印。

void NumStr(char s[])
{
    char a[100][100];
    int len, i, j, t, flag, l[100];
    len = strlen(s);
    j = 1;
    t = 0;
    for (i = 0, j = 0; i < len; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            a[j][t] = s[i];
            t++;
        }
        else
        {
            if (s[i - 1] >= '0' && s[i - 1] <= '9')
                j++;
            t = 0;
        }
    }
    t = -1;
    flag = -1;
    for (i = j; i >= 0; i--)
    {
        l[i] = strlen(a[i]);
        if (t < l[i])
        {
            t = l[i];
            flag = i;
        }
    }
    if (flag!=-1)
    {
        puts(a[flag]);
    }
}

int main()
{
    char s[100];
    gets(s);
    NumStr(s);
    return 0;
}
