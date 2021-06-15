#include <stdio.h>
#include <stdlib.h>


typedef struct LNode{
	int data;
	struct LNode *next;
}*LinkedList,LNode;

//头插法 
LinkedList List_HeadInsert(LinkedList &L){
	int x;
	L=(LinkedList)malloc(sizeof(LNode)); //头结点
	L->next=NULL;
	LNode *s,*r=L;
	scanf("%d",&x);
	while(x!=999){
		s=(LNode *)malloc(sizeof(LNode));
		s->data=x;
		s->next=r->next;
		r->next=s;
		scanf("%d",&x);
	}
	return L;
}

bool print_LinkList(LinkedList L){
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
	LinkedList L;
	List_HeadInsert(L);
	print_LinkList(L);
	return 0;
} 
