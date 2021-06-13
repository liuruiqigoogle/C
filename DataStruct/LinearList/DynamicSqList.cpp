#include <stdio.h>
#include <stdlib.h>
#define INITSIZE 5 

/**
 * Author:������ 
 * Description:˳���(˳��洢�ṹ�����Ա�) 
 * Weakness:�����Բ�
 * Advantage:�ɽ��������ȡ 
 * Plan ������(ָ��ʵ��) Sequence List Utmost Size:5
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
	if(L.data==NULL)// ��Ҫ�����ڴ����ʧ�ܵ���� 
		return false;
	return true;	
}
//�������� 
bool IncreaseList(SqList &L){
	int *p=L.data;
	L.data=(int *)malloc(sizeof(int)*(L.MAXSIZE*2));//����ԭ���������2�� 
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
	//����ǰ 
	printf("Current Length is %d, Current MaxSize is %d\n",Length(L),MaxSize(L));
	ListInsert(L,6,6);
	//���ݺ� 
	printf("Current Length is %d, Current MaxSize is %d\n",Length(L),MaxSize(L));
	return 0;
} 
