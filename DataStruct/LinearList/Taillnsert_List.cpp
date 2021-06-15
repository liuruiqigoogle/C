#include <stdio.h>
#include <stdlib.h>

typedef struct LNode{
	int data;
	struct LNode *next;
}*LinkList,LNode;

//尾插法(带头结点) 
LinkList List_Taillnsert(LinkList &L){
	int x;
	L=(LinkList)malloc(sizeof(LNode));//建立头结点
	LNode *s,*r=L;
	scanf("%d",&x);
	while(x!=999){
		s=(LNode *)malloc(sizeof(LNode));
		s->data=x;
		r->next=s;
		r=s;
		scanf("%d",&x);
	}
	r->next=NULL;//r指针永远指向最后一个结点 
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
