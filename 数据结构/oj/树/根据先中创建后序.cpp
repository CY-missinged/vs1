�벹���������������ʵ�ֶ����������ĵݹ麯��BSTCreatePreIn��

#include <stdio.h>

#include <stdlib.h>

#define N 8 //�������Ľ������

    typedef char DataType; //�������Ľ��ֵΪchar��

typedef struct node //������������Ͷ���

{
    DataType data;

    struct node *lchild, *rchild;

} BSTNode,*BiTree;

DataType p1[10], p2[10]; // pre��in����ֱ����ڱ������������������Ӧ�Ľ��ֵ����

// int PosInorder(DataType a[], DataType x) //ȷ��ֵΪx�Ľ������������pre�е�λ��

// {
//     int i;

//     for (i = 0; i < N; i++)

//         if (a[i] == x)

//             return i;
// }

// //�������������������д�����n�����Ķ�����t
// BSTNode* BSTCreatePreIn(BSTNode **t, DataType *p1, DataType *p2, int n)
// // p1��p2�ֱ�ָ��ǰ�������������������������׸����ֵλ��
// {
//     BiTree T;
//     int i;
//     if (n <= 0) return NULL;
//     T = (BiTree)malloc(sizeof(BSTNode));
//     T->data = p1[0];
//     for (i = 0; p2[i] != p1[0]; i++);
//     //�ҵ��������������������е�һ����ͬԪ�ص�λ��
//     //������ǰi��������������i����������
//     T->lchild = CreatBinTree(p1 + 1, p2, i);
//     //��������������i��������������������ĺ�i����������������ĺ�i��������������ͼ���ܿ�������
//     T->rchild = CreatBinTree(p1 + i + 1, p2 + i + 1, n - i - 1);
//     return T;
// }

void PostOrder(BSTNode *p) //�������������

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
    //�ҵ��������������������е�һ����ͬԪ�ص�λ��
    //������ǰi��������������i����������
    T->lchild = CreatBinTree(pre + 1, in, i);
    //��������������i��������������������ĺ�i����������������ĺ�i����������
    T->rchild = CreatBinTree(pre + i + 1, in + i + 1, n - i - 1);
    return T;
}
*/
