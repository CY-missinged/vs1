#include <stdio.h>
#include <string.h>

// ����������ַ�����s
// NumStr�����ڲ��������㣬��ӡ����������Ӵ������û�������Ӵ��򲻴�ӡ��

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
