#include <stdio.h>
#include <stdlib.h>

typedef struct LNode{
	int data;
	struct LNode *next;
}*LinkList,LNode;

//β�巨(��ͷ���) 
LinkList List_Taillnsert(LinkList &L){
	int x;
	L=(LinkList)malloc(sizeof(LNode));//����ͷ���
	LNode *s,*r=L;
	scanf("%d",&x);
	while(x!=999){
		s=(LNode *)malloc(sizeof(LNode));
		s->data=x;
		r->next=s;
		r=s;
		scanf("%d",&x);
	}
	r->next=NULL;//rָ����Զָ�����һ����� 
	return L;
} 

bool print_LinkList(LinkList L){
	if(L==NULL)
		return false;
	int j=0;
	LNode *p=L;
	while(p->next!=NULL){
		p=p->next;
		j++;
		printf("position[%d]=%d\n",j,p->data);
	}
	return true;
}


int main(){
	LinkList L;
	List_Taillnsert(L);
	print_LinkList(L);
	
	return 0;
} 
