#include <stdio.h>
#include <stdlib.h>

/**
*����������
*�赥����ı�ͷָ��ΪL,���ṹ��data��next�����򹹳ɣ�dataΪchar���ͣ�����㷨�ж� 
*�������ȫ��n���ַ��Ƿ����ĶԳƣ���xyx,xyyx�������ĶԳơ�  
*Author:������ 
*/

typedef struct LNode{
	char data;
	struct LNode *next;
}*LinkedList,LNode;

bool InitList(LinkedList &L){
	L=(LNode *)malloc(sizeof(LNode));
	if(L==NULL)
		return false;
	L->next=NULL;
	return true;
}

bool DestroyList(LinkedList &L){
	if(L==NULL)
		return true;
	free(L);
	return true;
}

void print_LinkedList(LinkedList L){
	LNode *p=L;
	while(p->next!=NULL){
		p=p->next;
		printf("%c",p->data);
	}
}

bool InsertList(LinkedList &L,int i,char c){
	if(i<1)
		return false;
	if(L==NULL)
		return false; 
	int j=0;
	LNode *p=L;
	while(p!=NULL&&j<i-1){
		p=p->next;
		j++;
	}
	if(p==NULL)
		return false;
	LNode *s=(LNode *)malloc(sizeof(LNode));
	s->data=c;
	s->next=p->next;
	p->next=s;
	return true;	
} 

bool isHuiWen(LinkedList &L,int n){
	char c[n/2];
	LNode *p=L;
	int i,j=0;
	while(p!=NULL&&j<n/2){
		p=p->next;
		c[j++]=p->data;
	}
	if(n%2!=0)
		p=p->next;
int count=0;
	for(i=n/2;i>0;i--)
		p=p->next;
		if(c[i]==p->data){
			count++;
		}
	if(count==n/2){
		printf("�������ĶԳ�");
	}else{
		printf("���������ĶԳ�");
	}
}

int main(){
	LinkedList L;
	InitList(L);
	InsertList(L,1,'x');
	InsertList(L,2,'y');
	InsertList(L,3,'y');
	InsertList(L,3,'x');
	print_LinkedList(L);
	isHuiWen(L,3);
	
}
