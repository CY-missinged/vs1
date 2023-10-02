//本程序可实现建立中序线索二叉树，
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct node //线索二叉树中的结点类型定义
{
	char data;					  //数据域，存放结点的数据值
	struct node *lchild, *rchild; //左右指针域，分别存放左、右孩子结点的地址
	int ltag, rtag;				  //左右指针所指对象的类型标志
} ThrBSTree;

//输入结点值的先序序列建立二叉树，t为指向二叉树根结点指针的指针
void CreatBSTree(ThrBSTree **t)
{
	char ch;
	scanf("%c", &ch); //输入当前结点的数据值
	if (ch == '#')	  //以'#'作为空结点值用于结束递归
		*t = NULL;
	else
	{
		*t = (ThrBSTree *)malloc(sizeof(ThrBSTree)); //申请新结点空间
		(*t)->data = ch;
		(*t)->ltag = (*t)->rtag = 0;  //二叉树结点的左右标志均初始化为0
		CreatBSTree(&((*t)->lchild)); //递归创建左子树
		CreatBSTree(&((*t)->rchild)); //递归创建右子树
	}
}

void InOrder(ThrBSTree *p) //二叉树的中序遍历函数
{
	if (p != NULL)
	{
		InOrder(p->lchild);
		printf("%5c", p->data);
		InOrder(p->rchild);
	}
}

//中序线索二叉树的递归函数，p指向待线索化的二叉树的根结点
void InThreading(ThrBSTree *p, ThrBSTree **pre)
{
	if (p != NULL)
	{
		InThreading(p->lchild, pre);
		if (p->lchild == NULL)
		{
			p->ltag = 1;
			p->lchild = *pre;
		}
		if ((*pre)->rchild == NULL)
		{
			(*pre)->rtag = 1;
			(*pre)->rchild = p;
		}
		*pre = p;
		InThreading(p->rchild, pre);
	}
}

//建立带头结点的中序线索二叉树的函数，其中p指向二叉树的根结点，root用于返回头结点的地址
int InOrderThr(ThrBSTree **root, ThrBSTree *p)
{
	ThrBSTree *pre;									// pre用于指向p结点的中序前驱结点
	*root = (ThrBSTree *)malloc(sizeof(ThrBSTree)); //初始化头结点
	if (*root == NULL)
		return 0;
	(*root)->ltag = 0;
	(*root)->rtag = 1;
	(*root)->rchild = *root;
	if (p == NULL) //若二叉树为空
		(*root)->lchild = *root;
	else //若二叉树非空
	{
		(*root)->lchild = p;  //头结点的左指针指向根结点
		pre = *root;		  //线索化前，pre初始化为根结点地址
		InThreading(p, &pre); //中序遍历二叉树，对其进行线索化
		pre->rchild = *root;  //线索化结束，中序序列中最后一个结点的右指针指向头结点
		pre->rtag = 1;
		(*root)->rchild = pre;
	}
	return 1;
}

//查找中序线索二叉树中序遍历的第1个结点的函数
ThrBSTree *InFirstNode(ThrBSTree *root)
{
	ThrBSTree *p = root->lchild;
	while (p->ltag == 0)
		p = p->lchild;
	return p;
}

//在中序线索树中查找结点P在中序遍历的后继结点的函数
ThrBSTree *InPostNode(ThrBSTree *p)
{
	ThrBSTree *post;
	post = p->rchild;
	if (p->rtag == 0) // p有右孩子
	{				  //以右孩子为根的右子树的最左的结点就是p的后继结点
		while (post->ltag == 0)
			post = post->lchild;
	}
	return post;
}

//实现基于中序线索二叉树的非递归中序遍历
void ThrInOrder(ThrBSTree *root)
{
	ThrBSTree *p;
	for (p = InFirstNode(root); p != root; p = InPostNode(p))
		printf("%5d%5c%5d\n", p->ltag, p->data, p->rtag);
}

ThrBSTree *PrePostNode(ThrBSTree *root, ThrBSTree *p)
//中序线索中找先序遍历的p的后继
{
	ThrBSTree *post;
	if (p->ltag == 0)
		post = p->lchild; // P有左孩子，左孩子是后继
	else if (p->rtag == 0)
		post = p->rchild; //若p无左而有右孩子，则右孩子是后继
	else				  //若p是叶子结点
	{
		while (p->rchild->rtag == 1 && p->rchild != root)
			p = p->rchild;
		if (p->rchild != root)
			post = p->rchild->rchild;
		else
			post = root; //若p的右孩子指向头结点，则结束，返回p
	}
	return post;
}

//实现基于中序线索二叉树的非递归先序遍历
void ThrPreOrder(ThrBSTree *root)
{
	ThrBSTree *p;
	for (p = root->lchild; p != root; p = PrePostNode(root, p))
		printf("%5d%5c%5d\n", p->ltag, p->data, p->rtag);
}

//中序线索中查找结点p在后序遍历下的直接前驱结点的函数
ThrBSTree *PostPreNode(ThrBSTree *root, ThrBSTree *p)
{
	ThrBSTree *pre;
	if (p->rtag == 0)
		pre = p->rchild; // P有右孩子，右孩子是前驱
	else if (p->ltag == 0)
		pre = p->lchild; // p无右孩子而有左孩子，左孩子是前驱
	else
	{
		while (p->lchild->ltag == 1 && p->lchild != root)
			p = p->lchild;
		if (p->lchild != root)
			pre = p->lchild->lchild;
		else
			pre = root;
	}
	return pre;
}

////实现基于中序线索二叉树的非递归逆后序遍历
void ThrPostOrder(ThrBSTree *root)
{
	ThrBSTree *p;
	for (p = root->lchild; p != root; p = PostPreNode(root, p))
		printf("%5d%5c%5d\n", p->ltag, p->data, p->rtag);
}

int main()
{
	ThrBSTree *root, **t;
	root = (ThrBSTree *)malloc(sizeof(ThrBSTree));
	t = &root;
	CreatBSTree(t); //建立二叉树的二叉链表存储结构
	getchar();
	printf("\n中序遍历序列：\n");
	InOrder(root);
	InOrderThr(t, root); //对原二叉树进行中序线索化
	printf("\n线索中序遍历序列：\n");
	printf(" ltag  data  rtag\n");
	ThrInOrder(*t);
	printf("\n线索先序遍历序列：\n");
	printf(" ltag  data  rtag\n");
	ThrPreOrder(*t);
	printf("\n线索后序遍历反序列：\n");
	printf(" ltag  data  rtag\n");
	ThrPostOrder(*t);
	return 0;
}
