// gbk
//��д���������ڰ������ؼ��ֽ������е�˳����Ϸֱ�ʵ��˳����Һ��۰����

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct
{
    int key;
} DataType;

typedef struct
{
    DataType list[MAXSIZE + 1];
    int len;
} SeqList;

//��ʼ��
SeqList *Init_SeqList()
{
    SeqList *L;
    L = (SeqList *)malloc(sizeof(SeqList));
    L->len = 0; //�ձ�ı�Ϊ0
    return L;
}

//����
void Input_SeqList(SeqList *L)
{
    int m, i;
    printf("��������Ҫ�����Ԫ�ظ���:\n");
    scanf("%d", &m);
    L->len = m;
    printf("�����뼯��Ԫ��:\n");
    for (i = 1; i <= m; i++)
    {
        scanf("%d", &(L->list[i].key));
    }
}

//���
void Output_SeqList(SeqList *L)
{
    int i;
    for (i = 1; i <= L->len; i++)
    {
        if (i == L->len)
        {
            printf("%d\n", L->list[i].key);
        }
        else
        {
            printf("%d ", L->list[i].key);
        }
    }
}

//�ȽϺ���
int compare(const void *s1, const void *s2)
{
    return -((*(SeqList *)s1).list->key - (*(SeqList *)s2).list->key);
}

//˳�����
void shunxu_search(SeqList *L, int x)
{
    int i;
    for (i = 1; i <= L->len; i++)
    {
        if (i == L->len)
        {
            if (L->list[i].key != x)
                printf("δ���ҵ��ùؼ���!\n");
            else
            {
                printf("�Ѳ��ҵ��ùؼ��֣�λ�ڵ�%dλ\n", i);
                break;
            }
        }
        else
        {
            if (L->list[i].key == x)
            {
                printf("�Ѳ��ҵ��ùؼ��֣�λ�ڵ�%dλ\n", i);
                break;
            }
        }
    }
}

//�۰����
void half_search(SeqList *L, int x)
{
    int j = 1;
    int left, right, i = 0, flag = 0;
    for (j = 1, left = 1, right = L->len; j < 10; j++)
    {
        if (left == right)
        {
            if (x == L->list[i].key)
            {
                printf("�Ѳ��ҵ��ùؼ��֣�λ�ڵ�%dλ\n", i);
                flag = 1;
                break;
            }
            break;
        }
        i = (left + right) / 2;
        if (x == L->list[i].key)
        {
            printf("�Ѳ��ҵ��ùؼ��֣�λ�ڵ�%dλ\n", i);
            flag = 1;
            break;
        }
        else if (x > L->list[i].key)
        {
            right = i;
        }
        else
        {
            left = i;
        }
    }
    if (flag == 0)
    {
        printf("δ���ҵ��ùؼ���!\n");
    }
}

int main()
{
    int x;
    SeqList *L;
    L = Init_SeqList();
    Input_SeqList(L);
    qsort(L->list, L->len + 1, sizeof(L->list[1].key), compare);
    printf("��������Ϊ:\n");
    Output_SeqList(L);
    printf("��������Ҫ���ҵĹؼ���:");
    scanf("%d", &x);
    printf("˳����ҽ��Ϊ:\n");
    shunxu_search(L, x);
    printf("�۰���ҽ��Ϊ:\n");
    half_search(L, x);
    return 0;
}
