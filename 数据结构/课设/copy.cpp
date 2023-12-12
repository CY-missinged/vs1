#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <conio.h>

/**双向循环链表的结构体定义**/
typedef struct Node
{
    int data;
    struct Node *pre, *next;
} Node, *LinkList;

/*****函数声明*****/
int GetNum(LinkList &L);  // 读取一个数
void Output(LinkList &L); // 输出
// 以上2个函数 根据输入要求修改即可
void InitList(LinkList &L);                    // 初始化一个双向循环链表(存放一个大数)
void Add(LinkList a, LinkList b, LinkList &c); // a+b=c
void Sub(LinkList a, LinkList b, LinkList &c); // a-b=c
void Mul(LinkList a, LinkList b, LinkList &c); // a*b=c
void Div(LinkList a, LinkList b, LinkList &c); // a/b=c
// 以上5个函数 供用户调用
void ListInsert(LinkList &L, int x); // 在链表尾部插入一个值为x的结点
void ListDelete(LinkList &L);        // 删去链表尾节点即高位
void Adjust(LinkList &L);            // 对一个链表位调整
int Compare(LinkList a, LinkList b); // 比较两个数的绝对值大小
// 以上4个函数 是函数间调用不用管

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
        if (abs(b->data) == 1 && b->next->data == 0) // b为0
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

void InitList(LinkList &L) // 初始化一个双向循环链表
{
    // 表头结点数据域的符号代表长整数的符号
    // 其绝对值表示元素结点数目
    L = (LinkList)malloc(sizeof(Node));
    L->data = 0;
    L->next = L;
    L->pre = L;
}

void ListInsert(LinkList &L, int x) // 在链表尾部插入一个值为x的结点
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

void ListDelete(LinkList &L) // 删去链表尾节点即高位
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

void Adjust(LinkList &L) // 对一个链表进行调整
{
    LinkList p = L->next;
    while (p != L)
    {
        while (p->data > 9999) // 处理进位
        {
            if (p->next == L)
                ListInsert(L, 0);
            p->next->data += p->data / 10000;
            p->data %= 10000;
        }
        p = p->next;
    }
    while (L->pre->data == 0 && abs(L->data) > 1)
        ListDelete(L); // 处理前导零
}

int Compare(LinkList a, LinkList b) // 比较两个数的绝对值大小a>b返回1 a=b返回2 a<b返回0
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
    if (a->data * b->data > 0) // ab同号
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
                if (p->data < q->data) // 不够减则向上借位
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
                c->data = -c->data; // 绝对值较大者确定符号
            break;
        }

        case 0: // a<b
        {
            LinkList p = a->next, q = b->next;
            while (p != a && q != b)
            {
                if (q->data < p->data) // 不够减则向上借位
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
    Adjust(c); // 处理进位
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
        ListInsert(c, 0); // AB中有一个数为0
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
        c->data = -c->data; // ab异号
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
        ListInsert(c, 0); // 商的最大位数
    int flag = 0;         // b为负数时转正
    if (b->data < 0)
    {
        b->data = -b->data;
        flag = 1;
    }

    LinkList tmp;
    InitList(tmp);
    for (LinkList t = c->pre, p = a->pre; t != c; t = t->pre, p = p->pre)
    {
        LinkList q = (LinkList)malloc(sizeof(Node)); // 将a高位部分拷给tmp
        q->data = p->data, q->next = tmp->next, q->pre = tmp;
        tmp->next->pre = q, tmp->next = q;
        tmp->data++;

        while (Compare(tmp, b)) // 把除法转换为从高到低的减法
        {
            t->data++;
            LinkList r; // 余数
            InitList(r);
            Sub(tmp, b, r);
            while (tmp->data != 0)
                ListDelete(tmp);
            InitList(tmp);
            for (LinkList p = r->next; p != r; p = p->next)
                ListInsert(tmp, p->data); // 把r拷给tmp，相当于tmp-=b
        }
    }

    if (flag)
        b->data = -b->data;
    if (a->data * b->data < 0)
        c->data = -c->data; // ab异号
    Adjust(c);
}

int GetNum(LinkList &L) // 读取一个数
{
    char ss[100005];
    int sum = 0;
    scanf("%[^\n]", ss);
    getchar();
    for (int i = 0; i < strlen(ss); i++) // 如果出现非数字且不是第一个正负号
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
void Output(LinkList &L) // 输出
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
