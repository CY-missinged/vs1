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
    printf("����һ��С����");
    scanf("%lf", &num);
    integer_temp = num;

    while (integer_temp)
    {
        integer[i++] = HEX[(int)integer_temp % 16]; //��ʮ���������ಢ������HEX[]�����е��ַ�ƥ��
        integer_temp = (int)integer_temp / 16;
    }

    integer[i] = '.';

    for (j = i - 1; j - k > 0; j--) //����������16����˳��
    {
        hex_temp = integer[j];
        integer[j] = integer[k++];
        integer[i - j - 1] = hex_temp;
    }

    decimal_temp = num - (int)num;

    for (i = 0; i < 6; i++) //����6λ��Ч����
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
