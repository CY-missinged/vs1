#define _CRT_SECURE_NO_WARNINGS
// encoding=GBK
// ��������Ϊ���һ��ʵ�����ⳤ���������мӷ��������ʾ����
// ѡ������Ϊʵ�ֳ��������������㡣
// Ҫ������˫��ѭ������ʵ�ֳ������Ĵ洢��ÿ����㺬һ�����ͱ���,���ͱ����ķ�Χ�ǣ�(2^15-l)~(2^15-1)
// ��ԭ����������ʱÿ 4 λһ�飬��Ӧһ�������д洢��
// �ӷ�������˫��ѭ������

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef int Datatype;

// ����ڵ�
struct LNode
{
    Datatype num;        // ������
    LNode *first, *next; // ָ����
};

int menu();                            // �˵�
LNode *jia_fa(LNode *, LNode *);       // �ӷ�
LNode *jian_fa(LNode *, LNode *);      // ����
LNode *InitLink();                     // ����һ���ձ�
LNode *Inputlist();                    // ����
void Outputlist(LNode *);              // ���
LNode *Insert_node(LNode *, int);      // ����--L�ڵ�֮��
LNode *Insert_node_head(LNode *, int); // ����--ͷ�ڵ�֮��
LNode *jinwei(LNode *);                // ��λ
LNode *bianhao(LNode *);               // ����L���෴��
int compare_AB(LNode *, LNode *);

// ������
int main()
{
    int choose;
    LNode *shu1, *shu2, *jieguo;
    shu1 = InitLink();
    shu2 = InitLink();
    jieguo = InitLink();
    while (1)
    {
        choose = menu();
        switch (choose)
        {
        case 1: // ����
        {
            printf("�������һ������:\n");
            shu1 = Inputlist();
            printf("������ڶ�������:\n");
            shu2 = Inputlist();
            printf("\n\n%d\n", compare_AB(shu1, shu2));
            break;
        }
        case 2: // �ӷ�����
        {
            jieguo = jia_fa(shu1, shu2);
            printf("��һ������Ϊ:\n");
            Outputlist(shu1);
            printf("�ڶ�������Ϊ:\n");
            Outputlist(shu2);
            printf("�ӷ�����������:\n");
            Outputlist(jieguo);
            break;
        }
        case 3: // ��������
        {
            jieguo = jian_fa(shu1, shu2);
            printf("��һ������Ϊ:\n");
            Outputlist(shu1);
            printf("�ڶ�������Ϊ:\n");
            Outputlist(shu2);
            printf("��������������:\n");
            Outputlist(jieguo);
            break;
        }
        case 4: // �˷�����
            break;
        case 5: // ��������
            break;
        case 6: // ���
        {
            printf("��һ������Ϊ:\n");
            Outputlist(shu1);
            printf("�ڶ�������Ϊ:\n");
            Outputlist(shu2);
            break;
        }
        case 0: // �˳�
        {
            printf("��лʹ�ñ�����,�ټ�!\n");
            break;
        }
        default:
            printf("�������,����������!\n");
        }
        if (choose == 0)
            break;
        system("pause");
        system("cls");
    }
    return 0;
}

// �˵�
int menu()
{
    int choose;
    printf("**********************\n");
    printf("****�������������****\n");
    printf("**********************\n");
    printf("*   1----��������    *\n");
    printf("*   2----�ӷ�����    *\n");
    printf("*   3----��������    *\n");
    printf("*   4----�˷�����    *\n");
    printf("*   5----��������    *\n");
    printf("*   6----�������    *\n");
    printf("*   0----�˳�ϵͳ    *\n");
    printf("**********************\n");
    printf("���������ѡ��:(0-6)\n");
    scanf("%d", &choose);
    return choose;
}

// ��ʼ������--����һ���յ�˫��ѭ������
LNode *InitLink()
{
    LNode *head = (LNode *)malloc(sizeof(LNode));
    head->next = head;
    head->first = head;
    head->num = 0;
    return head;
}

// �洢����--�ڽڵ�L�����һ���½ڵ�
LNode *Insert_node(LNode *L, int x)
{
    LNode *s = (LNode *)malloc(sizeof(LNode));
    LNode *p = L->first, *head = L;
    s->num = x;
    s->next = head;
    s->first = p;
    p->next = s;
    head->first = s;
    if (head->num >= 0)
        head->num++;
    else
        head->num--;
    return L;
}

LNode *Insert_node_head(LNode *L, int x)
{
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->num = x;
    s->next = L->next;
    s->first = L;
    L->next->first = s;
    L->next = s;
    if (L->num >= 0)
        L->num++;
    else
        L->num--;
    return L;
}

// ����
LNode *Inputlist()
{
    int i, j, sum;
    char y[10005];
    LNode *head;
    i = 0;
    getchar();
    scanf("%s", y);
    head = InitLink();
    LNode *L = head;
    i = 0;
    j = 0;
    while (y[i] != '\0')
    {
        if (y[i] >= '0' && y[i] <= '9')
        {
            sum = 0;
            for (j = i; j <= i + 4; j++)
            {
                if (y[j] >= '0' && y[j] <= '9')
                    sum = sum * 10 + (y[j] - '0');
                else
                    break;
            }
            head = Insert_node_head(L, sum);
            i = j;
        }
        else
        {
            i++;
        }
    }
    if (y[0] == '-')
        head->num = -head->num;
    return head;
}

// ���--�������
void Outputlist(LNode *head)
{
    LNode *p = head;
    int flag = 0;
    if (p->next == head && p->first == head)
    {
        printf("�㻹û����������\n");
        return;
    }
    else
    {
        if (p->num < 0)
        {
            printf("-");
        }
        if (p->first->first != head)
            printf("%d,", p->first->num);
        else
        {
            printf("%d", p->first->num);
        }
    }
    p = p->first;
    while (p->first != head)
    {
        p = p->first;
        if (p->first != head)
            printf("%04d,", p->num);
        else
            printf("%04d", p->num);
    }
    printf("\n");
}

// ��λ
LNode *jinwei(LNode *L)
{
    LNode *head = L;
    int i, jinwei, num = abs(L->num);
    for (i = 1; i < num; i++)
    {
        head = head->next;
        if (head->num > 9999)
        {
            jinwei = head->num / 10000;
            head->num = head->num % 10000;
            head->next->num = head->next->num + jinwei;
        }
    }
    head = head->next;
    if (head->num > 9999)
    {
        jinwei = head->num / 10000;
        head->num = head->num % 10000;
        Insert_node(L, jinwei);
    }
    return L;
}

// ���--����L���෴��
LNode *bianhao(LNode *L)
{
    LNode *head = InitLink(), *p = L;
    while (p->next != L)
    {
        p = p->next;
        Insert_node(head, p->num);
    }
    head->num = -L->num;
    return head;
}

// ����ֵ�Ƚ�--|a|>|b|,����1,|a|==|b|,����2��|a|<|b|,����3
int compare_AB(LNode *shu1, LNode *shu2)
{
    LNode *A = shu1, *B = shu2;
    int a, b;
    a = abs(A->num);
    b = abs(B->num);
    if (a > b)
        return 1;
    if (b < a)
        return 3;
    while (A->next != shu1)
    {
        A = A->next;
        B = B->next;
        if (A->num > B->num)
            return 1;
        if (A->num < B->num)
            return 3;
    }
    return 2;
}

// �ӷ�����
LNode *jia_fa(LNode *shu1, LNode *shu2)
{
    LNode *jieguo, *A = shu1, *B = shu2;
    int i, j, a, b, num, flag_i, flag_j;
    jieguo = InitLink();
    // ab���
    if (A->num > 0 && B->num < 0)
    {
        return jian_fa(shu1, bianhao(shu2));
        // a>0,b<0
        // a+b=a-(-b)
    }
    if (A->num < 0 && B->num > 0)
    {
        return jian_fa(shu2, bianhao(shu1));
        // a<0,b>0
        // a+b=b-(a)
    }
    // abͬ��
    a = abs(A->num);
    b = abs(B->num);
    for (i = 0, j = 0; i <= a && j <= b;)
    {
        flag_i = i;
        flag_j = j;
        if (i < a)
        {
            i++;
            A = A->next;
        }
        if (j < b)
        {
            j++;
            B = B->next;
        }
        if (flag_i == i && flag_j == j)
            break;
        if (i == j)
        {
            num = A->num + B->num;
            Insert_node(jieguo, num);
        }
        if (i > j)
        {
            Insert_node(jieguo, A->num);
        }
        if (i < j)
        {
            Insert_node(jieguo, B->num);
        }
    }
    jieguo = jinwei(jieguo);
    if (A->next->num < 0)
    {
        jieguo->num = -jieguo->num;
    }
    return jieguo;
}

// ��������
LNode *jian_fa(LNode *shu1, LNode *shu2)
{
    LNode *jieguo, *A = shu1, *B = shu2;
    jieguo = InitLink();
    // ab���
    if (A->num > 0 && B->num < 0)
    {
        return jia_fa(A, bianhao(B));
        // a>0,b<0
        // a-b=a+(-b)
    }
    if (A->num < 0 && B->num > 0)
    {
        return bianhao(jia_fa(bianhao(A), B));
        // a<0,b>0
        // a-b=-(-a+b);
    }
    // abͬ��
    // if (compare_AB())
    {
        jieguo->num = -jieguo->num;
    }
    return jieguo;
}
