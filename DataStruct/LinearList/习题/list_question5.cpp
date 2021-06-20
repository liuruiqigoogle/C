#include <stdio.h>

typedef struct {
	int data[10];
	int length;
}SqList;


 void printList(SqList L){
 	for(int i=0;i<L.length;i++)
 		printf("%d\t",L.data[i]);
 }


//问题描述:有序顺序表去重 
bool DeleteRepeatElem(SqList &L) {
	if(L.length==0)
		return false;
	int e=L.data[0];
	int pos=1;
	for(int i=1;i<L.length;i++)
		if(L.data[i]!=e){
			e=L.data[i];
			L.data[pos]=e;
			pos++;
		}
	L.length=pos;
	return true;
}

int main(){
	 //test 
 	SqList L;
 	L.data[0]=1;
	L.data[1]=1;
	L.data[2]=2;
	L.data[3]=2;
	L.data[4]=3;	
	L.data[5]=3;
	L.data[6]=4;
	L.data[7]=5;
	L.data[8]=6;
	L.data[9]=6;
	//1 2 9 10	
 	L.length=10;
 //	printList(L);
 	DeleteRepeatElem(L);
 	printList(L);
	return 0;
}
