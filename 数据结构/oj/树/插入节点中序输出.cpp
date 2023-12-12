// ��һ����㲻�ظ��Ķ����������������������Ϊһ���������У�
// ��������в��뺯��InsertBST()��
// ʹ�ò���һ��ָ�����½��󣬶��������������Ϊ�������С�

// ������������������������㷨�����ö���������ʾ������������
// Ȼ�����������Ľ�㡣����ý����ԭ�������д���ʱ������ʧ�ܣ�����0��
// ���������ֲ��䣬���򽫸ý������ʵ�λ�ã���������1��
// ʹ���������������������Ϊ�������С����۲���ɹ����
// ��������������������������

// ע�⣺�������������ֵ��Ϊ����Ӣ����ĸ�ַ���
// �����յ��Ľ������ֵ���ַ��� #��ʱ�����򴴽��������ĺ����ݹ������

#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode //��������������������
{
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

char InOrderTraverse(BiTree T) //��������������
{
    char a, b;
    if (!T)
        return 0;
    b = InOrderTraverse(T->lchild);
    if (b != NULL)
    {
        a = b;
        b = NULL;
    }
    printf("%c ", T->data);
    b = T->data;
    if (b != NULL)
    {
        a = b;
        b = NULL;
    }
    b = InOrderTraverse(T->rchild);
    if (b != NULL)
    {
        a = b;
        b = NULL;
    }
    return a;
}

int flag = 0;

int InsertBST(BiTree *T, char e) //����ֵΪe�Ľ�㣬ʹ���������Ϊ����
{
    BiTree T2, t;
    T2 = (BiTree)malloc(sizeof(BiTNode));
    t = (*T)->lchild;
    if ((*T) == NULL)
    {
        return 0;
    }
    if ((*T)->lchild != NULL && InsertBST(&(*T)->lchild, e) == 1)
        return 1;
    if (e == ((*T)->data))
    {
        flag = 1;
    }
    if (e < (*T)->data && flag == 0)
    {
        T2->data = e;
        T2->lchild = t;
        T2->rchild = NULL;
        (*T)->lchild = T2;
        return 1;
    }
    if ((*T)->rchild != NULL && InsertBST(&(*T)->rchild, e) == 1)
        return 1;
}

void PreOrderCreate(struct BiTNode **p) //�����������������
{
    char a;
    scanf("%c", &a);
    if (a == '#')
        *p = NULL; //�����յ��Ľ��ֵΪ��#��ʱ���ݹ���̽���
    else
    {
        *p = (struct BiTNode *)malloc(sizeof(struct BiTNode));
        (*p)->data = a;
        PreOrderCreate(&(*p)->lchild);
        PreOrderCreate(&(*p)->rchild);
    }
}

int main()
{
    BiTree root = NULL;
    char ch, a;
    PreOrderCreate(&root);
    getchar();
    scanf("%c", &ch);
    if (root == NULL)
        printf("%c ", ch);
    InsertBST(&root, ch);
    a = InOrderTraverse(root);
    // printf("**%c**", a);
    if (a < ch && a != NULL)
        printf("%c ", ch);
    printf("\n");
    return 0;
}
