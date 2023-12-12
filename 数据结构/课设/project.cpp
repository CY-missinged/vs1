#define _CRT_SECURE_NO_WARNINGS
// encoding=GBK
// 必做内容为设计一个实现任意长的整数进行加法运算的演示程序；
// 选做内容为实现长整数的四则运算。
// 要求利用双向循环链表实现长整数的存储，每个结点含一个整型变量,整型变量的范围是－(2^15-l)~(2^15-1)
// 即原长整数划分时每 4 位一组，对应一个结点进行存储。
// 加法必做，双向循环链表

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef int Datatype;

// 链表节点
struct LNode
{
    Datatype num;        // 数据域
    LNode *first, *next; // 指针域
};

int menu();                            // 菜单
LNode *jia_fa(LNode *, LNode *);       // 加法
LNode *jian_fa(LNode *, LNode *);      // 减法
LNode *InitLink();                     // 创建一个空表
LNode *Inputlist();                    // 输入
void Outputlist(LNode *);              // 输出
LNode *Insert_node(LNode *, int);      // 插入--L节点之后
LNode *Insert_node_head(LNode *, int); // 插入--头节点之后
LNode *jinwei(LNode *);                // 进位
LNode *bianhao(LNode *);               // 返回L的相反数
int compare_AB(LNode *, LNode *);

// 主函数
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
        case 1: // 输入
        {
            printf("请输入第一个数字:\n");
            shu1 = Inputlist();
            printf("请输入第二个数字:\n");
            shu2 = Inputlist();
            printf("\n\n%d\n", compare_AB(shu1, shu2));
            break;
        }
        case 2: // 加法运算
        {
            jieguo = jia_fa(shu1, shu2);
            printf("第一个数字为:\n");
            Outputlist(shu1);
            printf("第二个数字为:\n");
            Outputlist(shu2);
            printf("加法运算结果如下:\n");
            Outputlist(jieguo);
            break;
        }
        case 3: // 减法运算
        {
            jieguo = jian_fa(shu1, shu2);
            printf("第一个数字为:\n");
            Outputlist(shu1);
            printf("第二个数字为:\n");
            Outputlist(shu2);
            printf("减法运算结果如下:\n");
            Outputlist(jieguo);
            break;
        }
        case 4: // 乘法运算
            break;
        case 5: // 除法运算
            break;
        case 6: // 输出
        {
            printf("第一个数字为:\n");
            Outputlist(shu1);
            printf("第二个数字为:\n");
            Outputlist(shu2);
            break;
        }
        case 0: // 退出
        {
            printf("感谢使用本程序,再见!\n");
            break;
        }
        default:
            printf("输入错误,请重新输入!\n");
        }
        if (choose == 0)
            break;
        system("pause");
        system("cls");
    }
    return 0;
}

// 菜单
int menu()
{
    int choose;
    printf("**********************\n");
    printf("****长整数计算程序****\n");
    printf("**********************\n");
    printf("*   1----输入数字    *\n");
    printf("*   2----加法运算    *\n");
    printf("*   3----减法运算    *\n");
    printf("*   4----乘法运算    *\n");
    printf("*   5----除法运算    *\n");
    printf("*   6----输出数字    *\n");
    printf("*   0----退出系统    *\n");
    printf("**********************\n");
    printf("请输入你的选择:(0-6)\n");
    scanf("%d", &choose);
    return choose;
}

// 初始化链表--返回一个空的双向循环链表
LNode *InitLink()
{
    LNode *head = (LNode *)malloc(sizeof(LNode));
    head->next = head;
    head->first = head;
    head->num = 0;
    return head;
}

// 存储数据--在节点L后插入一个新节点
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

// 输入
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

// 输出--逆序输出
void Outputlist(LNode *head)
{
    LNode *p = head;
    int flag = 0;
    if (p->next == head && p->first == head)
    {
        printf("你还没有输入数字\n");
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

// 进位
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

// 变号--返回L的相反数
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

// 绝对值比较--|a|>|b|,返回1,|a|==|b|,返回2，|a|<|b|,返回3
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

// 加法运算
LNode *jia_fa(LNode *shu1, LNode *shu2)
{
    LNode *jieguo, *A = shu1, *B = shu2;
    int i, j, a, b, num, flag_i, flag_j;
    jieguo = InitLink();
    // ab异号
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
    // ab同号
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

// 减法运算
LNode *jian_fa(LNode *shu1, LNode *shu2)
{
    LNode *jieguo, *A = shu1, *B = shu2;
    jieguo = InitLink();
    // ab异号
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
    // ab同号
    // if (compare_AB())
    {
        jieguo->num = -jieguo->num;
    }
    return jieguo;
}
