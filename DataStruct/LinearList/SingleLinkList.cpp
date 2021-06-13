#include <stdio.h>
#include <stdlib.h>

/**
* Signle Link List
* Advantage:不需要连续空间，扩容性强
* Weakness:不可随机存取，耗费一定空间存放指针 
* 分带头结点和不带头结点 (different:i=1需要特殊处理) 
**/ 

typedef struct LNode{ //结点 
	int data;
	struct LNode *next;
}*LinkList,LNode;

//不带头结点 
bool InitList(LinkList &L){
	L=NULL;
	return true;
} 

//不带头结点单链表判断是否为空 
bool Empty(LinkList L){
	return (L==NULL);
}

//带头结点链表判断是否为空 
bool Empty_Head(LinkList L){
	if(L->next==NULL){
		return true;
	}
	return false;
}

//带头结点 
bool InitList_Head(LinkList &L){
	L=(LNode *)malloc(sizeof(LNode));
	if(L==NULL){
		return false;//内存申请失败 
	}
	L->next=NULL;
	return true; 
} 

//带头结点插入数据(位序插入)
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

//不带头结点 
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

//后插操作：在P结点后插入元素e
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
 
 //前插操作：在p结点前插入元素e(带头结点)
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

//按位序删除 (带头结点)
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

//删除指定结点
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

//按位查找(带头结点)
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
 
 //按值查找(带头结点)
 LNode * LocateElem(LinkList L,int e){
	LNode *p=L->next;//去除头指针开始从第一个元素开始遍历 
	while(p!=NULL&&p->data!=e){
		p=p->next;
	}
	return p;
 } 
 
//求链表的长度
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
