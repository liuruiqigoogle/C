#include <stdio.h>
#include <stdlib.h>

/**
* description:˫����
* weakness:���������ȡ 
*
**/ 

typedef struct DNode{//˫���� 
 int data;
 struct DNode *prior,*next;
}*DLinkList,DNode;


bool InitDLinkList(DLinkList &L){
	L=(DLinkList)malloc(sizeof(DLinkList));
	if(L==NULL)
		return false;//�ڴ����ʧ��
	L->prior=NULL;
	L->next=NULL;
	return true; 
} 

bool Empty(DLinkList L){
	if(L->next==NULL)
		return true;
	return false;
}

//��p�������s���  Tips:ע�⿼�� p->next==NULL��Ҫ��һ���ж� 
bool InsertNextDNode(DNode *p,DNode *s){
	if(p==NULL||s==NULL)
		return false;
	s->next=p->next;
	p->next=s;
	s->prior=p;
	if(s->next!=NULL)
		s->next->prior=s;
	return true;
}

//ɾ��P���ĺ�̽�� 
bool DeleteNextDNode(DNode *p){
	if(p==NULL)
		return false; 
	DNode *q=p->next;
	p->next=q->next;
	if(p->next!=NULL)
		p->next->prior=p;
	free(q);
	return true;
}

//�������
// while(p!=NULL) p=p->next p->data;

//ǰ�����
// while(p->prior!=NULL) p=p->prior p->data;


bool print_DLinkList(DLinkList L){
	if(L==NULL)
		return false;
	DNode *p=L;
	int j=0;
	while(p->next!=NULL){
		p=p->next;
		j++;
		printf("element positon [%d]=%d",j,p->data);
	}
	return true;		
}

 

int main(){
	DLinkList L;
	InitDLinkList(L);
	
	DNode *s=(DNode *)malloc(sizeof(DNode));
	s->data=999;
	s->next=NULL;
	s->prior=NULL;
	InsertNextDNode(L,s);
	print_DLinkList(L);
	
	
	
	return 0;
} 
