//删除所有值为X的数据元素

//伪代码
//时间复杂度O(n)  空间复杂度O(1) 
#include <stdio.h>

typedef struct {
	int data[10];
	int length;
}SqList;


 bool DeleteElem(SqList &L,int e){
 	 if(L.length==0)
 	 	return false;
 	int pos=0;
 	for(int i=0;i<L.length;i++)
 		if(L.data[i]!=e){
 			L.data[pos]=L.data[i];
 			pos++;
		 }
	L.length=pos;
 } 
 
 void printList(SqList L){
 	for(int i=0;i<L.length;i++)
 		printf("%d\t",L.data[i]);
 }
 

 int main(){
 //test 
 	SqList L;
 	L.data[0]=1;
	L.data[1]=2;
	L.data[2]=2;
	L.data[3]=5;
	L.data[4]=1;	
 	L.length=5;
 //	printList(L);
 	DeleteElem(L,1);
 	printList(L);
	return 0;
 }
