请补充完善下面程序中实现二叉树创建的递归函数BSTCreatePreIn。

#include <stdio.h>

#include <stdlib.h>

#define N 8 //二叉树的结点总数

    typedef char DataType; //二叉树的结点值为char型

typedef struct node //二叉树结点类型定义

{
    DataType data;

    struct node *lchild, *rchild;

} BSTNode,*BiTree;

DataType p1[10], p2[10]; // pre和in数组分别用于保存二叉树先序和中序对应的结点值序列

// int PosInorder(DataType a[], DataType x) //确定值为x的结点在中序数组pre中的位置

// {
//     int i;

//     for (i = 0; i < N; i++)

//         if (a[i] == x)

//             return i;
// }

// //根据先序和中序遍历序列创建有n个结点的二叉树t
// BSTNode* BSTCreatePreIn(BSTNode **t, DataType *p1, DataType *p2, int n)
// // p1和p2分别指向当前二叉树先序和中序序列数组的首个结点值位置
// {
//     BiTree T;
//     int i;
//     if (n <= 0) return NULL;
//     T = (BiTree)malloc(sizeof(BSTNode));
//     T->data = p1[0];
//     for (i = 0; p2[i] != p1[0]; i++);
//     //找到中序遍历中与先序遍历中第一个相同元素的位置
//     //中序中前i个是左子树，后i个是右子树
//     T->lchild = CreatBinTree(p1 + 1, p2, i);
//     //建立右子树，后i个是右子树，所以中序的后i个是右子树，先序的后i个是右子树，看图就能看明白了
//     T->rchild = CreatBinTree(p1 + i + 1, p2 + i + 1, n - i - 1);
//     return T;
// }

void PostOrder(BSTNode *p) //后根遍历二叉树

{
    if (p != NULL)

    {
        PostOrder(p->lchild);

        PostOrder(p->rchild);

        printf("%c ", p->data);
    }
}

int main()

{
    BSTNode *root;

    root = NULL;

    gets(p1);

    gets(p2);

    BSTCreatePreIn(&root, p1, p2, N);

    PostOrder(root);

    return 0;
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char ElementType;
typedef struct BiTNode {
    ElementType data;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
}BiTNode, * BiTree;

BiTree CreatBinTree(char* pre, char* in, int n);
void postorder(BiTree T);

int main()
{
    BiTree T;
    char prelist[100];
    char inlist[100];
    int length;
    scanf("%s", prelist);
    scanf("%s", inlist);
    length = strlen(prelist);
    T = CreatBinTree(prelist, inlist, length);
    postorder(T);
    return 0;
}
void  postorder(BiTree T)
{
    if (T)
    {

        postorder(T->lchild);
        postorder(T->rchild);
        printf("%c ", T->data);
    }
}
BiTree CreatBinTree(char* pre, char* in, int n)
{
    BiTree T;
    int i;
    if (n <= 0) return NULL;
    T = (BiTree)malloc(sizeof(BiTNode));
    T->data = pre[0];
    for (i = 0; in[i] != pre[0]; i++);
    //找到中序遍历中与先序遍历中第一个相同元素的位置
    //中序中前i个是左子树，后i个是右子树
    T->lchild = CreatBinTree(pre + 1, in, i);
    //建立右子树，后i个是右子树，所以中序的后i个是右子树，先序的后i个是右子树
    T->rchild = CreatBinTree(pre + i + 1, in + i + 1, n - i - 1);
    return T;
}
*/
