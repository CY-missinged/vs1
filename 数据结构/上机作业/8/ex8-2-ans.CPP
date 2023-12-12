//第七上机作业，二叉排序树的遍历
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int key; //查找关键字，其它关键字可不考虑
} DataType;

typedef struct node
{
    DataType data;
    struct node *lchild, *rchild;
} BSTree;

typedef int KeyType;

/*向二叉排序树中插入一个新结点的算法*/
void InsertBST(BSTree **T, KeyType x)
{
    if (*T == NULL) // 若待插入的二叉排序树为空，将新元素作为根结点插入
    {
        *T = (BSTree *)malloc(sizeof(BSTree));
        (*T)->data.key = x;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
    }
    else // 若待插入的二叉排序树非空
        if (x < (*T)->data.key)
            InsertBST(&((*T)->lchild), x); //将新元素插入到左子树中
        else
            InsertBST(&((*T)->rchild), x); //将新元素插入到右子树中
}

//二叉排序树的创建算法，T 中存放着指向根结点的指针变量的地址
void CreateBSTree(BSTree **T)
{
    KeyType x, endflag = -1; // endflag 为输入结束标志，在本算法中假定为-1
    printf("请输入树中各个结点的值,以-1 结束：\n");
    scanf("%d", &x);     //输入第 1 个元素的关键字值
    while (x != endflag) //将输入的各元素依次插入到二叉排序树中
    {
        InsertBST(T, x);
        scanf("%d", &x); //假定输入的各结点关键字均不相同
    }
}

void InOrder(BSTree *p)
{
    if (p != NULL)
    {
        InOrder(p->lchild);         /*中序遍历左子树*/
        printf("%5d", p->data.key); /*访问根结点*/
        InOrder(p->rchild);         /*中序遍历右子树*/
    }
}

//在根结点指针为 t 的二叉排序树上查找关键字为 k 的元素
BSTree *BSTSearch(BSTree *t, KeyType k)
{
    if (t == NULL)
        return NULL; //查找失败，返回空指针
    if (t->data.key == k)
        return t; //查找成功，返回该结点的指针
    else if (k < t->data.key)
        return BSTSearch(t->lchild, k); //在左子树中查找
    else
        return BSTSearch(t->rchild, k); //在右子树中查找
}

int menu()
{
    int ch;
    printf("1--------插入一个新结点\n");
    printf("2--------中序遍历二叉排序树\n");
    printf("3--------查找指定关键字结点\n");
    printf("0--------退出程序\n");
    printf("请输入你的选择（0-3）：");
    scanf("%d", &ch);
    return ch;
}

int main()
{
    int x, ch = 1;
    BSTree *root = NULL, **t, *p;
    t = &root;
    CreateBSTree(t);
    while (ch != 0)
    {
        ch = menu();
        switch (ch)
        {
        case 1:
            printf("请输入新结点的关键字值：");
            scanf("%d", &x);
            InsertBST(t, x);
            break;
        case 2:
            printf("中序遍历访问结点值的结果为\n");
            InOrder(root);
            printf("\n");
            break;
        case 3:
            printf("请输入待查结点的关键字值：\n");
            scanf("%d", &x);
            p = BSTSearch(root, x);
            if (p == NULL)
                printf("无此结点！\n");
            else
                printf("查找成功！该结点的地址为%ld\n", p);
        }
    }
    return 0;
}
