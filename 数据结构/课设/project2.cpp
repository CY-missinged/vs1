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

#define max 100
#define max1 100
typedef int Datatype;

// 链表节点
struct LNode
{
    Datatype num;        // 数据域
    LNode *first, *next; // 指针域
};

char *menu(); // 菜单

LNode *InitLink();                      // 初始化--创建一个空表
LNode *Inputlist();                     // 输入
LNode *Inputlist_char(char[]);          // 输入--除法的商变为链表
void Outputlist(LNode *);               // 输出
LNode *Insert_node(LNode *, int);       // 插入--节点之前
LNode *Insert_node_head(LNode *, int);  // 插入--节点之后
LNode *delete_qian_0(LNode *);          // 删除高位的0
LNode *jinwei(LNode *);                 // 进位
LNode *bianhao(LNode *);                // 变号--返回L的相反数
int compare_AB(LNode *, LNode *);       // 比较
LNode *node_jianum(LNode *, int, int);  // 增加--指定节点增加指定数值
LNode *jia_fa(LNode *, LNode *);        // 加法
LNode *jian_fa(LNode *, LNode *);       // 减法
LNode *cheng_fa(LNode *, LNode *);      // 乘法
LNode *chu_fa(LNode *, LNode *, int &); // 除法

// 主函数
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
        case 1: // 输入
        {
            printf("请输入第一个数字:\n");
            shu1 = Inputlist();
            printf("请输入第二个数字:\n");
            shu2 = Inputlist();
            break;
        }
        case 2: // 加法运算
        {
            jieguo = jia_fa(shu1, shu2);
            printf("加法运算结果如下:\n");
            Outputlist(shu1);
            printf("+\n");
            Outputlist(shu2);
            printf("=\n");
            Outputlist(jieguo);
            break;
        }
        case 3: // 减法运算
        {
            jieguo = jian_fa(shu1, shu2);
            printf("减法运算结果如下:\n");
            Outputlist(shu1);
            printf("-\n");
            Outputlist(shu2);
            printf("=\n");
            Outputlist(jieguo);
            break;
        }
        case 4: // 乘法运算
            jieguo = cheng_fa(shu1, shu2);
            printf("乘法运算结果如下:\n");
            Outputlist(shu1);
            printf("*\n");
            Outputlist(shu2);
            printf("=\n");
            Outputlist(jieguo);
            break;
        case 5: // 除法运算
        {
            char num_chufa[10] = "10000000";
            int f_chu;
            f_chu = compare_AB(cheng_fa(shu2, Inputlist_char(num_chufa)), shu1);
            if (f_chu == 3)
            {
                printf("本程序不能计算！\n");
                printf("注意:被除数不得大于除数的1000,0000倍。\n");
                break;
            }
            printf("除法运算结果如下:\n");
            if (shu2->next->num == 0 && (shu1->num == 1 || shu1->num == -1))
            {
                printf("除数不能为0！\n");
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
    free(shu1);
    free(shu2);
    free(jieguo);
    return 0;
}

// 菜单
char *menu()
{
    char *choose = (char *)malloc(max * sizeof(char));
    memset(choose, '\0', max);
    printf("*****************************************\n");
    printf("*********     长整数计算程序    *********\n");
    printf("*****************************************\n");
    printf("******        1----输入数字        ******\n");
    printf("******        2----加法运算        ******\n");
    printf("******        3----减法运算        ******\n");
    printf("******        4----乘法运算        ******\n");
    printf("******        5----除法运算        ******\n");
    printf("******        6----输出数字        ******\n");
    printf("******        0----退出系统        ******\n");
    printf("*****************************************\n");
    printf("请输入你的选择:(0-6)\n");
    scanf("%s", choose);
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

// 存储数据--在L节点前插入一个新节点
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

// 存储数据--在L节点后插入一个新节点
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
            head = Insert_node_head(L, sum); // 低位离头节点近，head->个->十->百
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

// 输入--将字符数组y转换为链表
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

// 删除最高位的0
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
    if (a > b) // a的位数多
        return 1;
    if (b < a) // b的位数多
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

// 增加--L链表next方向的第i个节点的num加x
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

// 加法运算
LNode *jia_fa(LNode *shu1, LNode *shu2)
{
    LNode *jieguo, *A = shu1, *B = shu2;
    int i, j, a, b, num, flag_i, flag_j;
    jieguo = InitLink();
    // ab异号
    if (A->num > 0 && B->num < 0)
    {
        return jian_fa(shu1, bianhao(shu2)); // a>0,b<0,a+b=a-(-b)
    }
    if (A->num < 0 && B->num > 0)
    {
        return jian_fa(shu2, bianhao(shu1)); // a<0,b>0,a+b=b-(a)
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
        if (flag_i == i && flag_j == j) // a,b每一位遍历完成，结束
            break;
        if (i == j)
        { // a,b同位相加
            num = A->num + B->num;
            Insert_node(jieguo, num);
        }
        if (i > j)
        { // a多出位数的处理
            Insert_node(jieguo, A->num);
        }
        if (i < j)
        { // b多出位数的处理
            Insert_node(jieguo, B->num);
        }
    }
    jieguo = jinwei(jieguo); // 进位处理
    if (A->next->num < 0)
    { // a,b均为负数，结果加负号
        jieguo->num = -jieguo->num;
    }
    return delete_qian_0(jieguo);
}

// 减法运算
LNode *jian_fa(LNode *shu1, LNode *shu2)
{

    LNode *jieguo = InitLink(), *A = shu1, *B = shu2, *A2, *B2;
    if (compare_AB(shu1, shu2) == 2)
        return Insert_node(jieguo, 0);
    int flag_bianhao = 0;
    // ab异号
    if (A->num > 0 && B->num < 0)
    {
        return jia_fa(A, bianhao(B)); // a>0,b<0,a-b=a+(-b)
    }
    if (A->num < 0 && B->num > 0)
    {
        return jia_fa(A, bianhao(B)); // a<0,b>0,a-b=a+(-b);
    }
    // ab同号
    if (compare_AB(shu1, shu2) == 3)
    { // A2是绝对值大的那一个数字
        A2 = shu2;
        B2 = shu1;
        flag_bianhao = 1;
    } //|b|-|a|,结果加负号
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
        if (flag_i == i && flag_j == j) // a,b每一位遍历完成，结束
            break;
        if (i == j)
        {
            if (flag_jiewei == 0) // 相邻低位未借位
                num = A2->num - B2->num;
            else // 相邻低位借位，本位减一
                num = A2->num - B2->num - 1;
            if (num < 0)
            { // 向相邻高位借位
                flag_jiewei = 1;
                num = num + 10000;
            }
            else // 不借位
                flag_jiewei = 0;
            Insert_node(jieguo, num);
        }
        if (i > j)
        { // |A2|大，多出位数的处理
            if (flag_jiewei == 1)
            { // 借位处理
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
    { // shu1 < shu2 结果要加负号
        jieguo->num = -jieguo->num;
    }
    return delete_qian_0(jieguo);
}

// 乘法运算
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

// 除法运算
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
    case 2: // a=b,a/b=1余0
    {
        num = 1;
        yushu = jian_fa(A, B);
        break;
    }
    case 3: // a<b,a/b=0余a
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
