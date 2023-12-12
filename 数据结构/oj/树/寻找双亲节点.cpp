#include <stdio.h>
#include <stdlib.h>

struct BTNode
{
    char data;
    struct BTNode *lchild;
    struct BTNode *rchild;
};

void PreOrderCreate(struct BTNode **p) //先序遍历创建二叉树
{
    char a;
    scanf("%c", &a);
    if (a == '#')
        *p = NULL;
    else
    {
        *p = (struct BTNode *)malloc(sizeof(struct BTNode));
        (*p)->data = a;
        PreOrderCreate(&(*p)->lchild);
        PreOrderCreate(&(*p)->rchild);
    }
}

struct BTNode *p = NULL;

void SearchParents(struct BTNode *t, char x) //此处添加查找二叉树指定结点的双亲结点函数
{
    struct BTNode *a;
    if (t != NULL)
    {
        if (t->lchild != NULL)
        {
            if (t->lchild->data == x)
            {
                p = t;
                return;
            }
        }
        if (t->rchild != NULL)
        {
            if (t->rchild->data == x)
            {
                p = t;
                return;
            }
        }
        a = t->lchild;
        SearchParents(a, x);
        a = t->rchild;
        SearchParents(a, x);
    }
}

int main()
{
    struct BTNode *t;
    char x;
    PreOrderCreate(&t);
    getchar();
    scanf("%c", &x);
    SearchParents(t, x);
    if (p == NULL)
        printf("#");
    else
        printf("%c", p->data);
    return 0;
}
