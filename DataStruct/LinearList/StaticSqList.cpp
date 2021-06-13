 #include <stdio.h>
 #define MAXSIZE 10 
 
 /**
 * Author:刘瑞琪 
 * Description:顺序表(顺序存储结构的线性表) 
 * Weakness:扩容性差
 * Advantage:可进行随机存取 
 * Plan 不可扩容(数组实现) Sequence List Utmost Size:10
 **/
 
 typedef struct {
	int data [MAXSIZE];
	int length; 
 }SqList;
 
 //初始化 
 void InitList(SqList &L){
 	for(int i=0;i<MAXSIZE;i++)
 		L.data[i]=0;//防止内存中遗留脏数据 
 	L.length=0;
 } 
 
 //销毁 
 void DestroyList(SqList &L){
 	 	for(int i=0;i<MAXSIZE;i++)
 		L.data[i]=0;
 	L.length=0;
 } 
  
//添加元素(位序从1开始)  
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

//删除元素(位序从1开始) 返回被删除的元素 
bool ListDelete(SqList &L,int i,int &e){
	if(i<1||i>L.length)
		return false;
	e=L.data[i-1];
	for(int j=i;j<L.length;j++)
		L.data[j-1]=L.data[j];
	L.length--;
	return true;
}

//按位序查找
int GetElem(SqList L,int i){
	if(i<1||i>L.length)
		return -1;
	return L.data[i-1];
} 

//按值查找
int LocateElem(SqList L,int e){
	for(int i=0;i<L.length;i++)
		if(L.data[i]==e){
			return i+1;
		}
	return -1;
} 

//判断为空
bool Empty(SqList L){
	return (L.length==0);
} 
 
//线性表长度 
int Length(SqList L){
	return L.length;
}
 
//输出线性表全部元素
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
