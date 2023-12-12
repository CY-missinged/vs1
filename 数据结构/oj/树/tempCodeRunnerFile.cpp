// 有一个结点不重复的二叉树，它的中序遍历序列为一个升序序列，
// 试完成下列插入函数InsertBST()，
// 使得插入一个指定的新结点后，二叉树中序遍历仍为升序序列。

// 主函数中首先利用先序遍历算法创建该二叉树并显示中序遍历结果，
// 然后输入需插入的结点。如果该结点在原二叉树中存在时，插入失败，返回0，
// 二叉树保持不变，否则将该结点插入适当位置，函数返回1，
// 使插入后二叉树的中序遍历仍为升序序列。不论插入成功与否，
// 主函数中最后都输出中序遍历结果。

// 注意：二叉树结点数据值均为单个英文字母字符。
// 当接收到的结点数据值是字符“ #”时，先序创建二叉树的函数递归结束。

#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode //定义二叉树结点数据类型
{
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int flag = 1;

void InOrderTraverse(BiTree T, char e) //中序遍历后二叉树
{
    if (!T)
        return;
    InOrderTraverse(T->lchild, e);
    if (e < T->data&&flag==1)
    {
        flag=2;
        printf("%c ", e);
    }
    printf("%c ", T->data);
    InOrderTraverse(T->rchild, e);
}

// int InsertBST(BiTree *T, char e) //插入值为e的结点，使中序遍历仍为升序
// {
//     BiTree T2 ,t;
//     T2=(BiTree)malloc(sizeof(BiTNode));
//     t=(*T)->lchild;
//     if ((*T)==NULL)
//     {
//         return 0;
//     }
//     if ((*T)->lchild != NULL && InsertBST(&(*T)->lchild, e) == 1)
//         return 1;
//     if (e < (*T)->data)
//     {
//         T2->data=e;
//         T2->lchild = t;
//         T2->rchild=NULL;
//         (*T)->lchild = T2;
//         return 1;
//     }
//     if ((*T)->rchild != NULL && InsertBST(&(*T)->rchild, e) == 1)
//         return 1;
// }

void PreOrderCreate(struct BiTNode **p) //先序遍历创建二叉树
{
    char a;
    scanf("%c", &a);
    if (a == '#')
        *p = NULL; //当接收到的结点值为’#’时，递归过程结束
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
    char ch;
    PreOrderCreate(&root);
    getchar();
    scanf("%c", &ch);
    // InsertBST(&root, ch);
    InOrderTraverse(root, ch);
    printf("\n");
    return 0;
}
