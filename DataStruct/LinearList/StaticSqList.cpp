 #include <stdio.h>
 #define MAXSIZE 10 
 
 /**
 * Author:������ 
 * Description:˳���(˳��洢�ṹ�����Ա�) 
 * Weakness:�����Բ�
 * Advantage:�ɽ��������ȡ 
 * Plan ��������(����ʵ��) Sequence List Utmost Size:10
 **/
 
 typedef struct {
	int data [MAXSIZE];
	int length; 
 }SqList;
 
 //��ʼ�� 
 void InitList(SqList &L){
 	for(int i=0;i<MAXSIZE;i++)
 		L.data[i]=0;//��ֹ�ڴ������������� 
 	L.length=0;
 } 
 
 //���� 
 void DestroyList(SqList &L){
 	 	for(int i=0;i<MAXSIZE;i++)
 		L.data[i]=0;
 	L.length=0;
 } 
  
//���Ԫ��(λ���1��ʼ)  
bool ListInsert(SqList &L,int i,int e){
	if(i<1||i>L.length+1)
		return false;
	if(L.length>=MAXSIZE)
		return false;
	
	for(int j=L.length;j>=i;j--)
		L.data[j]=L.data[j-1];
	L.data[i-1]=e;
	L.length++;
	return true;
}

//ɾ��Ԫ��(λ���1��ʼ) ���ر�ɾ����Ԫ�� 
bool ListDelete(SqList &L,int i,int &e){
	if(i<1||i>L.length)
		return false;
	e=L.data[i-1];
	for(int j=i;j<L.length;j++)
		L.data[j-1]=L.data[j];
	L.length--;
	return true;
}

//��λ�����
int GetElem(SqList L,int i){
	if(i<1||i>L.length)
		return -1;
	return L.data[i-1];
} 

//��ֵ����
int LocateElem(SqList L,int e){
	for(int i=0;i<L.length;i++)
		if(L.data[i]==e){
			return i+1;
		}
	return -1;
} 

//�ж�Ϊ��
bool Empty(SqList L){
	return (L.length==0);
} 
 
//���Ա��� 
int Length(SqList L){
	return L.length;
}
 
//������Ա�ȫ��Ԫ��
void printList(SqList L){
	for(int i=0;i<L.length;i++)
		printf("List[%d]=%d\n",i+1,L.data[i]);
} 
 
 
 int main(){
 	
 	// Test Program
 	SqList L;
 	InitList(L);
	ListInsert(L,1,1);
	ListInsert(L,2,2);
	ListInsert(L,3,3);
	ListInsert(L,3,4);
	printf("length=%d\n",Length(L));
	int e=-1;
	ListDelete(L,2,e);
	printList(L);
	
 	return 0; 
 }
