//����˳�����н���������
// encoding=GBK

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct
{
    int data[MAXSIZE];
    int len;
} SeqList;

//˳����ʼ��
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
        scanf("%d", &(L->data[i]));
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
            printf("%d\n", L->data[i]);
        }
        else
        {
            printf("%d ", L->data[i]);
        }
    }
}

//��ֵ����,�ҵ�����1����෵��0
int Find_SeqList(SeqList *L, int x)
{
    int i = 1;
    while (i <= L->len && L->data[i] != x)
        i++;
    if (i > L->len)
        return 0;
    else
        return 1;
}

//��A��B�Ľ���
void jiaoji_SeqList(SeqList *A, SeqList *B, SeqList *C)
{
    int i;
    for (i = 1; i <= A->len; i++)
    {
        if (Find_SeqList(B, A->data[i]) == 1)
        {
            C->len++;
            C->data[C->len] = A->data[i];
        }
    }
}

//��A��B�Ĳ���
void bingji_SeqList(SeqList *A, SeqList *B, SeqList *C)
{
    int i;
    for (i = 1; i <= A->len; i++)
    {
        C->data[i] = A->data[i];
    }
    C->len = A->len;
    for (i = 1; i <= B->len; i++)
    {
        if (Find_SeqList(C, B->data[i]) == 0)
        {
            C->len++;
            C->data[C->len] = B->data[i];
        }
    }
}

int main()
{
    SeqList *A, *B, *C;
    A = Init_SeqList();
    B = Init_SeqList();
    C = Init_SeqList();
    printf("������A����:\n");
    Input_SeqList(A);
    printf("������B����:\n");
    Input_SeqList(B);
    jiaoji_SeqList(A, B, C);
    printf("����A�뼯��B�Ľ���Ϊ:\n");
    Output_SeqList(C);
    C = Init_SeqList();
    bingji_SeqList(A, B, C);
    printf("����A�뼯��B�Ĳ���Ϊ:\n");
    Output_SeqList(C);
    return 0;
}
