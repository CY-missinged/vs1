#include <stdio.h>
#include <string.h>

int main()
{
    char integer[32] = "0";
    char decimal[32] = "0";
    char HEX[] = "0123456789ABCDEF";
    char hex[64];
    char hex_temp;
    int i, j, k = 0;
    double num, decimal_temp, integer_temp = 0;
    printf("输入一个小数：");
    scanf("%lf", &num);
    integer_temp = num;

    while (integer_temp)
    {
        integer[i++] = HEX[(int)integer_temp % 16]; //对十进制数求余并最终与HEX[]数组中的字符匹配
        integer_temp = (int)integer_temp / 16;
    }

    integer[i] = '.';

    for (j = i - 1; j - k > 0; j--) //调换整数的16进制顺序
    {
        hex_temp = integer[j];
        integer[j] = integer[k++];
        integer[i - j - 1] = hex_temp;
    }

    decimal_temp = num - (int)num;

    for (i = 0; i < 6; i++) //保留6位有效数字
    {
        decimal_temp = decimal_temp * 16;
        decimal[i] = HEX[(int)decimal_temp];
        decimal_temp = decimal_temp - (int)decimal_temp;
        if (decimal_temp == 0)
        {
            decimal[i + 1] = '\0';
            break;
        }
    }
    strcpy(hex, integer);
    strcat(hex, decimal);
    puts(hex);
}
