#include <stdio.h>
#include <stdlib.h>

/**
* Signle Link List
* Advantage:����Ҫ�����ռ䣬������ǿ
* Weakness:���������ȡ���ķ�һ���ռ���ָ�� 
* �ִ�ͷ���Ͳ���ͷ��� (different:i=1��Ҫ���⴦��) 
**/ 

typedef struct LNode{ //��� 
	int data;
	struct LNode *next;
}*LinkList,LNode;

//����ͷ��� 
bool InitList(LinkList &L){
	L=NULL;
	return true;
} 

//����ͷ��㵥�����ж��Ƿ�Ϊ�� 
bool Empty(LinkList L){
	return (L==NULL);
}

//��ͷ��������ж��Ƿ�Ϊ�� 
bool Empty_Head(LinkList L){
	if(L->next==NULL){
		return true;
	}
	return false;
}

//��ͷ��� 
bool InitList_Head(LinkList &L){
	L=(LNode *)malloc(sizeof(LNode));
	if(L==NULL){
		return false;//�ڴ�����ʧ�� 
	}
	L->next=NULL;
	return true; 
} 

//��ͷ����������(λ�����)
bool ListInsert_Head(LinkList &L,int i,int e){
	if(i<1){
		return false;
	}
	LNode *p;
	int j=0;
	p=L;
	while(p!=NULL&&j<i-1){
		p=p->next;
		j++; 
	}
	if(p==NULL){
		return false;
	}
	LNode *s=(LNode *)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true; 	
} 

//����ͷ��� 
bool ListInsert(LinkList &L,int i,int e){
	if(i<1){
		return false;
	} 
	if(i==1){
		LNode *s=(LNode *)malloc(sizeof(LNode));
		s->data=e;
		s->next=L;
		L=s;
		return true;
	}
	LNode *p;
	int j=1;
	p=L;
	while(p!=NULL&&j<i-1){
		p=p->next;
		j++;
	}
	if(p==NULL){
		return false;
	}
	LNode *s=(LNode *)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s; 
	return true;
//	return InsertNextNode(p,e);
}

//����������P�������Ԫ��e
bool InsertNextNode(LNode *p,int e){
	if(p==NULL){
		return false;
	}
	LNode *s=(LNode *)malloc(sizeof(LNode));
	if(s==NULL){
		return false;
	}
	s->data=e;
	s->next=p->next;
    p->next=s;
    return true;
} 
 
 //ǰ���������p���ǰ����Ԫ��e(��ͷ���)
bool InsertPriorNode(LNode *p,int e){
	if(p==NULL){
		return false;
	}
	LNode *s=(LNode *)malloc(sizeof(LNode));
	s->data=p->data;
	s->next=p->next;
	p->data=e;
	p->next=s;
	return true;
}

//��λ��ɾ�� (��ͷ���)
bool ListDelete(LinkList &L,int i,int &e){
	if(i<1){
		return false;
	}
	LNode *p;
	int j=0;
	p=L;
	while(p!=NULL&&j<i-1){
		p=p->next;
		j++;
	}
	if(p==NULL){
		return false;
	} 
	if(p->next==NULL){
		return false;
	}
	LNode *s=p->next;
	e=s->data;
	p->next=s->next;
	free(p);
	return true;
}

//ɾ��ָ�����
 bool DeleteNode(LNode *p){
 	if(p==NULL){
 		return false;
	 }
	 LNode *s=p->next;
	 p->data=s->data;
	 p->next=s->next;
	 free(s);
	 return true;
 } 

//��λ����(��ͷ���)
 int GetElem(LinkList L,int i){
 	if(i<0){
 		return -1;
	 }
 	
 	if(L==NULL){
 		return -1;
	 }
	 LNode *p;
	 int j=0;
	 p=L;
	while(p!=NULL&&j<i){
		p=p->next;
		j++;
	}
	if(p==NULL){
		return false;
	}
	return p->data;  
 } 
 
 //��ֵ����(��ͷ���)
 LNode * LocateElem(LinkList L,int e){
	LNode *p=L->next;//ȥ��ͷָ�뿪ʼ�ӵ�һ��Ԫ�ؿ�ʼ���� 
	while(p!=NULL&&p->data!=e){
		p=p->next;
	}
	return p;
 } 
 
//������ĳ���
int Length(LinkList L){
	int len=0;
	LNode *p=L;
	while(p->next!=NULL){
		p=p->next;
		len++;
	}
	return len;
} 


int main(){
	//Test Program
	LinkList L;
	InitList_Head(L);
	ListInsert_Head(L,1,1);
	ListInsert_Head(L,2,2);
	printf("LinkList len:%d\n",Length(L));
	
	return 0;
}
