// encoding=GBK
//链表实现交并集运算

#include <stdio.h>
#include <stdlib.h>

#define SIZEMAX 100

struct LNode {
	int data;
	LNode *next;
};

//链表初始化
LNode *InitLink() {
	LNode *head;
	head = (LNode *)malloc(sizeof(LNode));
	if (head != NULL)
		head->next = NULL;
	return head;
}

//输入，尾插法
LNode *creatlink() {
	LNode *head, *p;
	int m, i;
	head = InitLink();
	p = head;
	printf("请输入需要输入的元素个数:\n");
	scanf("%d", &m);
	printf("请输入集合元素:\n");
	for (i = 0; i < m; i++) {
		p->next = (LNode *)malloc(sizeof(LNode));
		p = p->next;
		scanf("%d", &p->data);
	}
	p->next = NULL;
	return head;
}

//输出
void InputList(LNode *head) {
	LNode *p = head;
	while (p->next != NULL) {
		p = p->next;
		printf("%d ", p->data);
	}
	printf("\n");
}

//检查链表中是否有元素x，有返回1，无返回0
int  Find_List(LNode *head ,int x) {
	LNode *p=head;
	int judge=0;
	while(p->next!=NULL) {
		p=p->next;
		if(p->data==x) {
			judge=1;
		}
	}
	if(p->data==x)
		judge=1;
	return judge;
}

//插入一个没有的元素
void insert_list(LNode *head,int x) {
	LNode *p=head;
	if(Find_List(head,x)!=1) {
		while(p->next!=NULL) {
			p=p->next;
		}
		p->next=(LNode *)malloc(sizeof(LNode));
		p=p->next;
		p->data=x;
		p->next=NULL;
	}
}

//交集
void jiaoji_List(LNode *head1,LNode *head2,LNode *head3) {
	LNode *A=head1,*B=head2,*C=head3;
	while(A->next!=NULL) {
		A=A->next;
		B=head2;
		while(B->next!=NULL) {
			B=B->next;
			if(A->data==B->data) {
				insert_list(C,A->data);
			}
		}
		if(B->next==NULL) {
			if(A->data==B->data) {
				insert_list(C,A->data);
			}
		}
	}
	if(A->next==NULL) {
		if(A->data==B->data) {
			insert_list(C,A->data);
		}
	}
}

//并集
void bingji_List(LNode *head1,LNode *head2,LNode *head3) {
	LNode *A=head1,*B=head2,*C=head3;
	while(A->next!=NULL) {
		A=A->next;
		insert_list(C,A->data);
	}
	if(A->next==NULL) {
		insert_list(C,A->data);
	}
	while(B->next!=NULL) {
		B=B->next;
		insert_list(C,B->data);
	}
	if(B->next==NULL) {
		insert_list(C,B->data);
	}
}

int main() {
	LNode *A, *B, *C;
	printf("请输入A集合:\n");
	A = creatlink();
	printf("请输入B集合:\n");
	B = creatlink();
	printf("集合A与集合B的交集为:\n");
	C = InitLink();
	jiaoji_List(A,B,C);
	InputList(C);
	C = InitLink();
	printf("集合A与集合B的并集为:\n");
	bingji_List(A,B,C);
	InputList(C);
	return 0;
}
