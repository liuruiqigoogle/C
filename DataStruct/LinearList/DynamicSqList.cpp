#include <stdio.h>
#include <stdlib.h>
#define INITSIZE 5 

/**
 * Author:刘瑞琪 
 * Description:顺序表(顺序存储结构的线性表) 
 * Weakness:扩容性差
 * Advantage:可进行随机存取 
 * Plan 可扩容(指针实现) Sequence List Utmost Size:5
 **/

typedef struct{
	int *data;
	int length; 
	int MAXSIZE;
}SqList; 

bool InitList(SqList &L){
	L.data=(int *)malloc(sizeof(int)*INITSIZE);
	L.length=0;
	L.MAXSIZE=INITSIZE;
	if(L.data==NULL)// 需要考虑内存分配失败的情况 
		return false;
	return true;	
}
//扩充容量 
bool IncreaseList(SqList &L){
	int *p=L.data;
	L.data=(int *)malloc(sizeof(int)*(L.MAXSIZE*2));//乘以原最大容量的2倍 
	for(int i=0;i<L.length;i++)
		L.data[i]=p[i];
	L.MAXSIZE*=2;                
	free(p);                                                                                
}

bool ListInsert(SqList &L,int i,int e){
	if(i<1||i>L.length+1)
		return false;
	if(L.length>=L.MAXSIZE)
		IncreaseList(L);
	for(int j=L.length;j>=i;j--)
		L.data[j]=L.data[j-1];
	L.length++;
	return true;
}

int Length(SqList L){
	return L.length;
}

int MaxSize(SqList L){
	return L.MAXSIZE;
}

void DestroyList(SqList &L){
	if(L.data!=NULL)
		free(L.data);
}

int main(){
	
	SqList L;
	InitList(L);
	for(int i=1;i<=5;i++)
		ListInsert(L,i,i);
	//扩容前 
	printf("Current Length is %d, Current MaxSize is %d\n",Length(L),MaxSize(L));
	ListInsert(L,6,6);
	//扩容后 
	printf("Current Length is %d, Current MaxSize is %d\n",Length(L),MaxSize(L));
	return 0;
} 
