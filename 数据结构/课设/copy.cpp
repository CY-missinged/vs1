#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <conio.h>

/**˫��ѭ������Ľṹ�嶨��**/
typedef struct Node
{
    int data;
    struct Node *pre, *next;
} Node, *LinkList;

/*****��������*****/
int GetNum(LinkList &L);  // ��ȡһ����
void Output(LinkList &L); // ���
// ����2������ ��������Ҫ���޸ļ���
void InitList(LinkList &L);                    // ��ʼ��һ��˫��ѭ������(���һ������)
void Add(LinkList a, LinkList b, LinkList &c); // a+b=c
void Sub(LinkList a, LinkList b, LinkList &c); // a-b=c
void Mul(LinkList a, LinkList b, LinkList &c); // a*b=c
void Div(LinkList a, LinkList b, LinkList &c); // a/b=c
// ����5������ ���û�����
void ListInsert(LinkList &L, int x); // ������β������һ��ֵΪx�Ľ��
void ListDelete(LinkList &L);        // ɾȥ����β�ڵ㼴��λ
void Adjust(LinkList &L);            // ��һ������λ����
int Compare(LinkList a, LinkList b); // �Ƚ��������ľ���ֵ��С
// ����4������ �Ǻ�������ò��ù�

int main()
{
    LinkList a, b, c;
    InitList(a);
    InitList(b);
    InitList(c);
    printf("Input number_A, end with ENTER\n");
    if (!GetNum(a))
    {
        printf("EORROR:wrong number\n");
        return 0;
    }
    // debug(a);
    // Output(a);
    printf("Input number_B, end with ENTER\n");
    if (!GetNum(b))
    {
        printf("EORROR:wrong number\n");
        return 0;
    }
    printf("Select an operation\n");
    printf("[1] +\n[2] -\n[3] *\n[4] /\n");
    char op = getch();
    switch (op)
    {
    case '1':
        printf("A + B = ");
        Add(a, b, c);
        Output(c);
        break;
    case '2':
        printf("A - B = ");
        Sub(a, b, c);
        Output(c);
        break;
    case '3':
        printf("A * B = ");
        Mul(a, b, c);
        Output(c);
        break;
    case '4':
        printf("A / B = ");
        if (abs(b->data) == 1 && b->next->data == 0) // bΪ0
        {
            printf("EORROR:denominator zero\n");
            return 0;
        }
        Div(a, b, c);
        Output(c);
        break;
    default:
    {
        printf("EORROR:wrong operation\n");
        return 0;
    }
    }
    system("pause");
    return 0;
}

void InitList(LinkList &L) // ��ʼ��һ��˫��ѭ������
{
    // ��ͷ���������ķ��Ŵ��������ķ���
    // �����ֵ��ʾԪ�ؽ����Ŀ
    L = (LinkList)malloc(sizeof(Node));
    L->data = 0;
    L->next = L;
    L->pre = L;
}

void ListInsert(LinkList &L, int x) // ������β������һ��ֵΪx�Ľ��
{
    LinkList p = (LinkList)malloc(sizeof(Node));
    LinkList q = L->pre;
    p->data = x;
    p->next = L;
    p->pre = q;
    q->next = p;
    L->pre = p;
    if (L->data >= 0)
        L->data++;
    else
        L->data--;
}

void ListDelete(LinkList &L) // ɾȥ����β�ڵ㼴��λ
{
    if (L->data == 0)
        return;
    LinkList p = L->pre;
    LinkList q = p->pre;
    q->next = L;
    L->pre = q;
    free(p);
    if (L->data >= 0)
        L->data--;
    else
        L->data++;
}

void Adjust(LinkList &L) // ��һ��������е���
{
    LinkList p = L->next;
    while (p != L)
    {
        while (p->data > 9999) // �����λ
        {
            if (p->next == L)
                ListInsert(L, 0);
            p->next->data += p->data / 10000;
            p->data %= 10000;
        }
        p = p->next;
    }
    while (L->pre->data == 0 && abs(L->data) > 1)
        ListDelete(L); // ����ǰ����
}

int Compare(LinkList a, LinkList b) // �Ƚ��������ľ���ֵ��Сa>b����1 a=b����2 a<b����0
{
    if (abs(a->data) != abs(b->data))
    {
        if (abs(a->data) > abs(b->data))
            return 1;
        else
            return 0;
    }
    LinkList p = a->pre, q = b->pre;
    while (p != a && q != b)
    {
        if (p->data != q->data)
        {
            if (p->data > q->data)
                return 1;
            else
                return 0;
        }
        p = p->pre;
        q = q->pre;
    }
    return 2;
}

void Add(LinkList a, LinkList b, LinkList &c) // a+b=c
{
    if (a->data * b->data > 0) // abͬ��
    {
        LinkList p = a->next, q = b->next;
        while (p != a && q != b)
        {
            ListInsert(c, p->data + q->data);
            p = p->next;
            q = q->next;
        }
        while (p != a)
        {
            ListInsert(c, p->data);
            p = p->next;
        }
        while (q != b)
        {
            ListInsert(c, q->data);
            q = q->next;
        }
        if (a->data < 0)
            c->data = -c->data;
    }
    else
    {
        switch (Compare(a, b))
        {
        case 2: // a==b abs
            ListInsert(c, 0);
            return;
        case 1: // a>b
        {
            LinkList p = a->next, q = b->next;
            while (p != a && q != b)
            {
                if (p->data < q->data) // �����������Ͻ�λ
                {
                    p->next->data--;
                    p->data += 10000;
                }
                ListInsert(c, p->data - q->data);
                p = p->next;
                q = q->next;
            }
            while (p != a)
            {
                ListInsert(c, p->data);
                p = p->next;
            }
            if (a->data < 0)
                c->data = -c->data; // ����ֵ�ϴ���ȷ������
            break;
        }

        case 0: // a<b
        {
            LinkList p = a->next, q = b->next;
            while (p != a && q != b)
            {
                if (q->data < p->data) // �����������Ͻ�λ
                {
                    q->next->data--;
                    q->data += 10000;
                }
                ListInsert(c, q->data - p->data);
                p = p->next;
                q = q->next;
            }
            while (q != b)
            {
                ListInsert(c, q->data);
                q = q->next;
            }
            if (b->data < 0)
                c->data = -c->data;
            break;
        }
        }
    }
    Adjust(c); // �����λ
}

void Sub(LinkList a, LinkList b, LinkList &c) // a-b=a+(-b)=c
{
    b->data = -b->data;
    Add(a, b, c);
    b->data = -b->data;
}

void Mul(LinkList a, LinkList b, LinkList &c) // a*b=c
{
    if (abs(a->data) == 1 && a->next->data == 0 || abs(b->data) == 1 && b->next->data == 0)
    {
        ListInsert(c, 0); // AB����һ����Ϊ0
        return;
    }
    for (int i = 1; i <= (abs(a->data) + abs(b->data)); i++)
        ListInsert(c, 0);
    LinkList p = a->next;
    for (int i = 1; p != a; p = p->next, i++)
    {
        LinkList q = b->next;
        for (int j = 1; q != b; q = q->next, j++)
        {
            int k = i + j - 1;
            LinkList t = c;
            while (k--)
                t = t->next;
            t->data += p->data * q->data;
        }
    }
    if (a->data * b->data < 0)
        c->data = -c->data; // ab���
    Adjust(c);
}

void Div(LinkList a, LinkList b, LinkList &c) // a/b=c
{
    if (Compare(a, b) == 0) // a<b,ans=0
    {
        ListInsert(c, 0);
        return;
    }
    for (int i = 1; i <= abs(a->data); i++)
        ListInsert(c, 0); // �̵����λ��
    int flag = 0;         // bΪ����ʱת��
    if (b->data < 0)
    {
        b->data = -b->data;
        flag = 1;
    }

    LinkList tmp;
    InitList(tmp);
    for (LinkList t = c->pre, p = a->pre; t != c; t = t->pre, p = p->pre)
    {
        LinkList q = (LinkList)malloc(sizeof(Node)); // ��a��λ���ֿ���tmp
        q->data = p->data, q->next = tmp->next, q->pre = tmp;
        tmp->next->pre = q, tmp->next = q;
        tmp->data++;

        while (Compare(tmp, b)) // �ѳ���ת��Ϊ�Ӹߵ��͵ļ���
        {
            t->data++;
            LinkList r; // ����
            InitList(r);
            Sub(tmp, b, r);
            while (tmp->data != 0)
                ListDelete(tmp);
            InitList(tmp);
            for (LinkList p = r->next; p != r; p = p->next)
                ListInsert(tmp, p->data); // ��r����tmp���൱��tmp-=b
        }
    }

    if (flag)
        b->data = -b->data;
    if (a->data * b->data < 0)
        c->data = -c->data; // ab���
    Adjust(c);
}

int GetNum(LinkList &L) // ��ȡһ����
{
    char ss[100005];
    int sum = 0;
    scanf("%[^\n]", ss);
    getchar();
    for (int i = 0; i < strlen(ss); i++) // ������ַ������Ҳ��ǵ�һ��������
        if (!(i == 0 && (ss[0] == '-' || ss[0] == '+')) && (!(ss[i] >= '0' && ss[i] <= '9')))
            return 0;
    int j = 0;
    for (int i = strlen(ss) - 1; i >= 0; i--)
    {
        if (ss[i] >= '0' && ss[i] <= '9')
        {
            j++;
            if (j == 4 || i == 0 || (i == 1) && ss[0] == '-')
            {
                int sum = 0;
                for (int k = i; k < i + j; k++)
                    sum = 10 * sum + (ss[k] - '0');
                ListInsert(L, sum);
                j = 0;
            }
        }
    }
    if (ss[0] == '-')
        L->data = -L->data;
    if (L->data == 0)
        return 0;
    Adjust(L);
    return 1;
}
void Output(LinkList &L) // ���
{
    LinkList p = L->pre;
    if (L->data < 0)
        printf("-");
    while (p != L)
    {
        if (p->next != L)
            printf("%04d", p->data);
        else
            printf("%d", p->data);
        if (p->pre != L)
            printf(",");
        p = p->pre;
    }
    printf("\n");
}
