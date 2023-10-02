// encoding=GBK
//����ʵ�ֽ���������

#include <stdio.h>
#include <stdlib.h>

#define SIZEMAX 100

struct LNode {
	int data;
	LNode *next;
};

//�����ʼ��
LNode *InitLink() {
	LNode *head;
	head = (LNode *)malloc(sizeof(LNode));
	if (head != NULL)
		head->next = NULL;
	return head;
}

//���룬β�巨
LNode *creatlink() {
	LNode *head, *p;
	int m, i;
	head = InitLink();
	p = head;
	printf("��������Ҫ�����Ԫ�ظ���:\n");
	scanf("%d", &m);
	printf("�����뼯��Ԫ��:\n");
	for (i = 0; i < m; i++) {
		p->next = (LNode *)malloc(sizeof(LNode));
		p = p->next;
		scanf("%d", &p->data);
	}
	p->next = NULL;
	return head;
}

//���
void InputList(LNode *head) {
	LNode *p = head;
	while (p->next != NULL) {
		p = p->next;
		printf("%d ", p->data);
	}
	printf("\n");
}

//����������Ƿ���Ԫ��x���з���1���޷���0
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

//����һ��û�е�Ԫ��
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

//����
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

//����
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
	printf("������A����:\n");
	A = creatlink();
	printf("������B����:\n");
	B = creatlink();
	printf("����A�뼯��B�Ľ���Ϊ:\n");
	C = InitLink();
	jiaoji_List(A,B,C);
	InputList(C);
	C = InitLink();
	printf("����A�뼯��B�Ĳ���Ϊ:\n");
	bingji_List(A,B,C);
	InputList(C);
	return 0;
}
