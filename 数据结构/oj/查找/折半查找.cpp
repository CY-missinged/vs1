// ��д�۰���Һ���BinSearch��ʵ����һ����ѧ�Ž������е�ѧ����Ϣ˳����ϲ���ָ��ѧ��ѧ���Ĺ��ܡ�
// �������´�����������BinSearch�����ı�д������������BinSearch�����ĵ��á�

#include <stdio.h>

#define MAXLEN 100

typedef struct
{
    int num;
    char name[10];
    int age;
} DataType;

typedef struct
{
    DataType list[MAXLEN];
    int length;
} SeqList;

void BinSearch(SeqList *, int);

int main()
{
    int i, n, tnum;
    SeqList a;
    scanf("%d", &a.length);
    for (i = 1; i <= a.length; i++)
        scanf("%d%s%d", &a.list[i].num, a.list[i].name, &a.list[i].age);
    scanf("%d", &tnum);
    BinSearch(&a, tnum);
    return 0;
}

void BinSearch(SeqList *L, int tnum)
{
    int left = 1, right = L->length, i, j, flag = 0, time = 0;
    while (left <= right)
    {
        time++;
        i = (left + right) / 2;
        if (tnum == L->list[i].num)
        {
            flag = 1;
            printf("position:%d\n", i);
            printf("times:%d\n", time);
            break;
        }
        else if (tnum < L->list[i].num)
        {
            left = i + 1;
        }
        else
        {
            right = i - 1;
        }
    }
    if (flag == 0)
    {
        printf("Not found!\n");
    }
}
