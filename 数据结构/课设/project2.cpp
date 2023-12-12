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

#define max 100
#define max1 100
typedef int Datatype;

// ����ڵ�
struct LNode
{
    Datatype num;        // ������
    LNode *first, *next; // ָ����
};

char *menu(); // �˵�

LNode *InitLink();                      // ��ʼ��--����һ���ձ�
LNode *Inputlist();                     // ����
LNode *Inputlist_char(char[]);          // ����--�������̱�Ϊ����
void Outputlist(LNode *);               // ���
LNode *Insert_node(LNode *, int);       // ����--�ڵ�֮ǰ
LNode *Insert_node_head(LNode *, int);  // ����--�ڵ�֮��
LNode *delete_qian_0(LNode *);          // ɾ����λ��0
LNode *jinwei(LNode *);                 // ��λ
LNode *bianhao(LNode *);                // ���--����L���෴��
int compare_AB(LNode *, LNode *);       // �Ƚ�
LNode *node_jianum(LNode *, int, int);  // ����--ָ���ڵ�����ָ����ֵ
LNode *jia_fa(LNode *, LNode *);        // �ӷ�
LNode *jian_fa(LNode *, LNode *);       // ����
LNode *cheng_fa(LNode *, LNode *);      // �˷�
LNode *chu_fa(LNode *, LNode *, int &); // ����

// ������
int main()
{
    int choose;
    char x[max];
    // memset(x, '\0', max);
    LNode *shu1, *shu2, *jieguo;
    shu1 = InitLink();
    shu2 = InitLink();
    jieguo = InitLink();
    while (1)
    {
        strcpy(x, menu());
        if (x[0] < '0' && x[0] > '6')
            choose = 7;
        else
        {
            if (x[1] >= '0' && x[1] <= '9')
                choose = 7;
            else
                choose = x[0] - '0';
        }
        switch (choose)
        {
        case 1: // ����
        {
            printf("�������һ������:\n");
            shu1 = Inputlist();
            printf("������ڶ�������:\n");
            shu2 = Inputlist();
            break;
        }
        case 2: // �ӷ�����
        {
            jieguo = jia_fa(shu1, shu2);
            printf("�ӷ�����������:\n");
            Outputlist(shu1);
            printf("+\n");
            Outputlist(shu2);
            printf("=\n");
            Outputlist(jieguo);
            break;
        }
        case 3: // ��������
        {
            jieguo = jian_fa(shu1, shu2);
            printf("��������������:\n");
            Outputlist(shu1);
            printf("-\n");
            Outputlist(shu2);
            printf("=\n");
            Outputlist(jieguo);
            break;
        }
        case 4: // �˷�����
            jieguo = cheng_fa(shu1, shu2);
            printf("�˷�����������:\n");
            Outputlist(shu1);
            printf("*\n");
            Outputlist(shu2);
            printf("=\n");
            Outputlist(jieguo);
            break;
        case 5: // ��������
        {
            char num_chufa[10] = "10000000";
            int f_chu;
            f_chu = compare_AB(cheng_fa(shu2, Inputlist_char(num_chufa)), shu1);
            if (f_chu == 3)
            {
                printf("�������ܼ��㣡\n");
                printf("ע��:���������ô��ڳ�����1000,0000����\n");
                break;
            }
            printf("��������������:\n");
            if (shu2->next->num == 0 && (shu1->num == 1 || shu1->num == -1))
            {
                printf("��������Ϊ0��\n");
                break;
            }
            if (shu1->next->num == 0 && (shu1->num == 1 || shu1->num == -1))
            {
                Outputlist(shu1);
                printf("/\n");
                Outputlist(shu2);
                printf("=\n");
                printf("0\n");
                printf("......\n0\n");
                break;
            }
            LNode *yushu = InitLink(), *shang_chufa = InitLink();
            int chufa_jieguo_int;
            char chufa_jieguo_char[max];
            yushu = chu_fa(shu1, shu2, chufa_jieguo_int);
            sprintf(chufa_jieguo_char, "%d", chufa_jieguo_int);
            Outputlist(shu1);
            printf("/\n");
            Outputlist(shu2);
            printf("=\n");
            Outputlist(Inputlist_char(chufa_jieguo_char));
            printf("......\n");
            Outputlist(yushu);
            break;
        }
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
    free(shu1);
    free(shu2);
    free(jieguo);
    return 0;
}

// �˵�
char *menu()
{
    char *choose = (char *)malloc(max * sizeof(char));
    memset(choose, '\0', max);
    printf("*****************************************\n");
    printf("*********     �������������    *********\n");
    printf("*****************************************\n");
    printf("******        1----��������        ******\n");
    printf("******        2----�ӷ�����        ******\n");
    printf("******        3----��������        ******\n");
    printf("******        4----�˷�����        ******\n");
    printf("******        5----��������        ******\n");
    printf("******        6----�������        ******\n");
    printf("******        0----�˳�ϵͳ        ******\n");
    printf("*****************************************\n");
    printf("���������ѡ��:(0-6)\n");
    scanf("%s", choose);
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

// �洢����--��L�ڵ�ǰ����һ���½ڵ�
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

// �洢����--��L�ڵ�����һ���½ڵ�
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
    char y[max1];
    LNode *head;
    i = 0;
    getchar();
    scanf("%s", y);
    head = InitLink();
    LNode *L = head;
    i = 0;
    j = 0;
    while ((y[i] >= '0' && y[i] <= '9') || y[i] == '-' || y[i] == ',')
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
            head = Insert_node_head(L, sum); // ��λ��ͷ�ڵ����head->��->ʮ->��
            i = j;
        }
        else
        {
            i++;
        }
    }
    if (y[0] == '-')
        head->num = -head->num;
    head = delete_qian_0(head);
    return head;
}

// ����--���ַ�����yת��Ϊ����
LNode *Inputlist_char(char y[max])
{
    int i, j, sum, y_long;
    LNode *head;
    i = 0;
    head = InitLink();
    y_long = strlen(y);
    i = y_long - 1;
    j = 0;
    while (((y[i] >= '0' && y[i] <= '9') || y[i] == '-' || y[i] == ',') && i >= 0)
    {
        if (y[i] >= '0' && y[i] <= '9')
        {
            sum = 0;
            for (j = i; j > i - 4; j--)
            {
                if (y[j] >= '0' && y[j] <= '9')
                    sum = sum + int((y[j] - '0') * pow(10, i - j));
                else
                    break;
            }
            head = Insert_node(head, sum);
            i = j;
        }
        else
        {
            i--;
        }
    }
    if (y[0] == '-')
        head->num = -head->num;
    head = delete_qian_0(head);
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

// ɾ�����λ��0
LNode *delete_qian_0(LNode *L)
{
    LNode *head = L, *p = L->first, *q = L->first->first;
    if (head->num == 0)
        return head;
    while (head->first->num == 0 && abs(head->num) > 1)
    {
        q->next = head;
        head->first = q;
        if (head->num >= 0)
            head->num--;
        else
            head->num++;
        p = head->first;
        q = head->first->first;
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
    if (a > b) // a��λ����
        return 1;
    if (b < a) // b��λ����
        return 3;
    while (A->first != shu1)
    {
        A = A->first;
        B = B->first;
        if (A->num > B->num)
            return 1;
        if (A->num < B->num)
            return 3;
    }
    return 2;
}

// ����--L����next����ĵ�i���ڵ��num��x
LNode *node_jianum(LNode *L, int i, int x)
{
    if (L->num < i)
        return L;
    LNode *head = L;
    int a = abs(L->num), j;
    for (j = 1; j <= a; j++)
    {
        head = head->next;
        if (i == j)
        {
            head->num = head->num + x;
            break;
        }
    }
    return jinwei(L);
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
        return jian_fa(shu1, bianhao(shu2)); // a>0,b<0,a+b=a-(-b)
    }
    if (A->num < 0 && B->num > 0)
    {
        return jian_fa(shu2, bianhao(shu1)); // a<0,b>0,a+b=b-(a)
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
        if (flag_i == i && flag_j == j) // a,bÿһλ������ɣ�����
            break;
        if (i == j)
        { // a,bͬλ���
            num = A->num + B->num;
            Insert_node(jieguo, num);
        }
        if (i > j)
        { // a���λ���Ĵ���
            Insert_node(jieguo, A->num);
        }
        if (i < j)
        { // b���λ���Ĵ���
            Insert_node(jieguo, B->num);
        }
    }
    jieguo = jinwei(jieguo); // ��λ����
    if (A->next->num < 0)
    { // a,b��Ϊ����������Ӹ���
        jieguo->num = -jieguo->num;
    }
    return delete_qian_0(jieguo);
}

// ��������
LNode *jian_fa(LNode *shu1, LNode *shu2)
{

    LNode *jieguo = InitLink(), *A = shu1, *B = shu2, *A2, *B2;
    if (compare_AB(shu1, shu2) == 2)
        return Insert_node(jieguo, 0);
    int flag_bianhao = 0;
    // ab���
    if (A->num > 0 && B->num < 0)
    {
        return jia_fa(A, bianhao(B)); // a>0,b<0,a-b=a+(-b)
    }
    if (A->num < 0 && B->num > 0)
    {
        return jia_fa(A, bianhao(B)); // a<0,b>0,a-b=a+(-b);
    }
    // abͬ��
    if (compare_AB(shu1, shu2) == 3)
    { // A2�Ǿ���ֵ�����һ������
        A2 = shu2;
        B2 = shu1;
        flag_bianhao = 1;
    } //|b|-|a|,����Ӹ���
    else
    {
        A2 = shu1;
        B2 = shu2;
    } //|a|-|b|
    int i, j, a, b, num, flag_jiewei = 0, flag_i, flag_j;
    a = abs(A2->num);
    b = abs(B2->num);
    for (i = 0, j = 0; i <= a && j <= b;)
    {
        flag_i = i;
        flag_j = j;
        if (i < a)
        {
            i++;
            A2 = A2->next;
        }
        if (j < b)
        {
            j++;
            B2 = B2->next;
        }
        if (flag_i == i && flag_j == j) // a,bÿһλ������ɣ�����
            break;
        if (i == j)
        {
            if (flag_jiewei == 0) // ���ڵ�λδ��λ
                num = A2->num - B2->num;
            else // ���ڵ�λ��λ����λ��һ
                num = A2->num - B2->num - 1;
            if (num < 0)
            { // �����ڸ�λ��λ
                flag_jiewei = 1;
                num = num + 10000;
            }
            else // ����λ
                flag_jiewei = 0;
            Insert_node(jieguo, num);
        }
        if (i > j)
        { // |A2|�󣬶��λ���Ĵ���
            if (flag_jiewei == 1)
            { // ��λ����
                if (A2->num - 1 < 0)
                {
                    Insert_node(jieguo, A2->num + 9999);
                    flag_jiewei = 1;
                }
                else
                {
                    Insert_node(jieguo, A2->num - 1);
                    flag_jiewei = 0;
                }
            }
            else
            {
                if (A2->num < 0)
                {
                    Insert_node(jieguo, A2->num + 10000);
                    flag_jiewei = 1;
                }
                else
                {
                    Insert_node(jieguo, A2->num);
                    flag_jiewei = 0;
                }
            }
        }
    }
    if (flag_bianhao)
    { // shu1 < shu2 ���Ҫ�Ӹ���
        jieguo->num = -jieguo->num;
    }
    return delete_qian_0(jieguo);
}

// �˷�����
LNode *cheng_fa(LNode *shu1, LNode *shu2)
{
    int flag_cheng = shu1->num * shu2->num, i, j, a, b;
    LNode *jieguo, *A = shu1, *B = shu2;
    jieguo = InitLink();
    a = abs(shu1->num);
    b = abs(shu2->num);
    for (i = 1; i < a + b; i++)
    {
        jieguo = Insert_node_head(jieguo, 0);
    }
    for (i = 1; i <= a; i++)
    {
        A = A->next;
        B = shu2;
        for (j = 1; j <= b; j++)
        {
            B = B->next;
            jieguo = node_jianum(jieguo, i + j - 1, A->num * B->num);
        }
    }
    jinwei(jieguo);
    if (flag_cheng < 0)
    {
        jieguo->num = -jieguo->num;
    }
    return jieguo;
}

// ��������
LNode *chu_fa(LNode *shu1, LNode *shu2, int &num)
{
    LNode *A, *B, *yushu = InitLink();
    int flag_yushu = 0, flag_jieguo = shu1->num * shu2->num;
    if (shu1->num < 0)
    {
        A = bianhao(shu1);
        flag_yushu = 1;
    }
    else
    {
        A = shu1;
    }
    if (shu2->num < 0)
    {
        B = bianhao(shu2);
    }
    else
    {
        B = shu2;
    }
    switch (compare_AB(A, B))
    {
    case 1: // a>b
    {
        yushu = jian_fa(A, B);
        num = 1;
        while (compare_AB(yushu, B) != 3)
        {
            yushu = jian_fa(yushu, B);
            num++;
        }
        break;
    }
    case 2: // a=b,a/b=1��0
    {
        num = 1;
        yushu = jian_fa(A, B);
        break;
    }
    case 3: // a<b,a/b=0��a
    {
        num = 0;
        yushu = A;
        break;
    }
    }
    if (flag_jieguo > 0)
        num = num;
    else
        num = -num;
    if (flag_yushu == 1)
        yushu = bianhao(yushu);
    return yushu;
}
