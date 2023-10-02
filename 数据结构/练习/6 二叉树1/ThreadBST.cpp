//�������ʵ�ֽ�������������������
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct node //�����������еĽ�����Ͷ���
{
	char data;					  //�����򣬴�Ž�������ֵ
	struct node *lchild, *rchild; //����ָ���򣬷ֱ������Һ��ӽ��ĵ�ַ
	int ltag, rtag;				  //����ָ����ָ��������ͱ�־
} ThrBSTree;

//������ֵ���������н�����������tΪָ������������ָ���ָ��
void CreatBSTree(ThrBSTree **t)
{
	char ch;
	scanf("%c", &ch); //���뵱ǰ��������ֵ
	if (ch == '#')	  //��'#'��Ϊ�ս��ֵ���ڽ����ݹ�
		*t = NULL;
	else
	{
		*t = (ThrBSTree *)malloc(sizeof(ThrBSTree)); //�����½��ռ�
		(*t)->data = ch;
		(*t)->ltag = (*t)->rtag = 0;  //�������������ұ�־����ʼ��Ϊ0
		CreatBSTree(&((*t)->lchild)); //�ݹ鴴��������
		CreatBSTree(&((*t)->rchild)); //�ݹ鴴��������
	}
}

void InOrder(ThrBSTree *p) //�������������������
{
	if (p != NULL)
	{
		InOrder(p->lchild);
		printf("%5c", p->data);
		InOrder(p->rchild);
	}
}

//���������������ĵݹ麯����pָ����������Ķ������ĸ����
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

//������ͷ�������������������ĺ���������pָ��������ĸ���㣬root���ڷ���ͷ���ĵ�ַ
int InOrderThr(ThrBSTree **root, ThrBSTree *p)
{
	ThrBSTree *pre;									// pre����ָ��p��������ǰ�����
	*root = (ThrBSTree *)malloc(sizeof(ThrBSTree)); //��ʼ��ͷ���
	if (*root == NULL)
		return 0;
	(*root)->ltag = 0;
	(*root)->rtag = 1;
	(*root)->rchild = *root;
	if (p == NULL) //��������Ϊ��
		(*root)->lchild = *root;
	else //���������ǿ�
	{
		(*root)->lchild = p;  //ͷ������ָ��ָ������
		pre = *root;		  //������ǰ��pre��ʼ��Ϊ������ַ
		InThreading(p, &pre); //����������������������������
		pre->rchild = *root;  //�������������������������һ��������ָ��ָ��ͷ���
		pre->rtag = 1;
		(*root)->rchild = pre;
	}
	return 1;
}

//��������������������������ĵ�1�����ĺ���
ThrBSTree *InFirstNode(ThrBSTree *root)
{
	ThrBSTree *p = root->lchild;
	while (p->ltag == 0)
		p = p->lchild;
	return p;
}

//�������������в��ҽ��P����������ĺ�̽��ĺ���
ThrBSTree *InPostNode(ThrBSTree *p)
{
	ThrBSTree *post;
	post = p->rchild;
	if (p->rtag == 0) // p���Һ���
	{				  //���Һ���Ϊ����������������Ľ�����p�ĺ�̽��
		while (post->ltag == 0)
			post = post->lchild;
	}
	return post;
}

//ʵ�ֻ������������������ķǵݹ��������
void ThrInOrder(ThrBSTree *root)
{
	ThrBSTree *p;
	for (p = InFirstNode(root); p != root; p = InPostNode(p))
		printf("%5d%5c%5d\n", p->ltag, p->data, p->rtag);
}

ThrBSTree *PrePostNode(ThrBSTree *root, ThrBSTree *p)
//���������������������p�ĺ��
{
	ThrBSTree *post;
	if (p->ltag == 0)
		post = p->lchild; // P�����ӣ������Ǻ��
	else if (p->rtag == 0)
		post = p->rchild; //��p��������Һ��ӣ����Һ����Ǻ��
	else				  //��p��Ҷ�ӽ��
	{
		while (p->rchild->rtag == 1 && p->rchild != root)
			p = p->rchild;
		if (p->rchild != root)
			post = p->rchild->rchild;
		else
			post = root; //��p���Һ���ָ��ͷ��㣬�����������p
	}
	return post;
}

//ʵ�ֻ������������������ķǵݹ��������
void ThrPreOrder(ThrBSTree *root)
{
	ThrBSTree *p;
	for (p = root->lchild; p != root; p = PrePostNode(root, p))
		printf("%5d%5c%5d\n", p->ltag, p->data, p->rtag);
}

//���������в��ҽ��p�ں�������µ�ֱ��ǰ�����ĺ���
ThrBSTree *PostPreNode(ThrBSTree *root, ThrBSTree *p)
{
	ThrBSTree *pre;
	if (p->rtag == 0)
		pre = p->rchild; // P���Һ��ӣ��Һ�����ǰ��
	else if (p->ltag == 0)
		pre = p->lchild; // p���Һ��Ӷ������ӣ�������ǰ��
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

////ʵ�ֻ������������������ķǵݹ���������
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
	CreatBSTree(t); //�����������Ķ�������洢�ṹ
	getchar();
	printf("\n����������У�\n");
	InOrder(root);
	InOrderThr(t, root); //��ԭ��������������������
	printf("\n��������������У�\n");
	printf(" ltag  data  rtag\n");
	ThrInOrder(*t);
	printf("\n��������������У�\n");
	printf(" ltag  data  rtag\n");
	ThrPreOrder(*t);
	printf("\n����������������У�\n");
	printf(" ltag  data  rtag\n");
	ThrPostOrder(*t);
	return 0;
}
